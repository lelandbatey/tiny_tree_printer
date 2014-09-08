generate:
	python c_white_reducer.py > tiny_tree_printer.c

run: generate
	cc tiny_tree_printer.c -o ttp ; ./ttp

all: generate