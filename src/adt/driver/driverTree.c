#include <stdio.h>
#include "../headers/tree.h"

int main(){
    printf("--------\n");
    Tree t = NewTree (NewElType(0, (union Data){.i=1}));
    PrintTree(t);printf("\n");
    printf("children t: %d\n",numberChildren(t));
    printf("--------\n");
    AddChild(&t, NewElType(0, (union Data){.i=2}));
    AddChild(&t, NewElType(0, (union Data){.i=3}));
    AddChild(&t, NewElType(0, (union Data){.i=4}));
    PrintTree(t);printf("\n");
    printf("children t: %d\n",numberChildren(t));
    printf("--------\n");
    AddChild(&(t->firstChild), NewElType(0, (union Data){.i=5}));
    AddChild(&(t->firstChild), NewElType(0, (union Data){.i=6}));
    PrintTree(t);printf("\n");
    printf("children t: %d\n",NumberChildren(t));
    printf("children t->firstChild: %d\n",NumberChildren(t->firstChild));
    printf("--------\n");
    printf("CHECK CHILDREN\n");
    printf("2: ");printf("%d",isChild(t, NewElType(0, (union Data){.i=2})));printf("\n");
    printf("3: ");printf("%d",isChild(t, NewElType(0, (union Data){.i=3})));printf("\n");
    printf("4: ");printf("%d",isChild(t, NewElType(0, (union Data){.i=4})));printf("\n");
    printf("5: ");printf("%d",isChild(t, NewElType(0, (union Data){.i=5})));printf("\n");
    printf("6: ");printf("%d",isChild(t, NewElType(0, (union Data){.i=6})));printf("\n");
    printf("--------\n");
    printf("CHECK PART OF\n");
    printf("1: %d\n",isPartOf(t, NewElType(0, (union Data){.i=1})));
    printf("2: %d\n",isPartOf(t, NewElType(0, (union Data){.i=2})));
    printf("5: %d\n",isPartOf(t, NewElType(0, (union Data){.i=5})));
    printf("7: %d\n",isPartOf(t, NewElType(0, (union Data){.i=7})));
    return 0;
}