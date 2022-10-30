#include <stdio.h>
#include <stdlib.h>
#include "../headers/listdineltype.h"

void CreateListDinElType(ListDinElType *L, int capacity){
    (*L).buffer = (ElType*) malloc(capacity * sizeof(ElType));
    (*L).capacity = capacity;
    (*L).nEff = 0;
}

void DeallocateListDinElType(ListDinElType *L){
    (*L).capacity = 0;
    (*L).nEff = 0;
    free((*L).buffer);
}

int ListDinElTypeLength(ListDinElType L){
    return L.nEff;
}

boolean IsListDinElTypeEmpty(ListDinElType L){
    return L.nEff == 0;
}

boolean IsListDinElTypeFull(ListDinElType L){
    return L.nEff == L.capacity;
}

boolean IsListDinElTypeIdxValid(ListDinElType L, int index){
    return index >= 0 && index < L.capacity;
}

boolean IsListDinElTypeIdxEff(ListDinElType L, int index){
    return index >= 0 && index <= L.nEff;
}

void PrintListDinElType(ListDinElType L){
    printf("[");
    int i;
    for(i = 0; i < L.nEff; i++){
        PrintElType(L.buffer[i]);
        if(i != L.nEff - 1){
            printf(", ");
        }
    }
    printf("]");
}

int ListDinElTypeIdxOf(ListDinElType L, ElType e){
    int i;
    for(i = 0; i < L.nEff; i++){
        if(Compare(L.buffer[i], e)){
            return i;
        }
    }
    return -1;
}

void InsertFirstListDinElType(ListDinElType *L, ElType e){
    int i;
    if(!IsListDinElTypeFull(*L)){
        for(i = L->nEff; i > 0; i--){
            L->buffer[i] = L->buffer[i-1];
        }
        L->buffer[0] = e;
        L->nEff++;
    }
}

void InsertLastListDinElType(ListDinElType *L, ElType e){
    if(!IsListDinElTypeFull(*L)){
        L->buffer[L->nEff] = e;
        L->nEff++;
    }
}

void ExpandListDinElType(ListDinElType *L){
    ElType *temp = (ElType*) malloc(1.5 * L->capacity * sizeof(ElType));
    int i;
    for(i = 0; i < L->nEff; i++){
        temp[i] = L->buffer[i];
    }
    free(L->buffer);
    L->buffer = temp;
    L->capacity = 1.5 * L->capacity;
}

void ShrinkListDinElType(ListDinElType *L){
    ElType *temp = (ElType*) malloc(0.5 * L->capacity * sizeof(ElType));
    L->capacity = 0.5 * L->capacity;
    int i;
    for(i = 0; i < L->nEff && i<L->capacity; i++){
        temp[i] = L->buffer[i];
    }
    free(L->buffer);
    L->buffer = temp;
    L->nEff = L->capacity<L->nEff?L->capacity:L->nEff;
}

void CompressListDinElType(ListDinElType *L){
    ElType *temp = (ElType*) malloc(L->nEff * sizeof(ElType));
    int i;
    for(i = 0; i < L->nEff; i++){
        temp[i] = L->buffer[i];
    }
    free(L->buffer);
    L->buffer = temp;
    L->capacity = L->nEff;
}