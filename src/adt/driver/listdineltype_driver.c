#include <stdio.h>
#include "../headers/listdineltype.h"

int main(){
    // Declaration of variables
    ListDinElType l;
    ElType e1 = NewElType(0, (union Data){.i = 1});
    ElType e2 = NewElType(0, (union Data){.i = 2});
    ElType e3 = NewElType(0, (union Data){.i = 3});
    ElType e4 = NewElType(0, (union Data){.i = 4});
    ElType e5 = NewElType(0, (union Data){.i = 5});
    ElType e6 = NewElType(0, (union Data){.i = 6});
    ElType e7 = NewElType(0, (union Data){.i = 7});
    ElType e8 = NewElType(0, (union Data){.i = 8});
    ElType e9 = NewElType(0, (union Data){.i = 9});
    ElType e10 = NewElType(0, (union Data){.i = 10});

    printf("===== CREATE EMPTY LIST =====\n");
    CreateListDinElType(&l, 10);
    PrintListDinElType(l);printf("\n");
    printf("Length: %d\n",ListDinElTypeLength(l));
    printf("Empty: %d\n", IsListDinElTypeEmpty(l));
    printf("Full: %d\n", IsListDinElTypeFull(l));
    printf("\n");

    printf("====== INSERT ELEMENTS ======\n");
    InsertFirstListDinElType(&l, e1);
    InsertFirstListDinElType(&l, e2);
    InsertFirstListDinElType(&l, e3);
    InsertLastListDinElType(&l, e4);
    InsertLastListDinElType(&l, e5);
    InsertLastListDinElType(&l, e6);
    InsertLastListDinElType(&l, e7);
    InsertLastListDinElType(&l, e8);
    InsertLastListDinElType(&l, e9);
    InsertLastListDinElType(&l, e10);
    PrintListDinElType(l);printf("\n"); // [3, 2, 1, 4, 5, 6, 7, 8, 9, 10]
    printf("Length: %d\n",ListDinElTypeLength(l));
    printf("Empty: %d\n", IsListDinElTypeEmpty(l));
    printf("Full: %d\n", IsListDinElTypeFull(l));
    printf("\n");

    printf("====== SHRINK ELEMENTS ======\n");
    ShrinkListDinElType(&l);
    PrintListDinElType(l);printf("\n");
    printf("Length: %d\n",ListDinElTypeLength(l));
    printf("Empty: %d\n", IsListDinElTypeEmpty(l));
    printf("Full: %d\n", IsListDinElTypeFull(l));

    return 0;
}