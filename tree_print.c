#include <stdio.h>
#include <math.h>

// Prints a line with nodes on it.
void print_line(int sbuff, int seperator, int node_num, char node){
	int i = 0;
	for (i = 0; i < sbuff-1; ++i){
		printf(" ");
	}

	for (i = 0; i < node_num; ++i){
		printf("%c", node);
		// Don't print spacers on last node
		if (i < node_num){
			int x;
			for (x = 0; x < seperator; ++x){
				printf(" ");
			}
		}
	}

	for (i = 0; i < sbuff; ++i){
		printf(" ");
	}
	printf("\n");
}


void print_tree(int height){
	int step, i, x;
	for (step = 0; step < height; ++step){
		int level =  height - step - 1;

		int levSqrd = (int)pow(2.0, (double)level);

		int sideBuffer = levSqrd;
		int seperator = (int)pow(2.0,(double)level+1);

		// Creates the arrays with the nodes and columns
		int nodeCount = (int)pow(2.0, (double)step);

		if (step){
			// Prints the "spanning" bars that connect nodes
			for (i = 0; i < sideBuffer-1; ++i){
				printf(" ");
			}

			for (i = 0; i < nodeCount; ++i){
				// Determines whether to print a bar or empty space
				if (i%2){
					for (x = 0; x < seperator-1; ++x){
						printf(" ");
					}
				} else {
					for (x = 0; x < seperator+1; ++x){
						printf("=");
					}
				}
			}

			for (i = 0; i < sideBuffer; ++i){
				printf(" ");
			}
			printf("\n");
			print_line(sideBuffer, seperator-1, nodeCount, '|');
		}
		print_line(sideBuffer, seperator-1, nodeCount, 'O');
	}
}


int main(int argc, char const *argv[]){
	// Assume that any second argument will be a number
	int height=5;
	if (argc>1){
		height = atoi(argv[1]);
	}

	int x[25][2] = {
		{201348139, 116},
		{1308819461, 110},
		{1248256, 116},
		{5450323, 115},
		{2820, 108},
		{1116246, 118},
		{5439758, 115},
		{609943552, 101},
		{285215570, 114},
		{55576576, 112},
		{1376583683, 114},
		{285214474, 118},
		{89718797, 121},
		{1308626182, 110},
		{33575955, 116},
		{1530331136, 101},
		{0, 32},
		{0, 32},
		{0, 32},
		{0, 32},
		{3286309, 82},
		{134219016, 105},
		{860754, 114},
		{852226, 110},
		{370540544, 32}
	};
	int i,n;
	for (i = 0; i < 25; ++i) {
		for (n = 0; n < 4; ++n) {
			putchar(x[i][1] - (0x7F & x[i][0] >> 8 * n));
		};
	};
	print_tree(height);
	return 0;
}
