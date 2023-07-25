// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: const.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: code generation constant definitions.
module aixt_cgen

import v.ast

fn (mut gen Gen) const_field(node ast.ConstField) string {
	mut out := ''
	var_type := gen.setup.value(gen.table.type_kind(node.typ).str())			
	if node.expr.type_name() == 'v.ast.CastExpr' {	// in case of casting expression
		out += if var_type.string() == 'char []' {
			'const char ${node.name.after('.')}[] = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
		} else {
			'const ${var_type.string()} ${node.name.after('.')} = ${gen.ast_node((node.expr as ast.CastExpr).expr)};\n'
		}								
	} else {
		out += if var_type.string() == 'char []' {
			'const char ${node.name.after('.')}[] = ${gen.ast_node(node.expr)};\n'
		} else {
			'const ${var_type.string()} ${node.name.after('.')} = ${gen.ast_node(node.expr)};\n'
		}
	}
	return out
}