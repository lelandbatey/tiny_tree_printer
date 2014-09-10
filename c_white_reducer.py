#!/usr/bin/env python
from __future__ import print_function
import sys
import re

def strip_comments(instr):
	outStr = ""
	for line in instr.split('\n'):
		outStr+= line.split('//')[0] + '\n'

	return outStr

def remove_indentation(instr):	
	outStr = '\n'.join([ line.strip() for line in instr.split('\n') ])
	return outStr

def remove_newlines(instr):
	outStr = ""
	for x in instr.split('\n'):
		if x and x[0] == '#':
			outStr += x+'\n'
		else:
			outStr += x
	return outStr

def remove_inner_spaces(instr):
	opList = [
		';',
		',',
		'for',
		'=',
		'-',
		'<',
		'if',
		'&',
		'*',
		'<<',
		'>>',
		'/'
	]

	for op in opList:
		p = re.escape(op)
		find = r'(\s{}\s|{}\s|\s{})'.format(p,p,p)
		r = re.compile(find)

		instr = r.sub(op,instr)

	return instr

def printf_replace(instr):
	instr = instr.replace('printf','pc')
	# instr = instr.replace('node_num','nn')
	instr = instr.replace('"',"'")
	return instr

def fname_replace(instr):
	repDict = {
		'print_line' : 'pl',
		'print_tree' : 'ptr',
		'two_pow'    : 't',
		'seperator'  : 'r',
		'node_num'   : 'k',
		'node'       : 'n',
		'sbuff'      : 's',
		'height'     : 'h',
		'level'      : 'l',
		'len'        : 'l',
		'levSqrd'    : 'g',
		'nCount'     : 'd',
		'nodeCount'  : 'b',
		'step'       : 'm',
		'putchar'    : 'q',
		'sideBuffer' : 'w',
		'int '       : 'j ',
		'power'      : 'p',
		'item'       : 't',
		"'|'"        : '124',
		"'O'"        : '79',
		"'='"        : '61',
		"' '"        : '32',
		"'\\n'"      : '10',
		' else '     : 'else',
		' ? '        :'?',
		' : '        : ':',
		'argc'       :'c',
		'argv'       :'v'
	}
	for x in repDict:
		instr = instr.replace(x, repDict[x])
	return instr

def preserve_meta(instr):
	outStr = ''
	pres = ''

	for line in instr.split('\n'):
		if '#' not in line:
			outStr+= line+'\n'
		else:
			pres += line+'\n'

	outStr = fname_replace(outStr)
	outStr = pres+outStr
	return outStr


with open('tree_print.c','r') as f:
	contents = f.read()

	# print(remove_inner_spaces(contents))
	# exit()

	contents = strip_comments(contents)
	contents = remove_indentation(contents)
	contents = remove_newlines(contents)
	contents = remove_inner_spaces(contents)
	contents = printf_replace(contents)
	contents = preserve_meta(contents)
	contents = contents.strip()

	print(contents)