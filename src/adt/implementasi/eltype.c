#include <stdio.h>
#include "../headers/eltype.h"

ElType newElType(int type, union data val){
    ElType e;
    e.type = type;
    e.val = val;
    return e;
}

int getType(ElType e){
    return e.type;
}

union data getVal(ElType e){
    return e.val;
}

void setVal(ElType *e, union data val){
    e->val = val;
}

void copyElType(ElType *a, ElType b){
    a->type = b.type;
    a->val = b.val;
}

boolean compare(ElType a, ElType b){
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

void printElType(ElType a){
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