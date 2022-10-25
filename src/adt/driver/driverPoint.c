/* File : driverPoint.c */
/* Driver untuk ADT Point */

#include <stdio.h>
#include "../headers/point.h"
#include "../headers/boolean.h"

void _assert(boolean x, char ID[]) 
/* I.S. x, ID terdefinisi */
/* F.S. Mengeluarkan pesan jika x false */
{
    if(!x) printf("ASSERT FAILED AT ID : %s\n", ID);
}

int main() {
    point p;
    createPoint(&p, 0, 0);
    _assert(getAbsis(p) == 0, "ABSIS0");
    _assert(getOrdinat(p) == 0, "ORDINAT0");

    /* MOVE */
    movePointNorth(&p);
    movePointNorth(&p);
    _assert(getAbsis(p) == -2, "NORTH");
    movePointSouth(&p);
    movePointEast(&p);
    _assert(getAbsis(p) == -1, "SOUTH");
    _assert(getOrdinat(p) == 1, "EAST");
    movePointWest(&p);
    movePointWest(&p);
    _assert(getOrdinat(p) == -1, "WEST");

    /* SET/GET */
    setAbsis(&p, 200);
    setOrdinat(&p, 150);
    _assert(getAbsis(p) == 200, "SETABSIS");
    _assert(getOrdinat(p) == 150, "SETORDINAT");

    /* OUTPUT */
    cetakPoint(p);

    return 0;
}