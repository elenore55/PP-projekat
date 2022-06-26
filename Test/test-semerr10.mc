// OPIS: Neodgovarajuci broj parametara

int f1(int a) {
    return a + 15;
}

unsigned f2() {
    return 10u;
}

int main() {
    int a;
    unsigned b;
    a = f1(a);
    b = f2(a);
    return a;
}