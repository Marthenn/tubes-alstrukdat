#include <stdio.h>
#include "set.h"

void _assert(boolean x, char ID[]){
    if(!x)printf("ASSERT FAILED AT ID: %s\n", ID);
}

int main(){
    Set s1, s2;
    CreateSet(&s1);CreateSet(&s2);
    _assert(IsSetEmpty(s1), "1");
    _assert(IsSetEmpty(s2), "2");
    _assert(!IsSetFull(s1), "3");
    _assert(!IsSetFull(s2), "4");
    _assert(Length(s1) == 0, "5");
    _assert(Length(s2) == 0, "6");
    SetAdd(&s1, 1, 5);
    _assert(Length(s1) == 1, "7");
    _assert(!IsSetEmpty(s1), "8");
    _assert(IsMember(s1, 1), "9");
    _assert(!IsMember(s1, 2), "10");
    SetAdd(&s1, 2, 5);
    SetAdd(&s1, 3, 5);
    SetAdd(&s1, 4, 5);
    SetAdd(&s2, 7, 5);
    Set s3 = UnionSet(s1, s2);
    PrintSet(s1);printf("\n");PrintSet(s2);printf("\n");PrintSet(s3);printf("\n");
    _assert(Length(s3) == 5, "11");
    Set s4 = Intersection(s1, s2);
    PrintSet(s4);printf("\n");
    _assert(Length(s4) == 0, "12");
    Set s5 = Difference(s3, s1);
    PrintSet(s5);printf("\n");
    _assert(Length(s5) == 1, "13");
    Set s6 = Difference(s3, s2);
    PrintSet(s6);printf("\n");
    _assert(Length(s6) == 4, "14");
    _assert(IsSubset(s1,s3), "15");
    _assert(IsSubset(s2,s3), "16");
    _assert(IsSubset(s1,s6), "17");
    _assert(!IsSubset(s1,s5), "18");
    CopySet(&s2, s1);
    _assert(IsSubset(s1, s2), "19");
    _assert(IsSubset(s2, s1), "20");
    RemoveSet(&s1, 1, 5);
    _assert(Length(s1) == 3, "21");
    RemoveSet(&s1, 2, 3);
    _assert(Length(s1) == 3, "22");
    SetId(&s1, 1);
    _assert(GetSetId(s1) == 1, "23");
}