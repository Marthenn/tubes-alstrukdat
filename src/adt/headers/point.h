/* File : point.h */
/* ADT point berisi koordinat x dan y */

#ifndef point_H
#define point_H

typedef struct {
    int x; //absis
    int y; //ordinat
} point;

/* *** KONSTRUKTOR *** */
void createPoint(point *p, int x, int y);
/* I.S. p sembarang, x dan y terdefinisi */
/* F.S. terbentuk point p dengan absis x dan ordinat y */

/* *** GETTER & SETTER *** */
void setAbsis(point *p, int x);
/* I.S. p terdefinisi, x nilainya di dalam batas peta */
/* F.S. Mengubah absis p menjadi x */
void setOrdinat(point *p, int y);
/* I.S. p terdefinisi, y nilainya di dalam batas peta */
/* F.S. Mengubah ordinat p menjadi y */

int getAbsis(point p);
/* Mengembalikan absis dari p, yaitu p.x */
int getOrdinat(point p);
/* Mengembalikan ordinat dari p, yaitu p.y*/

/* *** OPERASI LAIN *** */
void movePointNorth(point *p);
/* I.S. p terdefinisi */
/* F.S. p digeser ke utara: p.x dikurangi 1 */
void movePointSouth(point *p);
/* I.S. p terdefinisi */
/* F.S. p digeser ke selatan: p.x ditambah 1 */
void movePointWest(point *p);
/* I.S. p terdefinisi */
/* F.S. p digeser ke barat: p.y dikurangi 1 */
void movePointEast(point *p);
/* I.S. p terdefinisi */
/* F.S. p digeser ke timur: p.y ditambah 1 */

void cetakPoint(point p);
/* I.S. p terdefinisi */
/* F.S. mencetak (p.x, p.y) ke layar. Tidak mencetak karakter lain di awal maupun akhir*/
#endif