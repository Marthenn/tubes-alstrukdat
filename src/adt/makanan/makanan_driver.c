#include <stdio.h>
#include "makanan.h"
#include "../../app/parser/parser.h"

int main() {
    Makanan m;
    Point p;
    CreatePoint(&p, 2, 3);
    CreateMakanan(&m, 5, NewWord("Telur", 5), 10, 0, BUY_WORD, p, 3, 2);
    /* Info yang seharusnya dikeluarkan : Telur - 10 Menit - Buy - 0 */

    DisplayMakanan(m);
    return 0;
}