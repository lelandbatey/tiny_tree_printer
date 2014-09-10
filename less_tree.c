typedef int j;
int p(char item, int len){
	for (;len; --len)
		putchar(item);
}

int main(int c, char **v){
	int i,height = 5;
	c>1?height=atoi(v[1]):0;
	height = 1<<height;
	int base = height;
	for (;base;){
		base /= 2;
		for (i=base?height/base:0;i;i--)
			p(' ',base-1),
			p(!(i%2)*32+32,1);
		p('\n',1);
	}
}

