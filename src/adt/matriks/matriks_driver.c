/* C libraries */
#include <stdio.h>

/* ADT */
#include "matriks.h"
#include "../makanan/makanan.h"
#include "../eltype/eltype.h"
#include "../waktu/waktu.h"
#include "../point/point.h"
#include "../wordmachine/wordmachine.h"
#include "../charmachine/charmachine.h"
#include "../liststatik/liststatik.h"

/* APP */
#include "../../app/parser/parser.h"

int main(){
    Matriks m1, m2;

    MAT_ELMT(m1, 0, 0) = 2;
    MAT_ELMT(m1, 0, 1) = 5;
    MAT_ELMT(m1, 0, 2) = 10;
    MAT_ELMT(m1, 1, 0) = -2;
    MAT_ELMT(m1, 1, 1) = 100;
    MAT_ELMT(m1, 1, 2) = 7;
    MAT_ELMT(m1, 2, 0) = 69;
    MAT_ELMT(m1, 2, 1) = 42;
    MAT_ELMT(m1, 2, 2) = 5;

    CreateMatriks(3, 3, &m1);
    CreateMatriks(3, 3, &m2);
    printf("Matrix :\n");
    DisplayMatriks(m1);

    CopyMatriks(m1, &m2);
    printf("Copy of Matrix :\n");
    DisplayMatriks(m2);

    return 0;
}