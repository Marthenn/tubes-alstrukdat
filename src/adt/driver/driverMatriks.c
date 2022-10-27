#include <stdio.h>
#include "../headers/matriks.h"

int main(){
    Matriks m1, m2;
    ElType e1 = newElType(0, (union data){.i = 2});
    ElType e2 = newElType(0, (union data){.i = 5});
    ElType e3 = newElType(0, (union data){.i = 10});
    ElType e4 = newElType(0, (union data){.i = -2});
    ElType e5 = newElType(0, (union data){.i = 100});
    ElType e6 = newElType(0, (union data){.i = 7});
    ElType e7 = newElType(0, (union data){.i = 69});
    ElType e8 = newElType(0, (union data){.i = 42});
    ElType e9 = newElType(0, (union data){.i = 5});

    ELMT(m1, 0, 0) = e1;
    ELMT(m1, 0, 1) = e2;
    ELMT(m1, 0, 2) = e3;
    ELMT(m1, 1, 0) = e4;
    ELMT(m1, 1, 1) = e5;
    ELMT(m1, 1, 2) = e6;
    ELMT(m1, 2, 0) = e7;
    ELMT(m1, 2, 1) = e8;
    ELMT(m1, 2, 2) = e9;

    createMatriks(3, 3, &m1);
    createMatriks(3, 3, &m2);
    printf("Matrix :\n");
    displayMatriks(m1);

    copyMatriks(m1, &m2);
    printf("Copy of Matrix :\n");
    displayMatriks(m2);

    return 0;
}