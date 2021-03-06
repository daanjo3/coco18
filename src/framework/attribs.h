
/**
 * @file attribs.h
 *
 * Defines the AttribUnion and attrib structures.
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * $Id: attribs.h.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

#ifndef _SAC_ATTRIBS_H_
#define _SAC_ATTRIBS_H_

#include "types.h"


/******************************************************************************
 * For each node a structure of its attributes is defined, named 
 * ATTRIBS_<nodename>
 *****************************************************************************/
struct ATTRIBS_N_ASSIGN
{
  char *Id;
};
struct ATTRIBS_N_BINOP
{
  binop Op;
  basictype ExpressionType;
};
struct ATTRIBS_N_BOOL
{
  bool Value;
};
struct ATTRIBS_N_CAST
{
  basictype CastType;
};
struct ATTRIBS_N_CONDEXPR
{
};
struct ATTRIBS_N_DECLARATIONS
{
};
struct ATTRIBS_N_DOWHILE
{
};
struct ATTRIBS_N_ERROR
{
  char *message;
  compiler_phase_t anyphase;
};
struct ATTRIBS_N_EXPRS
{
};
struct ATTRIBS_N_FLOAT
{
  float Value;
};
struct ATTRIBS_N_FOR
{
  char *Id;
};
struct ATTRIBS_N_FUNBODY
{
};
struct ATTRIBS_N_FUNCALL
{
  char *Id;
};
struct ATTRIBS_N_FUNDEFDEC
{
  bool Export;
  basictype RetType;
  char *Id;
};
struct ATTRIBS_N_GLOBALDEC
{
  basictype Type;
  char *Id;
};
struct ATTRIBS_N_GLOBALDEF
{
  basictype Type;
  bool Export;
  char *Id;
};
struct ATTRIBS_N_IF
{
};
struct ATTRIBS_N_LOCALFUNDEFS
{
};
struct ATTRIBS_N_MONOP
{
  monop Op;
  basictype ExpressionType;
};
struct ATTRIBS_N_NUM
{
  int Value;
};
struct ATTRIBS_N_PARAM
{
  basictype Type;
};
struct ATTRIBS_N_PROGRAM
{
};
struct ATTRIBS_N_RETURN
{
};
struct ATTRIBS_N_STATEMENTS
{
};
struct ATTRIBS_N_SYMBOLTABLE
{
  node *Parent;
};
struct ATTRIBS_N_SYMBOLTABLEENTRY
{
  char *Name;
  basictype Type;
  bool Function;
  node *Params;
};
struct ATTRIBS_N_VAR
{
  char *Name;
  node *Link;
};
struct ATTRIBS_N_VARDEC
{
  basictype Type;
  char *Id;
};
struct ATTRIBS_N_WHILE
{
};
/*****************************************************************************
 * This union handles all different types of attributes. Its members are
 * called N_nodename.
 ****************************************************************************/
struct ATTRIBUNION
{
  struct ATTRIBS_N_ASSIGN *N_assign;
  struct ATTRIBS_N_BINOP *N_binop;
  struct ATTRIBS_N_BOOL *N_bool;
  struct ATTRIBS_N_CAST *N_cast;
  struct ATTRIBS_N_CONDEXPR *N_condexpr;
  struct ATTRIBS_N_DECLARATIONS *N_declarations;
  struct ATTRIBS_N_DOWHILE *N_dowhile;
  struct ATTRIBS_N_ERROR *N_error;
  struct ATTRIBS_N_EXPRS *N_exprs;
  struct ATTRIBS_N_FLOAT *N_float;
  struct ATTRIBS_N_FOR *N_for;
  struct ATTRIBS_N_FUNBODY *N_funbody;
  struct ATTRIBS_N_FUNCALL *N_funcall;
  struct ATTRIBS_N_FUNDEFDEC *N_fundefdec;
  struct ATTRIBS_N_GLOBALDEC *N_globaldec;
  struct ATTRIBS_N_GLOBALDEF *N_globaldef;
  struct ATTRIBS_N_IF *N_if;
  struct ATTRIBS_N_LOCALFUNDEFS *N_localfundefs;
  struct ATTRIBS_N_MONOP *N_monop;
  struct ATTRIBS_N_NUM *N_num;
  struct ATTRIBS_N_PARAM *N_param;
  struct ATTRIBS_N_PROGRAM *N_program;
  struct ATTRIBS_N_RETURN *N_return;
  struct ATTRIBS_N_STATEMENTS *N_statements;
  struct ATTRIBS_N_SYMBOLTABLE *N_symboltable;
  struct ATTRIBS_N_SYMBOLTABLEENTRY *N_symboltableentry;
  struct ATTRIBS_N_VAR *N_var;
  struct ATTRIBS_N_VARDEC *N_vardec;
  struct ATTRIBS_N_WHILE *N_while;
};
#endif /* _SAC_ATTRIBS_H_ */
