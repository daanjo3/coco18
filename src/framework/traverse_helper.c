
/**
 * @file traverse_helper.c
 *
 * Defines the helper function needed by the traversal system
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * $Id: traverse_helper.c.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */


#include "traverse_helper.h"
#include "dbug.h"
#include "tree_basic.h"
#include "traverse.h"

#define TRAV( son, info)    if (son != NULL) { son = TRAVdo( son, info); }

node *
TRAVnone (node * arg_node, info * arg_info)
{
  return (arg_node);
}

node *
TRAVerror (node * arg_node, info * arg_info)
{
  DBUG_ASSERT ((FALSE), "Illegal node type found.");

  return (arg_node);
}

node *
TRAVsons (node * arg_node, info * arg_info)
{
  switch (NODE_TYPE (arg_node))
    {
    case N_program:
      TRAV (PROGRAM_DECLARATIONS (arg_node), arg_info);
      TRAV (PROGRAM_SYMBOLTABLE (arg_node), arg_info);
      break;
    case N_declarations:
      TRAV (DECLARATIONS_DECLARATION (arg_node), arg_info);
      TRAV (DECLARATIONS_NEXT (arg_node), arg_info);
      break;
    case N_fundefdec:
      TRAV (FUNDEFDEC_PARAM (arg_node), arg_info);
      TRAV (FUNDEFDEC_BODY (arg_node), arg_info);
      TRAV (FUNDEFDEC_SYMBOLTABLE (arg_node), arg_info);
      break;
    case N_funbody:
      TRAV (FUNBODY_VARDEC (arg_node), arg_info);
      TRAV (FUNBODY_LOCALFUNDEFS (arg_node), arg_info);
      TRAV (FUNBODY_STATEMENTS (arg_node), arg_info);
      break;
    case N_vardec:
      TRAV (VARDEC_EXPR (arg_node), arg_info);
      TRAV (VARDEC_NEXT (arg_node), arg_info);
      break;
    case N_localfundefs:
      TRAV (LOCALFUNDEFS_FIRST (arg_node), arg_info);
      TRAV (LOCALFUNDEFS_NEXT (arg_node), arg_info);
      break;
    case N_globaldec:
      break;
    case N_globaldef:
      TRAV (GLOBALDEF_EXPR (arg_node), arg_info);
      break;
    case N_param:
      TRAV (PARAM_NEXT (arg_node), arg_info);
      break;
    case N_var:
      break;
    case N_statements:
      TRAV (STATEMENTS_FIRST (arg_node), arg_info);
      TRAV (STATEMENTS_NEXT (arg_node), arg_info);
      break;
    case N_assign:
      TRAV (ASSIGN_VAR (arg_node), arg_info);
      TRAV (ASSIGN_EXPR (arg_node), arg_info);
      break;
    case N_funcall:
      TRAV (FUNCALL_VAR (arg_node), arg_info);
      TRAV (FUNCALL_EXPRS (arg_node), arg_info);
      break;
    case N_if:
      TRAV (IF_EXPR (arg_node), arg_info);
      TRAV (IF_BLOCK (arg_node), arg_info);
      TRAV (IF_ELSEBLOCK (arg_node), arg_info);
      break;
    case N_while:
      TRAV (WHILE_EXPR (arg_node), arg_info);
      TRAV (WHILE_BLOCK (arg_node), arg_info);
      break;
    case N_dowhile:
      TRAV (DOWHILE_EXPR (arg_node), arg_info);
      TRAV (DOWHILE_BLOCK (arg_node), arg_info);
      break;
    case N_for:
      TRAV (FOR_VAR (arg_node), arg_info);
      TRAV (FOR_EXPRSTART (arg_node), arg_info);
      TRAV (FOR_EXPRSTOP (arg_node), arg_info);
      TRAV (FOR_EXPRINCR (arg_node), arg_info);
      TRAV (FOR_BLOCK (arg_node), arg_info);
      break;
    case N_return:
      TRAV (RETURN_EXPR (arg_node), arg_info);
      break;
    case N_exprs:
      TRAV (EXPRS_FIRST (arg_node), arg_info);
      TRAV (EXPRS_NEXT (arg_node), arg_info);
      break;
    case N_binop:
      TRAV (BINOP_LEFT (arg_node), arg_info);
      TRAV (BINOP_RIGHT (arg_node), arg_info);
      break;
    case N_monop:
      TRAV (MONOP_EXPR (arg_node), arg_info);
      break;
    case N_cast:
      TRAV (CAST_EXPR (arg_node), arg_info);
      break;
    case N_num:
      break;
    case N_float:
      break;
    case N_bool:
      break;
    case N_symboltable:
      TRAV (SYMBOLTABLE_HEAD (arg_node), arg_info);
      break;
    case N_symboltableentry:
      TRAV (SYMBOLTABLEENTRY_NEXT (arg_node), arg_info);
      break;
    case N_error:
      TRAV (ERROR_NEXT (arg_node), arg_info);
      break;
    default:
      DBUG_ASSERT ((FALSE), "Illegal nodetype found!");
      break;
    }

  return (arg_node);
}

