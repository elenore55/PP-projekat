int f() {
	int b;
	b = 0;
	{
		if (b > 0) 
		{
			if (b <= 30)
				b = 55;
			b = b + 12 - 3 - 7;
			return b;			
		}
		else
			b = b + 25 + b;
	}
	return 0;
}


int main() {
	int value;
	value = f();
	value = value - 2 - 1;
	return value;
}
