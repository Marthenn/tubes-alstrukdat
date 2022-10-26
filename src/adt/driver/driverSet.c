#include <stdio.h>
#include "../headers/set.h"

int main(){
    set s1,s2; createSet(&s1); createSet(&s2);
    ElType e1 = newElType(0, (union data){.i = 1});
    ElType e2 = newElType(0, (union data){.i = 2});
    ElType e3 = newElType(0, (union data){.i = 3});
    ElType e4 = newElType(0, (union data){.i = 4});
    ElType e5 = newElType(0, (union data){.i = 5});
    ElType e6 = newElType(0, (union data){.i = 6});

    add(&s1, e1);
    add(&s1, e2);
    add(&s1, e3);
    add(&s1, e4);

    printSet(s1);printf("\n");

    add(&s2, e3);
    add(&s2, e4);
    printSet(s2);printf("\n");

    printf("s2 is subset of s1: %d\n", isSubset(s2, s1));
    printf("s1 is subset of s2: %d\n", isSubset(s1, s2));

    set s3 = difference(s1, s2);
    printf("s1 - s2: ");printSet(s3);printf("\n");

    add(&s2, e5);
    add(&s2, e6);
    printf("s2: ");printSet(s2);printf("\n");

    s3 = unionSet(s1, s2);
    printf("s1 union s2: ");printSet(s3);printf("\n");

    s3 = intersection(s1, s2);
    printf("s1 intersection s2: ");printSet(s3);printf("\n");

    copySet(&s1, s2);
    printf("s1: ");printSet(s1);printf("\n");

    removeSet(&s1, e3);
    printf("s1: ");printSet(s1);printf("\n");

    return 0;
}