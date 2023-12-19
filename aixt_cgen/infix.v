// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: infix.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation for 'infix' expressions (binary operations).
module aixt_cgen

import v.ast

fn (mut gen Gen) infix_expr(node ast.InfixExpr) string {
	lvar_type := gen.idents['${gen.current_fn}.${node.left.str()}'].typ
	rvar_type := gen.idents['${gen.current_fn}.${node.right.str()}'].typ
	if lvar_type == ast.string_type_idx || rvar_type == ast.string_type_idx {
		match node.op.str() {
			'==' {
				if !gen.includes.contains('strings/comp.c') {
					api_path := '${gen.base_path}/ports/${gen.setup.value('path').string()}/api'
					gen.includes += '#include "${api_path}/strings/comp.c"\n'
				}
				return '__string_comp(${gen.ast_node(node.left)}, ${gen.ast_node(node.right)})'
			} 
			'+' {
				if !gen.includes.contains('strings/add.c') {
					api_path := '${gen.base_path}/ports/${gen.setup.value('path').string()}/api'
					gen.includes += '#include "${api_path}/strings/add.c"\n'
				}
				return '__string_add(${gen.ast_node(node.left)}, ${gen.ast_node(node.right)})'
			}	
			else {
				panic('\n\nTranspiler Error:\n"${node.op.str()}" operator not supported for strings.\n')
			}
		}
	} else {
		return '${gen.ast_node(node.left)} ${node.op} ${gen.ast_node(node.right)}'
	}
}