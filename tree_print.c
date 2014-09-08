#define j int

// Uses bit-shifting to get powers of two.
int two_pow(int power){
	return 1<<power;
}

// Printing to stdout without stdio or putchar
// Originally taken from here:
// http://stackoverflow.com/a/14296280
void pc(char item, int len){
	for (; 0 < len; --len){
		write(1, &item, 1);
	}
}

// Prints a line with nodes on it.
void print_line(int sbuff, int seperator, int node_num, int node){

	// Print the left-hand buffers
	pc(' ',sbuff-1);
	for (; 0 < node_num; --node_num){
		// Print the nodes (circles)
		pc(node,1);

		// Don't print spacers on last node
		0<node_num ? pc(' ', seperator) : 0;
	}

	pc(' ',sbuff);
	pc('\n',1);
}


void print_tree(int height){
	int step, i;
	for (step = 0; step < height; ++step){
		int level = height - step - 1;
		
		int sideBuffer = two_pow(level);
		int seperator = two_pow(level+1);

		// Creates the arrays with the nodes and columns
		int node_num = two_pow(step);

		if (step){

			// Prints the "spanning" bars that connect nodes
			pc(' ',sideBuffer-1);
			for (i = 0; i < node_num; ++i){
				// Determines whether to print a bar or empty space
				i%2 ? pc(' ', seperator-1) : pc('=', seperator+1);
			}

			pc(' ',sideBuffer);
			pc('\n',1);
			print_line(sideBuffer, seperator-1, node_num, '|');
		}
		print_line(sideBuffer, seperator-1, node_num, 'O');
	}
}


int main(int argc, char const *argv[]){

	// Assume that any second argument will be a number
	int height=5;
	argc>1 ? height = atoi(argv[1]) : 0;
	

	// Prints out the text of the poem
	//
	// 4 ascii chars are packed into each integer, then using bit shifting and
	// bitwise-and, those characters and printed one at a time.
	int x[25] = {
		285563184,
		1494092560,
		85463301,
		106508377,
		218961937,
		51645273,
		106497812,
		946803732,
		403116633,
		207163657,
		1494484746,
		335743501,
		89718797,
		1493899281,
		117791000,
		1867191316,
		1499027801,
		1499027801,
		1499027801,
		1499027801,
		660163660,
		403707160,
		118761817,
		186125325,
		1868126553
	};
	int i,n;
	for (i = 0; i < 25; ++i){
		for (n = 0; n < 4; ++n){
			pc(121 - (0x7F & x[i] >> 8 * n), 1);
		};
	};
	print_tree(height);
	return 0;
}
