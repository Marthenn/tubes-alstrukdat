#include <stdio.h>
#include "../headers/eltype.h"

int main(){
    printf("--------\n");
    printf("Test ElType integer\n");
    ElType a = newElType(0, (union data){.i=1});
    ElType b = newElType(0, (union data){.i=2});
    printf("a: ");printElType(a);printf("\n");
    printf("b: ");printElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",compare(a,b));
    printf("Change the Value of a and copying it to b\n");
    setVal(&a, (union data){.i=3});
    copyElType(&b,a);
    printf("a: ");printElType(a);printf("\n");
    printf("b: ");printElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",compare(a,b));
    printf("--------\n");
    printf("Test ElType float\n");
    a = newElType(0, (union data){.i=1.5});
    b = newElType(0, (union data){.i=2.5});
    printf("a: ");printElType(a);printf("\n");
    printf("b: ");printElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",compare(a,b));
    printf("Change the Value of a and copying it to b\n");
    setVal(&a, (union data){.i=3.5});
    copyElType(&b,a);
    printf("a: ");printElType(a);printf("\n");
    printf("b: ");printElType(b);printf("\n");
    printf("a:b = ");printf("%d\n",compare(a,b));
    printf("--------\n");
    return 0;
}