
/**
 * @file print.h
 *
 * Functions to print node structures
 *
 */

#ifndef _SAC_PRT_NODE_H_
#define _SAC_PRT_NODE_H_

#include "types.h"

// TODO print statements:
extern node *PRTprogram(node * arg_node, info * arg_info);
extern node *PRTdeclarations(node * arg_node, info * arg_info);
extern node *PRTfundefdec(node * arg_node, info * arg_info);
extern node *PRTfunbody(node * arg_node, info * arg_info);
extern node *PRTvardec(node * arg_node, info * arg_info);
extern node *PRTlocalfundefs(node * arg_node, info * arg_info);
extern node *PRTglobaldec(node * arg_node, info * arg_info);
extern node *PRTglobaldef(node * arg_node, info * arg_info);
extern node *PRTparam(node * arg_node, info * arg_info);
extern node *PRTvar(node * arg_node, info * arg_info);
extern node *PRTstatements(node * arg_node, info * arg_info);
extern node *PRTassign(node * arg_node, info * arg_info);
extern node *PRTfuncall(node * arg_node, info * arg_info);
extern node *PRTif(node * arg_node, info * arg_info);
extern node *PRTwhile(node * arg_node, info * arg_info);
extern node *PRTdowhile(node * arg_node, info * arg_info);
extern node *PRTfor(node * arg_node, info * arg_info);
extern node *PRTreturn(node * arg_node, info * arg_info);
extern node *PRTexprs(node * arg_node, info * arg_info);
extern node *PRTbinop(node * arg_node, info * arg_info);
extern node *PRTmonop(node * arg_node, info * arg_info);
extern node *PRTcondexpr(node *arg_node, info *arg_info);
extern node *PRTcast(node * arg_node, info * arg_info);
extern node *PRTnum(node * arg_node, info * arg_info);
extern node *PRTfloat(node * arg_node, info * arg_info);
extern node *PRTbool(node * arg_node, info * arg_info);
extern node *PRTsymboltable(node * arg_node, info * arg_info);
extern node *PRTsymboltableentry (node * arg_node, info * arg_info);
extern node *PRTstefuntype(node * arg_node, info * arg_info);

// Done
extern node *PRTerror (node * arg_node, info * arg_info);
extern node *PRTdoPrint( node *syntaxtree);

#endif /* _SAC_PRT_NODE_H_ */
