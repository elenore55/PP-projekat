int abs(int a) {
	int b;
	if (a >= 0)
		b = a;
	else
		b = a - a - a;
	return b;
}

unsigned fun1(int a) {
	int b;
	int c;
	b = abs(a) + 2;
	if (b > 3) 
		c = a - 5;
	return 3u;
}

int main() {
	unsigned d;
	d = fun1(5);
	return 0;
}
