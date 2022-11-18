/* C libraries */
#include <stdio.h>

/* ADT */
#include "eltype.h"
/* APP */
#include "../../app/parser/parser.h"

void _assert(boolean x, char ID[]){
    if(!x)printf("ASSERT FAILED AT ID: %s\n", ID);
}

int main(){
    ElType e1 = NewElType(0, (union Data){.i = 1});
    ElType e2 = NewElType(0, (union Data){.i = 2});
    ElType e3 = NewElType(0, (union Data){.i = 3});
    _assert(GetType(e1) == 0, "TYPE INT");
    _assert(GetType(e2) == 0, "TYPE INT");
    _assert(GetType(e3) == 0, "TYPE INT");

    _assert(GetVal(e1).i == 1, "VAL INT");
    _assert(GetVal(e2).i == 2, "VAL INT");
    _assert(GetVal(e3).i == 3, "VAL INT");

    SetVal(&e3, 0, (union Data){.i = 4});
    _assert(GetVal(e3).i == 4, "VAL INT AFTER SET");

    CopyElType(&e1, e3);
    _assert(GetVal(e1).i == 4, "VAL INT AFTER COPY");
    _assert(Compare(e1, e3), "COMPARE INT");
    _assert(!Compare(e1, e2), "COMPARE INT");

    printf("TEST PASSED FOR INT\n");
    PrintElType(e1);PrintElType(e2);PrintElType(e3);printf("\n");

    ElType e4 = NewElType(1, (union Data){.f = 1.0});
    ElType e5 = NewElType(1, (union Data){.f = 2.0});
    ElType e6 = NewElType(1, (union Data){.f = 3.0});
    _assert(GetType(e4) == 1, "TYPE FLOAT");
    _assert(GetType(e5) == 1, "TYPE FLOAT");
    _assert(GetType(e6) == 1, "TYPE FLOAT");

    _assert(GetVal(e4).f == 1.0, "VAL FLOAT");
    _assert(GetVal(e5).f == 2.0, "VAL FLOAT");
    _assert(GetVal(e6).f == 3.0, "VAL FLOAT");

    SetVal(&e6, 1, (union Data){.f = 4.0});
    _assert(GetVal(e6).f == 4.0, "VAL FLOAT AFTER SET");

    CopyElType(&e4, e6);
    _assert(GetVal(e4).f == 4.0, "VAL FLOAT AFTER COPY");
    _assert(Compare(e4, e6), "COMPARE FLOAT");
    _assert(!Compare(e4, e5), "COMPARE FLOAT");

    printf("TEST PASSED FOR FLOAT\n");
    PrintElType(e4);PrintElType(e5);PrintElType(e6);printf("\n");

    ElType e7 = NewElType(2, (union Data){.c = 'a'});
    ElType e8 = NewElType(2, (union Data){.c = 'b'});
    ElType e9 = NewElType(2, (union Data){.c = 'c'});
    _assert(GetType(e7) == 2, "TYPE CHAR");
    _assert(GetType(e8) == 2, "TYPE CHAR");
    _assert(GetType(e9) == 2, "TYPE CHAR");

    _assert(GetVal(e7).c == 'a', "VAL CHAR");
    _assert(GetVal(e8).c == 'b', "VAL CHAR");
    _assert(GetVal(e9).c == 'c', "VAL CHAR");

    SetVal(&e9, 2, (union Data){.c = 'd'});
    _assert(GetVal(e9).c == 'd', "VAL CHAR AFTER SET");

    CopyElType(&e7, e9);
    _assert(GetVal(e7).c == 'd', "VAL CHAR AFTER COPY");
    _assert(Compare(e7, e9), "COMPARE CHAR");
    _assert(!Compare(e7, e8), "COMPARE CHAR");

    printf("TEST PASSED FOR CHAR\n");
    PrintElType(e7);PrintElType(e8);PrintElType(e9);printf("\n");

    Waktu w1, w2, w3;
    CreateWaktu(&w1, 1, 1, 1);
    CreateWaktu(&w2, 2, 2, 2);
    CreateWaktu(&w3, 3, 3, 3);
    Point p1, p2, p3;
    CreatePoint(&p1, 1, 1);
    CreatePoint(&p2, 2, 2);
    CreatePoint(&p3, 3, 3);
    Word wd1, wd2, wd3;
    wd1.Length = 1; wd1.TabWord[0] = 'a';
    wd2.Length = 2; wd2.TabWord[0] = 'b'; wd2.TabWord[1] = 'b';
    wd3.Length = 3; wd3.TabWord[0] = 'c'; wd3.TabWord[1] = 'c'; wd3.TabWord[2] = 'c';
    Makanan m1, m2, m3;
    CreateMakanan(&m1, 1, wd1, w1, w1, wd3, p1, 0, 0);
    CreateMakanan(&m2, 2, wd2, w2, w2, wd1, p2, 0, 0);
    CreateMakanan(&m3, 3, wd3, w3, w3, wd2, p3, 0, 0);
    ElType e10 = NewElType(3, (union Data){.m = m1});
    ElType e11 = NewElType(3, (union Data){.m = m2});
    ElType e12 = NewElType(3, (union Data){.m = m3});

    _assert(GetType(e10) == 3, "TYPE MAKANAN");
    _assert(GetType(e11) == 3, "TYPE MAKANAN");
    _assert(GetType(e12) == 3, "TYPE MAKANAN");

    _assert(GetVal(e10).m.Id == 1, "VAL MAKANAN");
    _assert(GetVal(e11).m.Id == 2, "VAL MAKANAN");
    _assert(GetVal(e12).m.Id == 3, "VAL MAKANAN");

    SetVal(&e12, 3, (union Data){.m = m1});
    _assert(GetVal(e12).m.Id == 1, "VAL MAKANAN AFTER SET");

    CopyElType(&e10, e12);
    _assert(GetVal(e10).m.Id == 1, "VAL MAKANAN AFTER COPY");
    _assert(Compare(e10, e12), "COMPARE MAKANAN");
    _assert(!Compare(e10, e11), "COMPARE MAKANAN");

    printf("TEST PASSED FOR MAKANAN\n");
    PrintElType(e10);PrintElType(e11);PrintElType(e12);printf("\n");

    ElType e13 = NewElType(4, (union Data){.w = wd1});
    ElType e14 = NewElType(4, (union Data){.w = wd2});
    ElType e15 = NewElType(4, (union Data){.w = wd3});
    _assert(GetType(e13) == 4, "TYPE WORD");
    _assert(GetType(e14) == 4, "TYPE WORD");
    _assert(GetType(e15) == 4, "TYPE WORD");

    _assert(GetVal(e13).w.Length == 1, "VAL WORD");
    _assert(GetVal(e14).w.Length == 2, "VAL WORD");
    _assert(GetVal(e15).w.Length == 3, "VAL WORD");

    SetVal(&e15, 4, (union Data){.w = wd1});
    _assert(GetVal(e15).w.Length == 1, "VAL WORD AFTER SET");

    CopyElType(&e13, e15);
    _assert(GetVal(e13).w.Length == 1, "VAL WORD AFTER COPY");

    _assert(Compare(e13, e15), "COMPARE WORD");
    _assert(!Compare(e13, e14), "COMPARE WORD");

    printf("TEST PASSED FOR WORD\n");
    PrintElType(e13);PrintElType(e14);PrintElType(e15);printf("\n");

    Tree T1 = NewTree(30);
    Tree T2 = NewTree(20);
    Tree T3 = NewTree(10);
    ElType e16 = NewElType(5, (union Data){.t = T1});
    ElType e17 = NewElType(5, (union Data){.t = T2});
    ElType e18 = NewElType(5, (union Data){.t = T3});

    _assert(GetType(e16) == 5, "TYPE TREE");
    _assert(GetType(e17) == 5, "TYPE TREE");
    _assert(GetType(e18) == 5, "TYPE TREE");

    _assert(GetVal(e16).t->info == 30, "VAL TREE");
    _assert(GetVal(e17).t->info == 20, "VAL TREE");
    _assert(GetVal(e18).t->info == 10, "VAL TREE");

    SetVal(&e18, 5, (union Data){.t = T1});
    _assert(GetVal(e18).t->info == 30, "VAL TREE AFTER SET");

    CopyElType(&e16, e18);
    _assert(GetVal(e16).t->info == 30, "VAL TREE AFTER COPY");

    _assert(Compare(e16, e18), "COMPARE TREE");
    _assert(!Compare(e16, e17), "COMPARE TREE");

    printf("TEST PASSED FOR TREE\n");
    PrintElType(e16);PrintElType(e17);PrintElType(e18);printf("\n");

    MakananKulkas mk1, mk2, mk3;
    mk1.makanan= m1; mk1.kiriAtas = p1; mk1.rotated = false; mk1.idx = 0;
    mk2.makanan= m2; mk2.kiriAtas = p2; mk2.rotated = true; mk2.idx = 2;
    mk3.makanan= m3; mk3.kiriAtas = p3; mk3.rotated = false; mk3.idx = 4;

    ElType e19 = NewElType(6, (union Data){.mk = mk1});
    ElType e20 = NewElType(6, (union Data){.mk = mk2});
    ElType e21 = NewElType(6, (union Data){.mk = mk3});

    _assert(GetType(e19) == 6, "TYPE MAKANAN KULKAS");
    _assert(GetType(e20) == 6, "TYPE MAKANAN KULKAS");
    _assert(GetType(e21) == 6, "TYPE MAKANAN KULKAS");

    _assert(GetVal(e19).mk.makanan.Id == 1, "VAL MAKANAN KULKAS");
    _assert(GetVal(e20).mk.makanan.Id == 2, "VAL MAKANAN KULKAS");
    _assert(GetVal(e21).mk.makanan.Id == 3, "VAL MAKANAN KULKAS");

    SetVal(&e21, 6, (union Data){.mk = mk1});
    _assert(GetVal(e21).mk.makanan.Id == 1, "VAL MAKANAN KULKAS AFTER SET");

    CopyElType(&e19, e21);
    _assert(GetVal(e19).mk.makanan.Id == 1, "VAL MAKANAN KULKAS AFTER COPY");

    _assert(Compare(e19, e21), "COMPARE MAKANAN KULKAS");
    _assert(!Compare(e19, e20), "COMPARE MAKANAN KULKAS");

    printf("TEST PASSED FOR MAKANAN KULKAS\n");
    PrintElType(e19);PrintElType(e20);PrintElType(e21);printf("\n");

    Set s1, s2, s3;
    CreateSet(&s1); CreateSet(&s2); CreateSet(&s3);
    SetAdd(&s1, 1, 1); SetAdd(&s1, 2, 1); SetAdd(&s1, 3, 1);

    ElType e22 = NewElType(7, (union Data){.s = s1});
    ElType e23 = NewElType(7, (union Data){.s = s2});
    ElType e24 = NewElType(7, (union Data){.s = s3});

    _assert(GetType(e22) == 7, "TYPE SET");
    _assert(GetType(e23) == 7, "TYPE SET");
    _assert(GetType(e24) == 7, "TYPE SET");

    _assert(GetVal(e22).s.data[0].val == 1, "VAL SET");
    _assert(GetVal(e23).s.data[0].val == 2, "VAL SET");
    _assert(GetVal(e24).s.data[0].val == 3, "VAL SET");

    SetVal(&e24, 7, (union Data){.s = s1});
    _assert(GetVal(e24).s.data[0].val == 1, "VAL SET AFTER SET");

    CopyElType(&e22, e24);
    _assert(GetVal(e22).s.data[0].val == 1, "VAL SET AFTER COPY");

    _assert(Compare(e22, e24), "COMPARE SET");
    _assert(!Compare(e22, e23), "COMPARE SET");

    printf("TEST PASSED FOR SET\n");
    PrintElType(e22);PrintElType(e23);PrintElType(e24);printf("\n");

    printf("TEST PASSED FOR ALL\n");
    return 0;
}