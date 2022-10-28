/* File: prioqueue.c */
/* Implementasi ADT Priority Queue*/

/* C libraries */
#include <stdio.h>
#include <stdlib.h>

/* ADT */
#include "../headers/prioqueue.h"


PQElType GetHeadInfo(PrioQueue Q)
{
    // Kamus Lokal
    // Algoritma
    return Q.Tab[Q.Head].Info;
}

Waktu GetHeadTime(PrioQueue Q)
{
    // Kamus Lokal
    // Algoritma
    return Q.Tab[Q.Head].Time;
}

PQElType GetElmtInfo(PrioQueue Q,int idx)
{
    // Kamus Lokal
    // Algoritma
    return Q.Tab[Q.Head+idx].Info;
}

Waktu GetElmtTime(PrioQueue Q,int idx)
{
    // Kamus Lokal
    // Algoritma
    return Q.Tab[Q.Head+idx].Time;
}


boolean IsEmptyPQ (PrioQueue Q)
{
    // Kamus Lokal
    // Algoritma
    return Q.Head == Nil && Q.Tail == Nil;
}

boolean IsFullPQ (PrioQueue Q)
{
    // Kamus Lokal
    // Algoritma
    return !IsEmptyPQ(Q) && (Q.Head == 0) && (Q.Tail == Q.Cap-1);
}

int LengthPQ (PrioQueue Q)
{
    // Kamus Lokal
    // Algoritma
    return Q.Tail - Q.Head+1;
}

void CreateEmptyPQ(PrioQueue* Q)
{
    // Kamus Lokal
    // Algoritma
    Q->Tab = (infotype*) malloc(DEF_SIZE*sizeof(infotype));
    Q->Head = Nil;
    Q->Tail = Nil;
    if (Q->Tab != NULL){
        Q->Cap = DEF_SIZE;
    } else {
        printf("Gagal alokasi!");
        Q->Cap = 0;
    }
}


void DeallocatePQ(PrioQueue * Q)
{
    // Kamus Lokal
    // Algoritma
    free(Q->Tab);
    Q->Cap = 0;
}

void ReallocatePQ(PrioQueue * Q, int newCap)
{
    // Kamus Lokal
    infotype* tmp;
    int i;
    // Algoritma
    if (newCap < Q->Cap){
        for (i = Q->Head;i <= Q->Tail;i++){
            Q->Tab[i-Q->Head] = Q->Tab[i];
        }
        Q->Tail -= Q->Head;
        Q->Head = 0;
    }
    tmp = realloc(Q->Tab,sizeof(infotype)*newCap);
    if (tmp != NULL){
        Q->Tab = tmp;
        Q->Cap = newCap;
    } else {
        free(Q->Tab);
        printf("Gagal realokasi!\n");
    }
}

int IndexOfPQ(PrioQueue Q, PQElType X)
{
    // Kamus Lokal
    int i, idx;
    boolean found;
    // Algoritma
    found = false;
    if (!IsEmptyPQ(Q)){
        idx = Q.Head;
        while (idx <= Q.Tail && !found){
            if (Q.Tab[idx].Info == X){
                found = true;
            } else idx++;
        }
    }
    if (found) return idx;
    else return IDX_UNDEF;
}

void Enqueue (PrioQueue * Q, PQElType X, Waktu time)
{
    // Kamus Lokal
    int i,oldCap,newCap,idx;
    infotype newInfo;
    // Algoritma
    newInfo.Info = X;
    newInfo.Time = time;
    if (IsEmptyPQ(*Q)){
        Q->Tail = Q->Head = 0;
    } else if (IsFullPQ(*Q)){
        oldCap = Q->Cap;
        newCap = oldCap*2;
        ReallocatePQ(Q,newCap);
        if (!IsFullPQ(*Q)){
            Q->Tail++;
        } else {
            printf("Gagal realokasi, enqueue dibatalkan...\n");
            return;
        }
    } else {
        if (Q->Tail == Q->Cap-1){
            for (i = Q->Head;i <= Q->Tail;i++){
                Q->Tab[i-Q->Head] = Q->Tab[i];
            }
            Q->Tail -= Q->Head;
            Q->Head = 0;
        }
        Q->Tail++;
    }
    idx = Q->Tail;
    while (idx != Q->Head && !IsWaktuGreaterEqual(newInfo.Time,Q->Tab[idx-1].Time)){
        Q->Tab[idx] = Q->Tab[idx-1];
        idx--;
    }
    Q->Tab[idx] = newInfo;
}
void Dequeue (PrioQueue * Q, PQElType* X)
{
    // Kamus Lokal
    int i,oldCap,newCap;
    infotype* tmpTab;
    // Algoritma
    *X = GetHeadInfo(*Q);
    if (LengthPQ(*Q) == 1){
        Q->Head = Nil;
        Q->Tail = Nil;
    } else {
        Q->Head++;
        if (Q->Cap != DEF_SIZE && LengthPQ(*Q) <= Q->Cap/4){
            oldCap = Q->Cap;
            newCap = (Q->Cap/2 > DEF_SIZE ? Q->Cap/2 : DEF_SIZE);
            ReallocatePQ(Q,newCap);
        }
    }
}

void DeleteAtPQ (PrioQueue* Q, PQElType* X,int idx)
{
    // Kamus Lokal
    int i,oldCap,newCap;
    infotype* tmpTab;
    // Algoritma
    if (idx == 0){
        Dequeue(Q,X);
    } else {
        *X = GetElmtInfo(*Q,idx);
        for (i = idx+1+Q->Head;i <= Q->Tail;i++){
            Q->Tab[i-1] = Q->Tab[i];
        }
        Q->Tail--;
        if (Q->Cap != DEF_SIZE && LengthPQ(*Q) <= Q->Cap/4){
            oldCap = Q->Cap;
            newCap = (Q->Cap/2 > DEF_SIZE ? Q->Cap/2 : DEF_SIZE);
           ReallocatePQ(Q,newCap);
        }
    }
}

void DisplayInfoTypePQ(infotype p){
    // Kamus Lokal
    // Algoritma
    printf("< %d, ",p.Info);
    CetakWaktuLengkap(p.Time);
    printf(">");
}

void DisplayPQ (PrioQueue Q)
{
    // Kamus Lokal
    int i;
    // Algoritma
    printf("--------------\n");
    if (!IsEmptyPQ(Q)){
        for (i = Q.Head;i <= Q.Tail;i++){
            DisplayInfoTypePQ(Q.Tab[i]);
            printf("\n");
        }
    }
    printf("--------------\n");
}
