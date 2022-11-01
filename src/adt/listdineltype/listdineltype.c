#include <stdio.h>
#include <stdlib.h>
#include "listdineltype.h"

void CreateListDinElType(ListDinElType *L, int capacity){
    // KAMUS LOKAL
    int cap;
    // ALGORITMA
    
    cap = LISTDIN_ELTYPE_MIN_CAP > capacity? LISTDIN_ELTYPE_MIN_CAP : capacity;
    L->buffer = (ElType*) malloc(cap * sizeof(ElType));

    L->capacity = cap;
    L->nEff = 0;
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

    if (IsListDinElTypeFull(*L))
    {
        ExpandListDinElType(L);
    }
    
    for(i = L->nEff; i > 0; i--){
        L->buffer[i] = L->buffer[i-1];
    }

    L->buffer[0] = e;
    L->nEff++;
    
}

void InsertLastListDinElType(ListDinElType *L, ElType e){

    if (IsListDinElTypeFull(*L))
    {
        ExpandListDinElType(L);
    }

    L->buffer[L->nEff] = e;
    L->nEff++;

}

void DeleteFirstListDinElType(ListDinElType *L, ElType *e)
{

    int i;

    *e = L->buffer[0];
    
    for (i = 0; i < ListDinElTypeLength(*L) - 1; i++)
    {
        L->buffer[i] = L->buffer[i+1];
    }

    L->nEff--;

    if (ListDinElTypeLength(*L) <= L->capacity / 4)
    {
        ShrinkListDinElType(L);
    }
}

void DeleteLastListDinElType(ListDinElType *L, ElType *e)
{

    L->nEff--;
    *e = L->buffer[ListDinElTypeLength(*L)];

    if (ListDinElTypeLength(*L) <= L->capacity / 4)
    {
        ShrinkListDinElType(L);
    }
}

void ExpandListDinElType(ListDinElType *L){

    int newCap = L->capacity * 3 / 2;
    if (newCap == L->capacity)
    {
        newCap++;
    }

    L->buffer = (ElType*) realloc(L->buffer, newCap * sizeof(ElType));

    L->capacity = newCap;
}

void ShrinkListDinElType(ListDinElType *L){
    // KAMUS LOKAL
    int newCap;
    // ALGORITMA
    
    newCap = (LISTDIN_ELTYPE_MIN_CAP > L->capacity / 2)? LISTDIN_ELTYPE_MIN_CAP : L->capacity / 2;

    L->capacity =  newCap;

    L->buffer = (ElType*) realloc(L->buffer, newCap * sizeof(ElType));
    // L->nEff = ((L->capacity) < (L->nEff))? (L->capacity) : (L->nEff);
}

void CompressListDinElType(ListDinElType *L){
    // KAMUS LOKAL
    int newCap;
    // ALGORITMA
    
    newCap = (LISTDIN_ELTYPE_MIN_CAP > L->capacity)? LISTDIN_ELTYPE_MIN_CAP : L->nEff;

    L->capacity =  newCap;

    L->buffer = (ElType*) realloc(L->buffer, newCap * sizeof(ElType));
}