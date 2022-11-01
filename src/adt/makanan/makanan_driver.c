#include <stdio.h>
#include "makanan.h"
#include "../../app/parser/parser.h"

int main() {
    Makanan m;
    Point p;
    CreatePoint(&p, 2, 3);
    CreateMakanan(&m, 5, NewWord("Telur", 5), 10, 0, p);

    DisplayMakanan(m);
    return 0;
}