#include <stdio.h>
#include "../headers/eltype.h"

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

void SetVal(ElType *e, union Data val){
    e->val = val;
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
        }
    }else{
        return false;
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
        default:
            printf("undefined");
            break;
    }
}