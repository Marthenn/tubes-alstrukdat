/* File : matriks.h*/
/* Definisi ADT Matriks*/

#ifndef MATRIKS_H
#define MATRIKS_H

#include <stdio.h>
#include "boolean.h"
#include "eltype.h"

# define ROW_CAP 100
# define COL_CAP 100

typedef int IdxType;

typedef struct{
    ElType mem[ROW_CAP][COL_CAP];
    int rowEff;
    int colEff;
} Matriks;

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define MAT_ELMT(M, i, j) (M).mem[(i)][(j)]

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matriks *** */
void CreateMatriks(int nRows, int nCols, Matriks *m);
/* Membentuk sebuah Matriks "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType GetLastIdxRow(Matriks m);
/* Mengirimkan Index baris terbesar m */
IdxType GetLastIdxCol(Matriks m);
/* Mengirimkan Index kolom terbesar m */
boolean IsMatIdxEff(Matriks m, IdxType i, IdxType j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */

/* ********** Assignment  Matriks ********** */
void CopyMatriks(Matriks mIn, Matriks *mOut);
/* Melakukan assignment mOut <- mIn */

void DisplayMatriks(Matriks m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

#endif