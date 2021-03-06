#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "str.h"
#include "ctinfo.h"

// Returns the symboltableentry which is searched for
node *getSymboltableEntry(char *name, bool isfunction, node *symboltable) {
    node *entry = SYMBOLTABLE_HEAD(symboltable);

    while(entry) {
        while(entry) {
        char *entryname = SYMBOLTABLEENTRY_NAME(entry);
        if(STReq(name, entryname) && SYMBOLTABLEENTRY_FUNCTION(entry) == isfunction) {
            return entry;
        }
        entry = SYMBOLTABLEENTRY_NEXT(entry);
        }
        symboltable = SYMBOLTABLE_PARENT(symboltable);
        if(symboltable) {
            entry = SYMBOLTABLE_HEAD(symboltable);
        }
    }
    CTIerror("codeanalysis_helper: getSymbolableEntry: entry not present in symboltable");
    return NULL;
}

char *getTypeChar(basictype type) {
    switch (type) {
    case BT_bool:
      return "boolean ";
    case BT_int:
      return "int ";
    case BT_float:
      return "float ";
    case RT_void:
      return "void ";
    case BT_unknown:
      CTIerror("codeanalysis_helper: getTypeChar: Unknown Type");
  }
  return " ";
}

// Returns the type belonging to the expression
basictype getExpressionType(node *expr, node *symboltable) {
    node *entry;
    switch(NODE_TYPE(expr)) {
        case N_binop:
            return BINOP_EXPRESSIONTYPE(expr);
        case N_monop:
            return MONOP_EXPRESSIONTYPE(expr);
        case N_cast:
            return CAST_CASTTYPE(expr);
        case N_funcall:
            entry = getSymboltableEntry(FUNCALL_ID(expr), TRUE, symboltable);
            return SYMBOLTABLEENTRY_TYPE(entry);
        case N_var:
            entry = getSymboltableEntry(VAR_NAME(expr), FALSE, symboltable);
            return SYMBOLTABLEENTRY_TYPE(entry);
        case N_num:
            return BT_int;
        case N_float:
            return BT_float;
        case N_bool:
            return BT_bool;
        case N_condexpr:
            return getExpressionType(CONDEXPR_THEN(expr), symboltable);
        default:
            CTIerror("codeanalysis_helper: getExpressionType: undefined node");
            return BT_unknown;   
    }
}

// Return the category of the binary operator
binopcat getBinopCat(binop op) {
    switch (op) {
    case BO_add:
      return BC_arith;
    case BO_sub:
      return BC_arith;
    case BO_mul:
      return BC_arith;
    case BO_div:
      return BC_arith;
    case BO_mod:
      return BC_arith;
    case BO_lt:
      return BC_rel;
    case BO_le:
      return BC_rel;
    case BO_gt:
      return BC_rel;
    case BO_ge:
      return BC_rel;
    case BO_eq:
      return BC_rel;
    case BO_ne:
      return BC_rel;
    case BO_or:
      return BC_logic;
    case BO_and:
      return BC_logic;
    default:
        CTIerror("codeanalysis_helper: getBinopCat: Unknown BinOp");
        return BC_unknown;
    }
}