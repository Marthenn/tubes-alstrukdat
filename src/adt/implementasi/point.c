/* File : point.c */
/* Body ADT point */

/* C libraries */
#include <stdio.h>

/* ADT */
#include "../headers/point.h"

/* *** KONSTRUKTOR *** */
void CreatePoint(Point *p, int x, int y)
/* I.S. p sembarang, x dan y terdefinisi */
/* F.S. terbentuk point p dengan absis x dan ordinat y */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    
    p->x = x;
    p->y = y;
}

/* *** GETTER & SETTER *** */
void SetAbsis(Point *p, int x)
/* I.S. p terdefinisi, x nilainya di dalam batas peta */
/* F.S. Mengubah absis p menjadi x */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    p->x = x;
}
void SetOrdinat(Point *p, int y)
/* I.S. p terdefinisi, y nilainya di dalam batas peta */
/* F.S. Mengubah ordinat p menjadi y */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    p->y = y;
}

int GetAbsis(Point p)
/* Mengembalikan absis dari p, yaitu p.x */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    return p.x;
}
int GetOrdinat(Point p)
/* Mengembalikan ordinat dari p, yaitu p.y*/
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    return p.y;
}

/* *** OPERASI LAIN *** */
void MovePointNorth(Point *p)
/* I.S. p terdefinisi */
/* F.S. p digeser ke utara: p.x dikurangi 1 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    (p->x)--;
}
void MovePointSouth(Point *p)
/* I.S. p terdefinisi */
/* F.S. p digeser ke selatan: p.x ditambah 1 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    (p->x)++;
}
void MovePointWest(Point *p)
/* I.S. p terdefinisi */
/* F.S. p digeser ke barat: p.y dikurangi 1 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    (p->y)--;
}
void MovePointEast(Point *p)
/* I.S. p terdefinisi */
/* F.S. p digeser ke timur: p.y ditambah 1 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    (p->y)++;
}

void CetakPoint(Point p)
/* I.S. p terdefinisi */
/* F.S. mencetak (p.x, p.y) ke layar. Tidak mencetak karakter lain di awal maupun akhir*/
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    printf("(%d,%d)", p.x, p.y);
}

boolean IsAdjacent(Point p1, Point p2){
    return((p1.x == p2.x && (p1.y == p2.y+1 || p1.y == p2.y-1)) || (p1.y == p2.y && (p1.x == p2.x+1 || p1.x == p2.x-1)));
}