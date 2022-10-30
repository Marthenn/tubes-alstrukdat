#include <stdio.h>
#include "../headers/set.h"

int main(){
    Set s1,s2; createSet(&s1); CreateSet(&s2);
    ElType e1 = NewElType(0, (union Data){.i = 1});
    ElType e2 = NewElType(0, (union Data){.i = 2});
    ElType e3 = NewElType(0, (union Data){.i = 3});
    ElType e4 = NewElType(0, (union Data){.i = 4});
    ElType e5 = NewElType(0, (union Data){.i = 5});
    ElType e6 = NewElType(0, (union Data){.i = 6});

    add(&s1, e1);
    add(&s1, e2);
    add(&s1, e3);
    add(&s1, e4);

    PrintSet(s1);printf("\n");

    add(&s2, e3);
    add(&s2, e4);
    PrintSet(s2);printf("\n");

    printf("s2 is subset of s1: %d\n", IsSubset(s2, s1));
    printf("s1 is subset of s2: %d\n", IsSubset(s1, s2));

    Set s3 = Difference(s1, s2);
    printf("s1 - s2: ");PrintSet(s3);printf("\n");

    Add(&s2, e5);
    Add(&s2, e6);
    printf("s2: ");PrintSet(s2);printf("\n");

    s3 = UnionSet(s1, s2);
    printf("s1 union s2: ");PrintSet(s3);printf("\n");

    s3 = Intersection(s1, s2);
    printf("s1 intersection s2: ");PrintSet(s3);printf("\n");

    CopySet(&s1, s2);
    printf("s1: ");printSet(s1);printf("\n");

    RemoveSet(&s1, e3);
    printf("s1: ");PrintSet(s1);printf("\n");

    return 0;
}