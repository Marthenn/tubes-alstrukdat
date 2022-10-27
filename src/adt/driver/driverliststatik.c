#include <stdio.h>
#include "../headers/liststatik.h"

int main(){
    ListStatik l1, l2;
    ElType e1 = newElType(0, (union data){.i = 2});
    ElType e2 = newElType(0, (union data){.i = 5});
    ElType e3 = newElType(0, (union data){.i = 10});
    ElType e4 = newElType(0, (union data){.i = -2});
    ElType e5 = newElType(0, (union data){.i = 100});
    ElType e6 = newElType(0, (union data){.i = 7});
    ElType e7 = newElType(0, (union data){.i = 3});
    ElType e8 = newElType(0, (union data){.i = 5});
    ElType del = newElType(0, (union data){.i = 0});

    CreateListStatik(&l1);
    CreateListStatik(&l2);

    insertFirst(&l1, e1);
    insertFirst(&l1, e2);
    insertLast(&l1, e3);
    insertLast(&l1, e4);
    insertAt(&l1, e5, 1);
    insertLast(&l1, e6);
    insertAt(&l1, e7, 3);
    insertFirst(&l1, e2);
    printf("List : ");
    displayList(l1);

    printf("\nLength : %d", listLength(l1));
    printf("\nIndex of e2 : %d", indexOf(l1, e2));
    printf("\nIndex of e7 : %d", indexOf(l1, e7));

    copyList(l1, &l2);
    printf("\nCopied List : ");
    displayList(l2);
    
    deleteAt(&l2, &del, 3);
    deleteFirst(&l2, &del);
    deleteLast(&l2, &del);
    printf("\nCopy of original list with deleted element : ");
    displayList(l2);


    return 0;
}