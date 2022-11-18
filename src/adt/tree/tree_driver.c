/* C libraries */
#include <stdio.h>

/* ADT */
#include "tree.h"

/* APP */
#include "../../app/parser/parser.h"

void _assert(boolean x, char ID[]){
    if(!x)printf("ASSERT FAILED AT ID: %s\n", ID);
}

int main(){
    Tree t1 = NewTree(1);
    Tree t2 = NewTree(2);
    Tree t3;
    _assert(NumberChildren(t1) == 0, "1");
    _assert(NumberChildren(t2) == 0, "2");
    AddChild(&t1, 3, &t3);
    _assert(NumberChildren(t1) == 1, "3");
    AddChild(&t1, 4, &t3);
    _assert(NumberChildren(t1) == 2, "4");
    AddChild(&t2, 5, &t3);
    _assert(NumberChildren(t2) == 1, "5");
    AddChild(&t2, 6, &t3);
    _assert(NumberChildren(t2) == 2, "6");
    AddChildNode(&t1, t2);
    _assert(NumberChildren(t1) == 3, "7");
    PrintTree(t1);
    _assert(IsChild(t1, 2), "8");
    _assert(IsChild(t1, 3), "9");
    _assert(IsChild(t1, 4), "10");
    _assert(!IsChild(t1, 5), "11");
    _assert(IsPartOf(t1, 1), "12");
    _assert(IsPartOf(t1, 2), "13");
    _assert(IsPartOf(t1, 3), "14");
    _assert(IsPartOf(t1, 4), "15");
    _assert(IsPartOf(t1, 5), "16");
    _assert(IsPartOf(t1, 6), "17");
    _assert(!IsPartOf(t1, 7), "18");
    _assert(!IsPartOf(t1, 8), "19");
    _assert(NumberChildren(GetSubTree(t1, 2)) == 2, "20");
    _assert(NumberChildren(GetSubTree(t1, 3)) == 0, "21");
    ListDin l = GetChildren(t1);
    _assert(ListDinLength(l) == 3, "22");
    PrintListDin(l);
    return 0;
}