/* File : Matriks.c*/
/* Implementasi ADT Matriks */

#include <stdio.h>
#include "../headers/matriks.h"

/* *** Konstruktor membentuk Matriks *** */
void CreateMatriks(int nRows, int nCols, Matriks *m){
/* Membentuk sebuah Matriks "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

    // KAMUS LOKAL
    // ALGORITMA
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType GetLastIdxRow(Matriks m){
/* Mengirimkan Index baris terbesar m */

    // KAMUS LOKAL
    // ALGORITMA
    return ROW_EFF(m) - 1;
}
IdxType GetLastIdxCol(Matriks m){
/* Mengirimkan Index kolom terbesar m */

    // KAMUS LOKAL
    // ALGORITMA
    return COL_EFF(m) - 1;
}
boolean IsMatIdxEff(Matriks m, IdxType i, IdxType j){
/* Mengirimkan true jika i, j adalah Index efektif bagi m */

    // KAMUS LOKAL
    // ALGORITMA
    return i >= 0 && i <= GetLastIdxRow(m) && j >= 0 && GetLastIdxCol(m);
}

/* ********** Assignment  Matriks ********** */
void CopyMatriks(Matriks mIn, Matriks *mOut){
/* Melakukan assignment mOut <- mIn */

    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    for(i = 0; i <= GetLastIdxRow(mIn); i++){
        for(j = 0; j <= GetLastIdxCol(mIn); j++){
            MAT_ELMT(*mOut, i, j) = MAT_ELMT(mIn, i, j);
        }
    }
}

/* ********** TULIS ********** */
void DisplayMatriks(Matriks m){
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3
1 2 3
4 5 6
8 9 10
*/

    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    for(i = 0; i <= GetLastIdxRow(m); i++){
        for(j = 0; j <= GetLastIdxCol(m); j++){
            PrintElType(MAT_ELMT(m, i, j));
            printf(" ");
        }
        printf("\n");
    }
}