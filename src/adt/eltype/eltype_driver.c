/* C libraries */
#include <stdio.h>

/* ADT */
#include "eltype.h"

int main(){
    printf("--------\n");
    printf("Test ElType integer\n");
    ElType a = NewElType(0, (union Data){.i=1});
    ElType b = NewElType(0, (union Data){.i=2});
    printf("a: ");PrintElType(a);printf("\n");
    printf("b: ");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    printf("Change the Value of a and copying it to b\n");
    SetVal(&a, 0, (union Data){.i=3});
    CopyElType(&b,a);
    printf("a: ");PrintElType(a);printf("\n");
    printf("b: ");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    printf("--------\n");
    printf("Test ElType float\n");
    a = NewElType(1, (union Data){.f=1.5});
    b = NewElType(1, (union Data){.f=2.5});
    printf("a: ");PrintElType(a);printf("\n");
    printf("b: ");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    printf("Change the Value of a and copying it to b\n");
    SetVal(&a, 1, (union Data){.f=3.5});
    CopyElType(&b,a);
    printf("a: ");PrintElType(a);printf("\n");
    printf("b: ");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    printf("--------\n");
    printf("Test ElType Char\n");
    a = NewElType(2, (union Data){.c='a'});
    b = NewElType(2, (union Data){.c='b'});
    printf("a: ");PrintElType(a);printf("\n");
    printf("b: ");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    printf("Change the Value of a and copying it to b\n");
    SetVal(&a, 2, (union Data){.c='c'});
    CopyElType(&b,a);
    printf("a: ");PrintElType(a);printf("\n");
    printf("b: ");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    printf("--------\n");
    printf("Test ElType Makanan\n");
    Waktu w1,w2,w3; CreateWaktu(&w1, 1, 1, 1); CreateWaktu(&w2, 2, 2, 2); CreateWaktu(&w3, 3, 3, 3);
    Point p1,p2,p3; CreatePoint(&p1, 1, 1); CreatePoint(&p2, 2, 2); CreatePoint(&p3, 3, 3);
    Word s1,s2,s3;
    s1.TabWord[0]='a'; s1.TabWord[1]='b'; s1.TabWord[2]='c'; s1.Length=3;
    s2.TabWord[0]='d'; s2.TabWord[1]='e'; s2.TabWord[2]='f'; s2.Length=3;
    s3.TabWord[0]='g'; s3.TabWord[1]='h'; s3.TabWord[2]='i'; s3.Length=3;
    Makanan m1,m2,m3; CreateMakanan(&m1, 1, s1, w1, w1, p1); CreateMakanan(&m2, 2, s2, w2, w2, p2);CreateMakanan(&m3, 3, s3, w3, w3, p3);
    a = NewElType(3, (union Data){.m=m1});
    b = NewElType(3, (union Data){.m=m2});
    printf("a:\n");PrintElType(a);printf("\n");
    printf("b:\n");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    printf("\nChange the Value of a and copying it to b\n");
    SetVal(&a, 3, (union Data){.m=m3});
    CopyElType(&b,a);
    printf("a:\n");PrintElType(a);printf("\n");
    printf("b:\n");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    return 0;
}