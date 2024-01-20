// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// File Name: cgen.v
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This file contains the C code generation fucntions of the Aixt project.

module aixt_cgen

import v.ast
// import v.token
import v.pref
import v.parser
import v.checker
import toml

pub struct Gen {
mut:	
	file  			&ast.File  = unsafe { nil }
	table 			&ast.Table = unsafe { nil }
	transpiler_path string
	out   			string
	includes		string
	definitions		string
	current_fn		string
	main_loop_cmds	string
	cond_assign		bool
	// temps_cont	int
	level_cont		int
	// idents			[]ast.Ident
	idents			map[string] struct {
	mut:
		kind    	ast.IdentKind	
		typ			ast.Type
		// is_busy		bool
		elem_type	ast.Type
		len			int
	}
	type_names		[]string
pub mut:
	pref  			&pref.Preferences = unsafe { nil }
	setup 			toml.Doc
}

pub fn (mut gen Gen) gen(source_path string) string {
	// gen.temps_cont = 0
	gen.level_cont = 0
	gen.definitions = ''
	gen.includes = ''
	// gen.pref.is_script = true
	gen.file = parser.parse_file(source_path, gen.table, .skip_comments, gen.pref)
	// println('${'='.repeat(50)}\n${gen.file}${'='.repeat(50)}\n')
	mut checker_ := checker.new_checker(gen.table, gen.pref)
	checker_.check(mut gen.file)
	// gen.table.cur_fn.scope.children[0].objets['_i'] = 0
	// println('${gen.table.cur_fn.scope.children[0]}')
	// println('a' in gen.table.cur_fn.scope.children[0].objects)
	println(gen.table.type_symbols)
	println('\n\n===== Top-down node analysis =====\n')
	gen.out = gen.ast_node(gen.file) // starts from the main node (file)
	println('\n\n===== Symbol table =====\n')
	print('${gen.symbol_table(gen.table.global_scope)}')
	println('${gen.symbol_table(gen.file.scope.children[0])}')
	gen.out_format()
	// println(gen.file.used_fns)
	return gen.out
}

fn (mut gen Gen) ast_node(node ast.Node) string {
	print('${node.type_name().after('v.ast.')} -> ')
	match node {
		ast.File {
			return gen.ast_file(node)
		}
		ast.Stmt {
			return gen.stmt(node)
		}
		ast.Expr {
			return gen.expr(node)
		}
		ast.ConstField {
			return gen.const_field(node)
		}
		ast.GlobalField {
			return gen.global_field(node)
		}
		ast.EnumField {
			return gen.enum_field(node)
		}
		ast.IfBranch { // statement block of "if" and "else" expressions
			return gen.if_branch(node)
		}
		ast.CallArg {
			return gen.call_arg(node)
		}
		ast.Param {
			return gen.param(node)
		}
		else {
			return ''
		} //'Error: Not defined node.\n' }
	}
}

fn (mut gen Gen) kind_and_type(object ast.ScopeObject) string {
	return match object {
		ast.ConstField {
			'Constant -- ${gen.table.type_symbols[object.expr.get_pure_type()].str().replace('&', '')}'
		}
		ast.GlobalField {
			'Global -- ${gen.table.type_symbols[object.typ].str().replace('&', '')}'
		}
		ast.Var {
			'Variable -- ${gen.table.type_symbols[object.typ].str().replace('&', '')}'
		}
		else {
			'Asm Reg  -- ${gen.table.type_symbols[object.typ].str().replace('&', '')}'
		}
	}
}

fn (mut gen Gen) symbol_table(scope ast.Scope) string {
	mut msg := ''
	for key, val in scope.objects {
		msg += '${key} -- ${gen.kind_and_type(val)}\n'
	}
	return msg
}

fn (mut gen Gen) out_format() {
	gen.out = gen.out.replace('___includes_block___', gen.includes)
	gen.out = gen.out.replace('___definitions_block___', gen.definitions)
	gen.out = gen.out.replace('\n\n\n;', '\n')
	gen.out = gen.out.replace('\n\n;', '\n---')
	gen.out = gen.out.replace('}\n;', '}')
	mut temp := ''
	mut ind_count := 0
	for c in gen.out {
		match rune(c) {
			`\n` {
				temp += '\n' + '\t'.repeat(ind_count)
			}
			`{` {
				ind_count++
				temp += rune(c).str()
			}
			`}` {
				ind_count--
				temp += rune(c).str()
			}
			else {
				temp += rune(c).str()
			}
		}
	}
	temp = temp.replace('\t}', '}')
	gen.out = temp + '\n'
}