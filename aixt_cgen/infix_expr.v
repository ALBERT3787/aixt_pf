// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: infix_expr.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: code generation for 'infix' expressions (binary operations).
module aixt_cgen

import v.ast

fn (mut gen Gen) infix_expr(node ast.InfixExpr) string {
	if node.left_type == ast.string_type_idx || node.right_type == ast.string_type_idx {
		match node.op.str() {
			'==' {
				gen.add_include('string.h')
				return '!strcmp(${gen.ast_node(node.left)}, ${gen.ast_node(node.right)})'
			} 
			'!=' {
				gen.add_include('string.h')
				return 'strcmp(${gen.ast_node(node.left)}, ${gen.ast_node(node.right)})'
			} 
			'+' {
				gen.add_include('string.h')
				gen.add_definition('char __temp_str[${gen.setup.value('string_default_len').int()}];')
				return 'strcat(strcpy(__temp_str, ${gen.ast_node(node.left)}), ${gen.ast_node(node.right)})'
			} 
			else {
				return ''
			}
		}
	} else {
		return '${gen.ast_node(node.left)} ${node.op} ${gen.ast_node(node.right)}'
	}
	return ''
}