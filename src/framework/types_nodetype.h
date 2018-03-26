
/**
 * @file types_nodetype.h
 *
 * This file defines the nodetype node enumeration.
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * $Id: types_nodetype.h.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

#ifndef _SAC_TYPES_NODETYPE_H_
#define _SAC_TYPES_NODETYPE_H_

#define MAX_NODES 27
typedef enum
{ N_undefined = 0, N_declarations = 1, N_fundefdec = 2, N_funbody =
    3, N_vardec = 4, N_localfundefs = 5, N_globaldec = 6, N_globaldef =
    7, N_param = 8, N_id = 9, N_stmts = 10, N_assign = 11, N_funcall =
    12, N_if = 13, N_while = 14, N_dowhile = 15, N_for = 16, N_return =
    17, N_exprs = 18, N_binop = 19, N_monop = 20, N_cast = 21, N_num =
    22, N_float = 23, N_bool = 24, N_symboltable = 25, N_symboltableentry =
    26, N_error = 27 } nodetype;

#endif /* _SAC_TYPES_NODETYPE_H_ */
