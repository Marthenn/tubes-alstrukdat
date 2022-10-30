/* C libraries */
#include <stdio.h>

/* ADT */
#include "../headers/tree.h"
#include "../headers/matriks.h"
#include "../headers/makanan.h"
#include "../headers/eltype.h"
#include "../headers/waktu.h"
#include "../headers/point.h"
#include "../headers/wordmachine.h"
#include "../headers/charmachine.h"
#include "../headers/liststatik.h"

/* APP */
#include "../../app/headers/parser.h"

int main(){
    printf("--------\n");
    Tree t = NewTree (1);
    PrintTree(t);printf("\n");
    printf("children t: %d\n",NumberChildren(t));
    printf("--------\n");
    AddChild(&t, 2);
    AddChild(&t, 3);
    AddChild(&t, 4);
    PrintTree(t);printf("\n");
    printf("children t: %d\n",NumberChildren(t));
    printf("--------\n");
    AddChild(&(t->firstChild), 5);
    AddChild(&(t->firstChild), 6);
    PrintTree(t);printf("\n");
    printf("children t: %d\n",NumberChildren(t));
    printf("children t->firstChild: %d\n",NumberChildren(t->firstChild));
    printf("--------\n");
    printf("CHECK CHILDREN\n");
    printf("2: ");printf("%d",IsChild(t, 2));printf("\n");
    printf("3: ");printf("%d",IsChild(t, 3));printf("\n");
    printf("4: ");printf("%d",IsChild(t, 4));printf("\n");
    printf("5: ");printf("%d",IsChild(t, 5));printf("\n");
    printf("6: ");printf("%d",IsChild(t, 6));printf("\n");
    printf("--------\n");
    printf("CHECK PART OF\n");
    printf("1: %d\n",IsPartOf(t, 1));
    printf("2: %d\n",IsPartOf(t, 2));
    printf("5: %d\n",IsPartOf(t, 5));
    printf("7: %d\n",IsPartOf(t, 7));
    printf("--------\n");
    Address p = NewTreeNode(10);
    AddChildNode(&t, p);
    PrintTree(t);printf("\n");
    printf("children t: %d\n",NumberChildren(t));
    printf("--------\n");
    return 0;
}