#include <stdio.h>
#include "../headers/tree.h"

int main(){
    printf("--------\n");
    tree t = newTree (newElType(0, (union data){.i=1}));
    printTree(t);printf("\n");
    printf("children t: %d\n",numberChildren(t));
    printf("--------\n");
    addChild(&t, newElType(0, (union data){.i=2}));
    addChild(&t, newElType(0, (union data){.i=3}));
    addChild(&t, newElType(0, (union data){.i=4}));
    printTree(t);printf("\n");
    printf("children t: %d\n",numberChildren(t));
    printf("--------\n");
    addChild(&(t->firstChild), newElType(0, (union data){.i=5}));
    addChild(&(t->firstChild), newElType(0, (union data){.i=6}));
    printTree(t);printf("\n");
    printf("children t: %d\n",numberChildren(t));
    printf("children t->firstChild: %d\n",numberChildren(t->firstChild));
    printf("--------\n");
    printf("CHECK CHILDREN\n");
    printf("2: ");printf("%d",isChild(t, newElType(0, (union data){.i=2})));printf("\n");
    printf("3: ");printf("%d",isChild(t, newElType(0, (union data){.i=3})));printf("\n");
    printf("4: ");printf("%d",isChild(t, newElType(0, (union data){.i=4})));printf("\n");
    printf("5: ");printf("%d",isChild(t, newElType(0, (union data){.i=5})));printf("\n");
    printf("6: ");printf("%d",isChild(t, newElType(0, (union data){.i=6})));printf("\n");
    printf("--------\n");
    printf("CHECK PART OF\n");
    printf("1: %d\n",isPartOf(t, newElType(0, (union data){.i=1})));
    printf("2: %d\n",isPartOf(t, newElType(0, (union data){.i=2})));
    printf("5: %d\n",isPartOf(t, newElType(0, (union data){.i=5})));
    printf("7: %d\n",isPartOf(t, newElType(0, (union data){.i=7})));
    return 0;
}