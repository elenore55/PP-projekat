int f1(int num) {
	return num + 23 - 10 + 5;
}

int f2() {
	return 100 - 50 - 5 - 10;
}

int main() {
	int a;
	int b;
	int c;
	a = f3();
	b = f1(a);
	c = f2();
	return a + b - c;
}

int f3() {
	int val1;
	val1 = 55;
	return val1 - 23 + 1 - 5;
}

unsigned f4(unsigned val) {
	unsigned num1;
	unsigned num2;
	unsigned num3;

	num1 = val + 20u - 5u;
	if (num1 < 50u) {
		num2 = num1 + 10u;
		num3 = num2 - num1 + 23u;
	}
	else {
		if (num1 != 55u) {
			num2 = num1 - 11u;
			num3 = num1 - num2 - 10u; 	
		}
		else 
			num3 = 11u;
	}
	return num2 + num3 - num1;
}
