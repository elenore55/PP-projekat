// OPIS: neodgovarajuci tip argumenta

int f1(int a) {
    return a + 15;
}

unsigned f2() {
    return 10u;
}

int main() {
    return f1(f2());
}