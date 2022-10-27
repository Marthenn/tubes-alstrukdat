/* File: prioqueue.c */
/* Implementasi ADT Priority Queue*/

#include <stdio.h>
#include <stdlib.h>
#include "../headers/prioqueue.h"


ElType getHeadInfo(PrioQueue Q)
{
    return Q.Tab[Q.Head].Info;
}

ElType getElmtPQ(PrioQueue Q,int idx)
{
    return Q.Tab[Q.Head+idx].Info;
}


boolean isEmptyPQ (PrioQueue Q)
{
    return Q.Head == Nil && Q.Tail == Nil;
}

boolean isFullPQ (PrioQueue Q)
{
    return !isEmptyPQ(Q) && (Q.Head == 0) && (Q.Tail == Q.Cap-1);
}

int lengthPQ (PrioQueue Q)
{
    return Q.Tail - Q.Head+1;
}

void createEmptyPQ(PrioQueue* Q)
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


void deallocatePQ(PrioQueue * Q)
{
    free(Q->Tab);
    Q->Cap = 0;
}

void reallocatePQ(PrioQueue * Q, int newCap)
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

void enqueue (PrioQueue * Q, ElType X, waktu time)
{
    int i,oldCap,newCap,idx;
    infotype newInfo;
    newInfo.Info = X;
    newInfo.Time = time;
    if (isEmptyPQ(*Q)){
        Q->Tail = Q->Head = 0;
    } else if (isFullPQ(*Q)){
        oldCap = Q->Cap;
        newCap = oldCap*2;
        reallocatePQ(Q,newCap);
        if (!isFullPQ(*Q)){
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
    while (idx != Q->Head && !isWaktuGreaterEqual(newInfo.Time,Q->Tab[idx-1].Time)){
        Q->Tab[idx] = Q->Tab[idx-1];
        idx--;
    }
    Q->Tab[idx] = newInfo;
}
void dequeue (PrioQueue * Q, ElType* X)
{
    int i,oldCap,newCap;
    infotype* tmpTab;
    *X = getHeadInfo(*Q);
    if (lengthPQ(*Q) == 1){
        Q->Head = Nil;
        Q->Tail = Nil;
    } else {
        Q->Head++;
        if (Q->Cap != DEF_SIZE && lengthPQ(*Q) <= Q->Cap/4){
            oldCap = Q->Cap;
            newCap = (Q->Cap/2 > DEF_SIZE ? Q->Cap/2 : DEF_SIZE);
            reallocatePQ(Q,newCap);
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
        *X = getElmtPQ(*Q,idx);
        for (i = idx+1+Q->Head;i <= Q->Tail;i++){
            Q->Tab[i-1] = Q->Tab[i];
        }
        Q->Tail--;
        if (Q->Cap != DEF_SIZE && lengthPQ(*Q) <= Q->Cap/4){
            oldCap = Q->Cap;
            newCap = (Q->Cap/2 > DEF_SIZE ? Q->Cap/2 : DEF_SIZE);
            reallocatePQ(Q,newCap);
        }
    }
}

void displayPQ (PrioQueue Q)
{
    int i;
    printf("┏━━━━━━━━\n");
    if (!isEmptyPQ(Q)){
        for (i = Q.Head;i <= Q.Tail;i++){
            ElType food = Q.Tab[i].Info;
            displayMakanan(food);
            printf("\n");
        }
    }
    printf("┗━━━━━━━━\n");
}
