int fun1(int a) {
	int b;
	int c;
	b = a + 2;
	if (b > 3) 
		c = a - 5;
	return c;
}

int main() {
	int d;
	int b;
	d = fun1(5);
	b = d - 2;
	return b;
}
