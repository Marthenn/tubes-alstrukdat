#include <stdio.h>
#include "../headers/eltype.h"

int main(){
    printf("--------\n");
    printf("Test ElType integer\n");
    ElType a = NewElType(0, (union Data){.i=1});
    ElType b = NewElType(0, (union Data){.i=2});
    printf("a: ");PrintElType(a);printf("\n");
    printf("b: ");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    printf("Change the Value of a and copying it to b\n");
    SetVal(&a, (union Data){.i=3});
    CopyElType(&b,a);
    printf("a: ");PrintElType(a);printf("\n");
    printf("b: ");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    printf("--------\n");
    printf("Test ElType float\n");
    a = NewElType(0, (union Data){.i=1.5});
    b = NewElType(0, (union Data){.i=2.5});
    printf("a: ");PrintElType(a);printf("\n");
    printf("b: ");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    printf("Change the Value of a and copying it to b\n");
    setVal(&a, (union Data){.i=3.5});
    CopyElType(&b,a);
    printf("a: ");PrintElType(a);printf("\n");
    printf("b: ");PrintElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",Compare(a,b));
    printf("--------\n");
    return 0;
}