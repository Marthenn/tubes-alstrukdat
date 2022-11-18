#include <stdio.h>
#include "set.h"

int main(){
    Set s1,s2; CreateSet(&s1); CreateSet(&s2);

    SetAdd(&s1, 1, 1);
    SetAdd(&s1, 2, 2);
    SetAdd(&s1, 3, 5);
    SetAdd(&s1, 4, 3);

    PrintSet(s1);printf("\n");

    SetAdd(&s2, 3, 2);
    SetAdd(&s2, 4, 3);
    PrintSet(s2);printf("\n");

    printf("s2 is subset of s1: %d\n", IsSubset(s2, s1));
    printf("s1 is subset of s2: %d\n", IsSubset(s1, s2));

    Set s3 = Difference(s1, s2);
    printf("s1 - s2: ");PrintSet(s3);printf("\n");

    SetAdd(&s2, 1, 4);
    SetAdd(&s2, 3, 2);
    printf("s2: ");PrintSet(s2);printf("\n");

    s3 = UnionSet(s1, s2);
    printf("s1 union s2: ");PrintSet(s3);printf("\n");

    s3 = Intersection(s1, s2);
    printf("s1 intersection s2: ");PrintSet(s3);printf("\n");

    CopySet(&s1, s2);
    printf("s1 copied from s2: ");PrintSet(s1);printf("\n");

    RemoveSet(&s1, 3, 5);
    printf("s1 remove 5 3's: ");PrintSet(s1);printf("\n");

    return 0;
}