
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
};
struct ATTRIBS_N_BINOP
{
  binop Op;
};
struct ATTRIBS_N_BOOL
{
  bool Value;
};
struct ATTRIBS_N_CAST
{
  basictype CastType;
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
};
struct ATTRIBS_N_FUNBODY
{
};
struct ATTRIBS_N_FUNCALL
{
};
struct ATTRIBS_N_FUNDEC
{
};
struct ATTRIBS_N_FUNDEF
{
  bool Export;
};
struct ATTRIBS_N_FUNHEADER
{
  RetType;
};
struct ATTRIBS_N_GLOBALDEC
{
  basictype Type;
};
struct ATTRIBS_N_GLOBALDEF
{
  basictype Type;
  bool Export;
};
struct ATTRIBS_N_ID
{
  char *Name;
};
struct ATTRIBS_N_IF
{
};
struct ATTRIBS_N_LOCALFUNDEF
{
};
struct ATTRIBS_N_LOCALFUNDEFS
{
};
struct ATTRIBS_N_MONOP
{
  Op;
};
struct ATTRIBS_N_NUM
{
  int Value;
};
struct ATTRIBS_N_PARAM
{
  basictype Type;
};
struct ATTRIBS_N_PARAMS
{
};
struct ATTRIBS_N_RETURN
{
};
struct ATTRIBS_N_STMTS
{
};
struct ATTRIBS_N_VARDEC
{
  basictype Type;
};
struct ATTRIBS_N_VARDECS
{
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
  struct ATTRIBS_N_DECLARATIONS *N_declarations;
  struct ATTRIBS_N_DOWHILE *N_dowhile;
  struct ATTRIBS_N_ERROR *N_error;
  struct ATTRIBS_N_EXPRS *N_exprs;
  struct ATTRIBS_N_FLOAT *N_float;
  struct ATTRIBS_N_FOR *N_for;
  struct ATTRIBS_N_FUNBODY *N_funbody;
  struct ATTRIBS_N_FUNCALL *N_funcall;
  struct ATTRIBS_N_FUNDEC *N_fundec;
  struct ATTRIBS_N_FUNDEF *N_fundef;
  struct ATTRIBS_N_FUNHEADER *N_funheader;
  struct ATTRIBS_N_GLOBALDEC *N_globaldec;
  struct ATTRIBS_N_GLOBALDEF *N_globaldef;
  struct ATTRIBS_N_ID *N_id;
  struct ATTRIBS_N_IF *N_if;
  struct ATTRIBS_N_LOCALFUNDEF *N_localfundef;
  struct ATTRIBS_N_LOCALFUNDEFS *N_localfundefs;
  struct ATTRIBS_N_MONOP *N_monop;
  struct ATTRIBS_N_NUM *N_num;
  struct ATTRIBS_N_PARAM *N_param;
  struct ATTRIBS_N_PARAMS *N_params;
  struct ATTRIBS_N_RETURN *N_return;
  struct ATTRIBS_N_STMTS *N_stmts;
  struct ATTRIBS_N_VARDEC *N_vardec;
  struct ATTRIBS_N_VARDECS *N_vardecs;
  struct ATTRIBS_N_WHILE *N_while;
};
#endif /* _SAC_ATTRIBS_H_ */
