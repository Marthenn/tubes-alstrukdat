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
    ElType e1 = NewElType(0, (union Data){.i = 2});
    ElType e2 = NewElType(0, (union Data){.i = 5});
    ElType e3 = NewElType(0, (union Data){.i = 10});
    ElType e4 = NewElType(0, (union Data){.i = -2});
    ElType e5 = NewElType(0, (union Data){.i = 100});
    ElType e6 = NewElType(0, (union Data){.i = 7});
    ElType e7 = NewElType(0, (union Data){.i = 69});
    ElType e8 = NewElType(0, (union Data){.i = 42});
    ElType e9 = NewElType(0, (union Data){.i = 5});

    MAT_ELMT(m1, 0, 0) = e1;
    MAT_ELMT(m1, 0, 1) = e2;
    MAT_ELMT(m1, 0, 2) = e3;
    MAT_ELMT(m1, 1, 0) = e4;
    MAT_ELMT(m1, 1, 1) = e5;
    MAT_ELMT(m1, 1, 2) = e6;
    MAT_ELMT(m1, 2, 0) = e7;
    MAT_ELMT(m1, 2, 1) = e8;
    MAT_ELMT(m1, 2, 2) = e9;

    CreateMatriks(3, 3, &m1);
    CreateMatriks(3, 3, &m2);
    printf("Matrix :\n");
    DisplayMatriks(m1);

    CopyMatriks(m1, &m2);
    printf("Copy of Matrix :\n");
    DisplayMatriks(m2);

    return 0;
}