int
TRAVnumSons (node * node)
{
  int result = 0;

  DBUG_ENTER ("TRAVnumSons");

  switch (NODE_TYPE (node))
    {
    case N_program:
      result = 2;
      break;
    case N_declarations:
      result = 2;
      break;
    case N_fundefdec:
      result = 3;
      break;
    case N_funbody:
      result = 3;
      break;
    case N_vardec:
      result = 2;
      break;
    case N_localfundefs:
      result = 2;
      break;
    case N_globaldec:
      result = 0;
      break;
    case N_globaldef:
      result = 1;
      break;
    case N_param:
      result = 1;
      break;
    case N_var:
      result = 0;
      break;
    case N_statements:
      result = 2;
      break;
    case N_assign:
      result = 2;
      break;
    case N_funcall:
      result = 2;
      break;
    case N_if:
      result = 3;
      break;
    case N_while:
      result = 2;
      break;
    case N_dowhile:
      result = 2;
      break;
    case N_for:
      result = 5;
      break;
    case N_return:
      result = 1;
      break;
    case N_exprs:
      result = 2;
      break;
    case N_binop:
      result = 2;
      break;
    case N_monop:
      result = 1;
      break;
    case N_cast:
      result = 1;
      break;
    case N_num:
      result = 0;
      break;
    case N_float:
      result = 0;
      break;
    case N_bool:
      result = 0;
      break;
    case N_symboltable:
      result = 1;
      break;
    case N_symboltableentry:
      result = 1;
      break;
    case N_error:
      result = 1;
      break;
    default:
      DBUG_ASSERT ((FALSE), "Illegal nodetype found!");
      break;
    }

  DBUG_RETURN (result);
}

node *
TRAVgetSon (int no, node * parent)
{
  node *result = NULL;

  DBUG_ENTER ("TRAVgetSon");

  switch (NODE_TYPE (parent))
    {
    case N_program:
      switch (no)
	{
	case 0:
	  result = PROGRAM_DECLARATIONS (parent);
	  break;
	case 1:
	  result = PROGRAM_SYMBOLTABLE (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_declarations:
      switch (no)
	{
	case 0:
	  result = DECLARATIONS_DECLARATION (parent);
	  break;
	case 1:
	  result = DECLARATIONS_NEXT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_fundefdec:
      switch (no)
	{
	case 0:
	  result = FUNDEFDEC_PARAM (parent);
	  break;
	case 1:
	  result = FUNDEFDEC_BODY (parent);
	  break;
	case 2:
	  result = FUNDEFDEC_SYMBOLTABLE (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_funbody:
      switch (no)
	{
	case 0:
	  result = FUNBODY_VARDEC (parent);
	  break;
	case 1:
	  result = FUNBODY_LOCALFUNDEFS (parent);
	  break;
	case 2:
	  result = FUNBODY_STATEMENTS (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_vardec:
      switch (no)
	{
	case 0:
	  result = VARDEC_EXPR (parent);
	  break;
	case 1:
	  result = VARDEC_NEXT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_localfundefs:
      switch (no)
	{
	case 0:
	  result = LOCALFUNDEFS_FIRST (parent);
	  break;
	case 1:
	  result = LOCALFUNDEFS_NEXT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_globaldec:
      switch (no)
	{
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_globaldef:
      switch (no)
	{
	case 0:
	  result = GLOBALDEF_EXPR (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_param:
      switch (no)
	{
	case 0:
	  result = PARAM_NEXT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_var:
      switch (no)
	{
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_statements:
      switch (no)
	{
	case 0:
	  result = STATEMENTS_FIRST (parent);
	  break;
	case 1:
	  result = STATEMENTS_NEXT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_assign:
      switch (no)
	{
	case 0:
	  result = ASSIGN_VAR (parent);
	  break;
	case 1:
	  result = ASSIGN_EXPR (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_funcall:
      switch (no)
	{
	case 0:
	  result = FUNCALL_VAR (parent);
	  break;
	case 1:
	  result = FUNCALL_EXPRS (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_if:
      switch (no)
	{
	case 0:
	  result = IF_EXPR (parent);
	  break;
	case 1:
	  result = IF_BLOCK (parent);
	  break;
	case 2:
	  result = IF_ELSEBLOCK (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_while:
      switch (no)
	{
	case 0:
	  result = WHILE_EXPR (parent);
	  break;
	case 1:
	  result = WHILE_BLOCK (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_dowhile:
      switch (no)
	{
	case 0:
	  result = DOWHILE_EXPR (parent);
	  break;
	case 1:
	  result = DOWHILE_BLOCK (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_for:
      switch (no)
	{
	case 0:
	  result = FOR_VAR (parent);
	  break;
	case 1:
	  result = FOR_EXPRSTART (parent);
	  break;
	case 2:
	  result = FOR_EXPRSTOP (parent);
	  break;
	case 3:
	  result = FOR_EXPRINCR (parent);
	  break;
	case 4:
	  result = FOR_BLOCK (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_return:
      switch (no)
	{
	case 0:
	  result = RETURN_EXPR (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_exprs:
      switch (no)
	{
	case 0:
	  result = EXPRS_FIRST (parent);
	  break;
	case 1:
	  result = EXPRS_NEXT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_binop:
      switch (no)
	{
	case 0:
	  result = BINOP_LEFT (parent);
	  break;
	case 1:
	  result = BINOP_RIGHT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_monop:
      switch (no)
	{
	case 0:
	  result = MONOP_EXPR (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_cast:
      switch (no)
	{
	case 0:
	  result = CAST_EXPR (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_num:
      switch (no)
	{
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_float:
      switch (no)
	{
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_bool:
      switch (no)
	{
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_symboltable:
      switch (no)
	{
	case 0:
	  result = SYMBOLTABLE_HEAD (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_symboltableentry:
      switch (no)
	{
	case 0:
	  result = SYMBOLTABLEENTRY_NEXT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_error:
      switch (no)
	{
	case 0:
	  result = ERROR_NEXT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    default:
      DBUG_ASSERT ((FALSE), "Illegal nodetype found!");
      break;
    }

  DBUG_RETURN (result);
}
