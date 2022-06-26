// OPIS: Redeklaracija promenljive

int f() {
    int a;
    int b;
    int a;
    a = 3;
    return a;
}

int main() {
    return f();
}