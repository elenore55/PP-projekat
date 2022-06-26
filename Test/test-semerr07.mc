//OPIS: Neodgovarajuci tip operanada aritmetickih i relacionih operacija

int main() {
    int a;
    int b;
    unsigned c;
    a = 10;
    b = 20;
    c = 30u;
    if (b >= c)
        a = b + c;
    return 0;
}