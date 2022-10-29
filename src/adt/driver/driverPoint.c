/* File : driverPoint.c */
/* Driver untuk ADT Point */

/* C libraries */
#include <stdio.h>

/* ADT */
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

    /* ADJACENT */
    Point p1,p2,p3;
    CreatePoint(&p1, 0, 0);
    CreatePoint(&p2, 1, 0);
    CreatePoint(&p3, 2, 0);
    _assert(IsAdjacent(p1, p2), "ADJACENT1");
    _assert(!IsAdjacent(p1, p3), "ADJACENT2");

    /* OUTPUT */
    CetakPoint(p); puts("");
    printf("Seluruh tes berhasil dijalankan. Point di atas seharusnya bernilai (200, 150)\n");

    return 0;
}