/* File : point.h */
/* ADT point berisi koordinat x dan y */

#ifndef point_H
#define point_H

typedef struct {
    int x; //absis
    int y; //ordinat
} Point;

/* *** KONSTRUKTOR *** */
void createPoint(Point *p, int x, int y);
/* I.S. p sembarang, x dan y terdefinisi */
/* F.S. terbentuk point p dengan absis x dan ordinat y */

/* *** GETTER & SETTER *** */
void setAbsis(Point *p, int x);
/* I.S. p terdefinisi, x nilainya di dalam batas peta */
/* F.S. Mengubah absis p menjadi x */
void setOrdinat(Point *p, int y);
/* I.S. p terdefinisi, y nilainya di dalam batas peta */
/* F.S. Mengubah ordinat p menjadi y */

int GetAbsis(Point p);
/* Mengembalikan absis dari p, yaitu p.x */
int GetOrdinat(Point p);
/* Mengembalikan ordinat dari p, yaitu p.y*/

/* *** OPERASI LAIN *** */
void MovePointNorth(Point *p);
/* I.S. p terdefinisi */
/* F.S. p digeser ke utara: p.x dikurangi 1 */
void MovePointSouth(Point *p);
/* I.S. p terdefinisi */
/* F.S. p digeser ke selatan: p.x ditambah 1 */
void MovePointWest(Point *p);
/* I.S. p terdefinisi */
/* F.S. p digeser ke barat: p.y dikurangi 1 */
void MovePointEast(Point *p);
/* I.S. p terdefinisi */
/* F.S. p digeser ke timur: p.y ditambah 1 */

void CetakPoint(Point p);
/* I.S. p terdefinisi */
/* F.S. mencetak (p.x, p.y) ke layar. Tidak mencetak karakter lain di awal maupun akhir*/
#endif