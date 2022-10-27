#include <stdio.h>
#include "../headers/liststatik.h"

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

    InsertFirst(&l1, e1);
    InsertFirst(&l1, e2);
    InsertLast(&l1, e3);
    InsertLast(&l1, e4);
    InsertAt(&l1, e5, 1);
    InsertLast(&l1, e6);
    InsertAt(&l1, e7, 3);
    InsertFirst(&l1, e2);
    printf("List : ");
    DisplayList(l1);

    printf("\nLength : %d", listLength(l1));
    printf("\nIndex of e2 : %d", indexOf(l1, e2));
    printf("\nIndex of e7 : %d", indexOf(l1, e7));

    CopyList(l1, &l2);
    printf("\nCopied List : ");
    DisplayList(l2);
    
    DeleteAt(&l2, &del, 3);
    DeleteFirst(&l2, &del);
    DeleteLast(&l2, &del);
    printf("\nCopy of original list with deleted element : ");
    DisplayList(l2);


    return 0;
}