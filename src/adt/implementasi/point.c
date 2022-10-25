/* File : point.c */
/* Body ADT point */

#include <stdio.h>
#include "../headers/point.h"

/* *** KONSTRUKTOR *** */
void createPoint(point *p, int x, int y)
/* I.S. p sembarang, x dan y terdefinisi */
/* F.S. terbentuk point p dengan absis x dan ordinat y */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    p->x = x;
    p->y = y;
}

/* *** GETTER & SETTER *** */
void setAbsis(point *p, int x)
/* I.S. p terdefinisi, x nilainya di dalam batas peta */
/* F.S. Mengubah absis p menjadi x */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    p->x = x;
}
void setOrdinat(point *p, int y)
/* I.S. p terdefinisi, y nilainya di dalam batas peta */
/* F.S. Mengubah ordinat p menjadi y */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    p->y = y;
}

int getAbsis(point p)
/* Mengembalikan absis dari p, yaitu p.x */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    return p.x;
}
int getOrdinat(point p)
/* Mengembalikan ordinat dari p, yaitu p.y*/
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    return p.y;
}

/* *** OPERASI LAIN *** */
void movePointNorth(point *p)
/* I.S. p terdefinisi */
/* F.S. p digeser ke utara: p.x dikurangi 1 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    (p->x)--;
}
void movePointSouth(point *p)
/* I.S. p terdefinisi */
/* F.S. p digeser ke selatan: p.x ditambah 1 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    (p->x)++;
}
void movePointWest(point *p)
/* I.S. p terdefinisi */
/* F.S. p digeser ke barat: p.y dikurangi 1 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    (p->y)--;
}
void movePointEast(point *p)
/* I.S. p terdefinisi */
/* F.S. p digeser ke timur: p.y ditambah 1 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    (p->y)++;
}

void cetakPoint(point p)
/* I.S. p terdefinisi */
/* F.S. mencetak (p.x, p.y) ke layar. Tidak mencetak karakter lain di awal maupun akhir*/
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    printf("(%d,%d)", p.x, p.y);
}