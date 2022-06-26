// OPIS: Neodgovarajuci tip povratne vrednosti

int f() {
    unsigned b;
    b = 5u;
    return b;
}

int main() {
    return 0;
}