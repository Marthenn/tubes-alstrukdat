/* File: prioqueue.c */
/* Implementasi ADT Priority Queue*/

/* C libraries */
#include <stdio.h>
#include <stdlib.h>

/* ADT */
#include "../headers/prioqueue.h"


ElType GetHeadInfo(PrioQueue Q)
{
    return Q.Tab[Q.Head].Info;
}

ElType GetElmtPQ(PrioQueue Q,int idx)
{
    return Q.Tab[Q.Head+idx].Info;
}


boolean IsEmptyPQ (PrioQueue Q)
{
    return Q.Head == Nil && Q.Tail == Nil;
}

boolean IsFullPQ (PrioQueue Q)
{
    return !isEmptyPQ(Q) && (Q.Head == 0) && (Q.Tail == Q.Cap-1);
}

int LengthPQ (PrioQueue Q)
{
    return Q.Tail - Q.Head+1;
}

void CreateEmptyPQ(PrioQueue* Q)
{
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
    free(Q->Tab);
    Q->Cap = 0;
}

void ReallocatePQ(PrioQueue * Q, int newCap)
{
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

void Enqueue (PrioQueue * Q, ElType X, Waktu time)
{
    int i,oldCap,newCap,idx;
    infotype newInfo;
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
void Dequeue (PrioQueue * Q, ElType* X)
{
    int i,oldCap,newCap;
    infotype* tmpTab;
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

void deleteAtPQ(PrioQueue* Q, ElType* X,int idx)
{
    int i,oldCap,newCap;
    infotype* tmpTab;
    if (idx == 0){
        dequeue(Q,X);
    } else {
        *X = GetElmtPQ(*Q,idx);
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

void DisplayPQ (PrioQueue Q)
{
    int i;
    printf("┏━━━━━━━━\n");
    if (!IsEmptyPQ(Q)){
        for (i = Q.Head;i <= Q.Tail;i++){
            ElType food = Q.Tab[i].Info;
            DisplayMakanan(food);
            printf("\n");
        }
    }
    printf("┗━━━━━━━━\n");
}
