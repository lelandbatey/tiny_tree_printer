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
		'>',
		'if',
		'&',
		'+',
		'*',
		'/',
		'%',
		'?',
		':'
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
	repMap = [
		('int',         'a'),
		('repeat_char', 'b'),
		('item',        'c'),
		('len',         'd'),
		('output_row',  'e'),
		('padding',     'f'),
		('height',      'f'),
		('symbol',      'g'),
		('width',       'h'),
		('count',       'i'),
		('character',   'i'),
		('output_tree', 'j'),
		('char_arr',    'k'),
		('item',        'l'),
		('argc',        'm'),
		('argv',        'n'),
		('char_buf',    'o'),
		("'|'",       '124'),
		("'O'",        '79'),
		("'='",        '61'),
		("' '",        '32'),
		("'\\n'",      '10')
	]
	for big, small in repMap:
		instr = instr.replace(big, small)
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
def strip_defines(instr):
	outStr = ""
	for line in instr.split('\n'):
	    if not line.startswith('#define'):
		    outStr+= line.split('//')[0] + '\n'

	return outStr


def preserve_meta(instr):
	lines = iter(instr.split('\n'))

	pres = next(lines)
	outStr = ''.join(lines)

	outStr = fname_replace(outStr)
	return pres + outStr

with open('tree_print.c','r') as f:
	contents = f.read()
	contents = strip_comments(contents)
	contents = strip_defines(contents)
	contents = remove_indentation(contents)
	contents = remove_inner_spaces(contents)
	contents = preserve_meta(contents)
	contents = contents.strip()

	print(contents, end="")
