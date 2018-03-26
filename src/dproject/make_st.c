#include "make_st.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "str.h"

#include "memory.h"
#include "ctinfo.h"
#include "lookup_table.h"

struct INFO {
    node *current_table;
};

#define INFO_CURRENT_TABLE(n) ((n)->current_table)

static info* MakeInfo(void) {
    info *result;
    DBUG_ENTER("MakeInfo");
    result = (info*)MEMmalloc(sizeof(info));
    INFO_CURRENT_TABLE(result) = TBmakeSymboltable(NULL);
    DBUG_RETURN(result);
}

static info* FreeInfo(info* info) {
    DBUG_ENTER("FreeInfo");
    info = MEMfree(info);
    DBUG_RETURN(info);
}

// Check whether an entry is already present in the table
bool checkEntry(info *arg_info, char* name, bool is_function) {
    node *table = INFO_CURRENT_TABLE(arg_info);
    node *entry = SYMBOLTABLE_HEAD(table);
    char* entry_name;
    bool entry_function;

    while (entry) {
        entry_name = SYMBOLTABLEENTRY_NAME(entry);
        entry_function = SYMBOLTABLEENTRY_FUNCTION(entry);

        if (STReq(name, entry_name) && (is_function == entry_function)) {
            return FALSE;
        }
        entry = SYMBOLTABLEENTRY_NEXT(entry);
    }
    return TRUE;
}


// Insert a new entry in the table
void insertEntry(info *arg_info, node *new_entry) {
    node *table = INFO_CURRENT_TABLE(arg_info);
    node *entry = SYMBOLTABLE_HEAD(table);

    if (!entry) {
        SYMBOLTABLE_HEAD(table) = new_entry;
    } else {
        while (SYMBOLTABLEENTRY_NEXT(entry)) {
            entry = SYMBOLTABLEENTRY_NEXT(entry);
        }
        SYMBOLTABLEENTRY_NEXT(entry) = new_entry;
    }
}

// Add an entry in the table
void addEntry(info *arg_info, char* name, basictype type, bool is_function, node *params) {
    if (!(checkEntry(arg_info, name, is_function))) {
        CTIerror("Syntax Error: Variable already declared");
        return;
    }
    node *new_entry = TBmakeSymboltableentry(name, type, is_function, NULL, params);
    insertEntry(arg_info, new_entry);
}

node *MSfundefdec(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSfundefdec");
    
    // Store the function in the current table
    char* name = FUNDEFDEC_ID(arg_node);
    basictype type = FUNDEFDEC_RETTYPE(arg_node);
    node *param = FUNDEFDEC_PARAM(arg_node);
    addEntry(arg_info, name, type, TRUE, param);

    info *body_info = MakeInfo();

    // Add the params to the block symbol table
    if (param) {
        do {
            name = PARAM_ID(param);
            type = PARAM_TYPE(param);
            addEntry(body_info, name, type, FALSE, NULL);
            param = PARAM_NEXT(param);
        } while (param);
    }

    // Traverse through the block
    if(FUNDEFDEC_BODY(arg_node)) {
        FUNDEFDEC_BODY(arg_node) = TRAVdo(FUNDEFDEC_BODY(arg_node), body_info);
    }

    // Make the current table the parent of the block symbol table
    node *body_table = INFO_CURRENT_TABLE(body_info);
    SYMBOLTABLE_PARENT(body_table) = INFO_CURRENT_TABLE(arg_info);

    body_info = FreeInfo(body_info);

    DBUG_RETURN(arg_node);
}

node *MSfor(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSfor");

    char* name = ID_NAME(FOR_ID(arg_node));
    // Create a new info struct with symbol table
    info *block_info = MakeInfo();

    // Add the parameters to the new symbol table
    addEntry(block_info, name, BT_int, FALSE, NULL);
    
    // Traverse over the block node to fill the symbol table
    FOR_BLOCK(arg_node) = TRAVdo(FOR_BLOCK(arg_node), block_info);

    // The block table's parent will be the current table
    node *block_table = INFO_CURRENT_TABLE(block_info);
    SYMBOLTABLE_PARENT(block_table) = INFO_CURRENT_TABLE(arg_info);
    
    // Free the block info struct
    block_info = FreeInfo(block_info);
    DBUG_RETURN(arg_node);
}

// Add a variable declaration
node *MSvardec(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSvardec");

    char* name = VARDEC_ID(arg_node);
    basictype type = VARDEC_TYPE(arg_node);
    addEntry(arg_info, name, type, FALSE, NULL);

    DBUG_RETURN(arg_node);
}

// Add a global definition
node *MSglobaldef(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSglobaldef");

    char* name = GLOBALDEF_ID(arg_node);
    basictype type = GLOBALDEF_TYPE(arg_node);
    addEntry(arg_info, name, type, FALSE, NULL);
    
    DBUG_RETURN(arg_node);
}

// Add a global declaration
node *MSglobaldec(node *arg_node, info *arg_info) {
    DBUG_ENTER("MSglobaldec");

    char* name = GLOBALDEC_ID(arg_node);
    basictype type = GLOBALDEC_TYPE(arg_node);
    addEntry(arg_info, name, type, FALSE, NULL);

    DBUG_RETURN(arg_node);
}

// Traversal entry point:

node *MSdoMakeSymbolTable(node *syntaxtree) {
    info *arg_info;
    DBUG_ENTER("MSdoScopeResolution");
    arg_info = MakeInfo();

    TRAVpush(TR_ms);
    syntaxtree = TRAVdo(syntaxtree, arg_info);
    TRAVpop();

    arg_info = FreeInfo(arg_info);
    DBUG_RETURN(syntaxtree);
}