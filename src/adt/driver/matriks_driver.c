/* C libraries */
#include <stdio.h>

/* ADT */
#include "../headers/matriks.h"
#include "../headers/makanan.h"
#include "../headers/eltype.h"
#include "../headers/waktu.h"
#include "../headers/point.h"
#include "../headers/wordmachine.h"
#include "../headers/charmachine.h"
#include "../headers/liststatik.h"

/* APP */
#include "../../app/headers/parser.h"

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