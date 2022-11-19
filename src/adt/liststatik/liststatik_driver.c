/* C libraries */
#include <stdio.h>

/* ADT */
#include "liststatik.h"

int main(){
    ListStatik l1, l2;
    ElType e1 = NewElType(0, (union Data){.i = 2});
    ElType e2 = NewElType(0, (union Data){.i = 5});
    ElType e3 = NewElType(0, (union Data){.i = 10});
    ElType e4 = NewElType(0, (union Data){.i = -2});
    ElType e5 = NewElType(0, (union Data){.i = 100});
    ElType e6 = NewElType(0, (union Data){.i = 7});
    ElType e7 = NewElType(0, (union Data){.i = 3});
    ElType e8 = NewElType(0, (union Data){.i = 5});
    ElType del = NewElType(0, (union Data){.i = 0});

    CreateListStatik(&l1);
    CreateListStatik(&l2);

    ListInsertFirst(&l1, e1);
    ListInsertFirst(&l1, e2);
    ListInsertLast(&l1, e3);
    ListInsertLast(&l1, e4);
    ListInsertAt(&l1, e5, 1);
    ListInsertLast(&l1, e6);
    ListInsertAt(&l1, e7, 3);
    ListInsertFirst(&l1, e2);
    printf("List : ");
    DisplayList(l1);

    printf("\nLength : %d", ListLength(l1));
    printf("\nIndex of e2 : %d", ListIndexOf(l1, e2));
    printf("\nIndex of e7 : %d", ListIndexOf(l1, e7));

    CopyList(l1, &l2);
    printf("\nCopied List : ");
    DisplayList(l2);
    
    ListDeleteAt(&l2, &del, 3);
    ListDeleteFirst(&l2, &del);
    ListDeleteLast(&l2, &del);
    printf("\nCopy of original list with deleted element : ");
    DisplayList(l2);


    return 0;
}