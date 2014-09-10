typedef int a;

int *char_buf, item, padding, count;
#define height padding  // Reuse variables to reduce declarations
#define character count

void repeat_char(int character, int len){
	for (; len; --len)
		putchar(character);
}

void output_row(int symbol, int width){
	for (item = count; item; --item)
		repeat_char(' ', padding - 1), // Perform all function calls in one
		repeat_char(symbol, width),    // statement to avoid braces
		repeat_char(' ', padding);
	repeat_char('\n', 1);
}

int main(int argc, char **argv){
	// Prints out the text of the poem
	//
	// 5 chars are packed into each integer
	int char_arr[] = {
		54127955,
		50101071,
		9182450,
		70452164,
		34408657,
		32560195,
		101748287,
		74449970,
		69134752,
		139471456,
		79869169,
		103184737,
		10612518,
		5421361,
		5421361,
		5421361,
		15487389,
		223069157,
		12195990,
		2271,
		0
	};
	for (char_buf = char_arr; character = *char_buf; ++char_buf)
		for (; item = character % 48; character /= 48)
			repeat_char(item < 2 ? ' ' : item < 27 ? item + 95 : item < 45 ?
					item + 38 : item < 47 ? item : '\n', 1);

	// Assume that any second argument will be a number
	height = argc > 1 ? atoi(argv[1]) : 5;

	// Print the tree
	for (padding = (1 << height) / 2, count = 1; padding;){
		output_row('O', 1);
		if (padding /= 2)
			output_row('=', padding * 2 + 1),
			count *= 2,
			output_row('|', 1);
	}

	return 0;
}
