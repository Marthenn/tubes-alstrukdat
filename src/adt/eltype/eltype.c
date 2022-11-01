/* C libraries */
#include <stdio.h>

/* ADT */
#include "eltype.h"
#include "../liststatik/liststatik.h"

/* APP */
#include "../../app/parser/parser.h"

ElType NewElType(int type, union Data val){
    ElType e;
    e.type = type;
    e.val = val;
    return e;
}

int GetType(ElType e){
    return e.type;
}

union Data GetVal(ElType e){
    return e.val;
}

void SetVal(ElType *e, int type, union Data val){
    e->val = val;
    e->type = type;
}

void CopyElType(ElType *a, ElType b){
    a->type = b.type;
    a->val = b.val;
}

boolean Compare(ElType a, ElType b){
    if(a.type==b.type){
        switch(a.type){
            case 0:
                return a.val.i==b.val.i;
                break;
            case 1:
                return a.val.f==b.val.f;
                break;
            case 2:
                return a.val.c==b.val.c;
                break;
            case 3:
                return GetIDMakanan(a.val.m)==GetIDMakanan(b.val.m);
                break;
            case 4:
                return IsWordEqual(a.val.w, b.val.w);
            case 5:
                return (a.val.t == b.val.t);
        }

    }else{
        switch(a.type)
        {
            case 3:
                switch (b.type)
                {
                case 0:
                    return ((a.val.m).Id == b.val.i);
                    break;
                
                default:
                    return false;
                    break;
                }

            case 5:
                switch (b.type)
                {
                case 0:
                    return ((a.val.t)->info == b.val.i);
                    break;
                
                default:
                    return false;
                    break;
                }
            default:
                return false;
        }
    }
}

void PrintElType(ElType a){
    switch(a.type){
        case 0:
            printf("%d",a.val.i);
            break;
        case 1:
            printf("%f",a.val.f);
            break;
        case 2:
            printf("%c",a.val.c);
            break;
        case 3:
            DisplayMakanan(a.val.m);
            break;
        case 4:
            DisplayWord(a.val.w);
            break;
        case 5:
            PrintTree(a.val.t);
            break;
        default:
            printf("undefined");
            break;
    }
}