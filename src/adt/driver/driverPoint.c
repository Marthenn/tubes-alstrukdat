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
    Point p;
    CreatePoint(&p, 0, 0);
    _assert(GetAbsis(p) == 0, "ABSIS0");
    _assert(GetOrdinat(p) == 0, "ORDINAT0");

    /* MOVE */
    MovePointNorth(&p);
    MovePointNorth(&p);
    _assert(GetAbsis(p) == -2, "NORTH");
    MovePointSouth(&p);
    MovePointEast(&p);
    _assert(GetAbsis(p) == -1, "SOUTH");
    _assert(GetOrdinat(p) == 1, "EAST");
    MovePointWest(&p);
    MovePointWest(&p);
    _assert(GetOrdinat(p) == -1, "WEST");

    /* SET/GET */
    SetAbsis(&p, 200);
    SetOrdinat(&p, 150);
    _assert(GetAbsis(p) == 200, "SETABSIS");
    _assert(GetOrdinat(p) == 150, "SETORDINAT");

    /* OUTPUT */
    CetakPoint(p);

    return 0;
}