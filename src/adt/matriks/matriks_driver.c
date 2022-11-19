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

    CreateMatriks(3, 3, &m1);
    CreateMatriks(3, 3, &m2);

    MAT_ELMT(m1, 0, 0) = 'a';
    MAT_ELMT(m1, 0, 1) = 'b';
    MAT_ELMT(m1, 0, 2) = 'c';
    MAT_ELMT(m1, 1, 0) = 'd';
    MAT_ELMT(m1, 1, 1) = 'e';
    MAT_ELMT(m1, 1, 2) = 'f';
    MAT_ELMT(m1, 2, 0) = 'g';
    MAT_ELMT(m1, 2, 1) = 'h';
    MAT_ELMT(m1, 2, 2) = 'i';

    printf("Matrix :\n");
    DisplayCharMatriks(m1);

    CopyMatriks(m1, &m2);
    printf("Copy of Matrix :\n");
    DisplayCharMatriks(m2);

    return 0;
}