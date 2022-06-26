unsigned f1(unsigned num) {
    unsigned x;
    unsigned y;
    if (num == 10u) {
        x = num + 2u;
        y = num - 2u;
        return x + y;
    }
	return num + 23u - 10u + 5u;
}

int main() {
	unsigned a;
	unsigned b;
	unsigned c;
    a = 10u;
    b = f1(f1(f1(a) + f2()));
    c = f1(b) - f2() + f1(a);
	return 0;
}

unsigned f2() {
	unsigned num;
	num = 100u - 50u - 5u - 10u;
    num = f1(num);
	return num;
}