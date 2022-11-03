/* File: prioqueue.c */
/* Implementasi ADT Priority Queue*/

/* C libraries */
#include <stdio.h>
#include <stdlib.h>

/* ADT */
#include "prioqueue.h"


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

void SetElmtTime(PrioQueue *Q, int idx, Waktu newTime)
{
    // Kamu Lokal
    int pos;
    PQInfoType newElmt;
    Waktu oldTime;
    // Algoritmas
    oldTime = Q->Tab[Q->Head+idx].Time;
    newElmt.Info = Q->Tab[Q->Head+idx].Info;
    newElmt.Time = newTime;
    pos = idx;
    // swap ke depan hingga berada di posisi yang tepat
    while (pos != 0 && IsEarlier(newElmt,Q->Tab[Q->Head+pos-1])){
        Q->Tab[Q->Head+pos] = Q->Tab[Q->Head+pos-1];
        pos--;
    }
    // swap ke belakang hingga berada di posisi yang tepat
    while (pos != LengthPQ(*Q)-1 && IsEarlier(Q->Tab[Q->Head+pos+1],newElmt)){
        Q->Tab[Q->Head+pos] = Q->Tab[Q->Head+pos+1];
        pos++;
    }
    Q->Tab[Q->Head+pos] = newElmt;
    return;
}

boolean IsEarlier(PQInfoType a, PQInfoType b){
    if (a.Time == b.Time){
        return a.Info < b.Info;
    } else return !IsWaktuGreaterEqual(a.Time,b.Time);
}

boolean IsEmptyPQ (PrioQueue Q)
{
    // Kamus Lokal
    // Algoritma
    return Q.Head == PQ_NIL && Q.Tail == PQ_NIL;
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
    Q->Tab = (PQInfoType*) malloc(PQ_DEF_SIZE*sizeof(PQInfoType));
    Q->Head =  PQ_NIL;
    Q->Tail =  PQ_NIL;
    if (Q->Tab != NULL){
        Q->Cap = PQ_DEF_SIZE;
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
    PQInfoType* tmp;
    int i;
    // Algoritma
    if (newCap < Q->Cap){
        for (i = Q->Head;i <= Q->Tail;i++){
            Q->Tab[i-Q->Head] = Q->Tab[i];
        }
        Q->Tail -= Q->Head;
        Q->Head = 0;
    }
    tmp = realloc(Q->Tab,sizeof(PQInfoType)*newCap);
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
    else return PQ_IDX_UNDEF;
}

void Enqueue (PrioQueue * Q, PQElType X, Waktu time)
{
    // Kamus Lokal
    int i,oldCap,newCap,idx;
    PQInfoType newInfo;
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
    while (idx != Q->Head && IsEarlier(newInfo,Q->Tab[idx-1])){
        Q->Tab[idx] = Q->Tab[idx-1];
        idx--;
    }
    Q->Tab[idx] = newInfo;
}
void Dequeue (PrioQueue * Q, PQElType* X, Waktu *time)
{
    // Kamus Lokal
    int i,oldCap,newCap;
    PQInfoType* tmpTab;
    // Algoritma
    *X = GetHeadInfo(*Q);
    *time = GetHeadTime(*Q);

    if (LengthPQ(*Q) == 1){
        Q->Head =  PQ_NIL;
        Q->Tail =  PQ_NIL;
    } else {
        Q->Head++;
        if (Q->Cap !=  PQ_DEF_SIZE && LengthPQ(*Q) <= Q->Cap/4){
            oldCap = Q->Cap;
            newCap = (Q->Cap/2 >  PQ_DEF_SIZE ? Q->Cap/2 :  PQ_DEF_SIZE);
            ReallocatePQ(Q,newCap);
        }
    }
}

void DeleteAtPQ (PrioQueue* Q, PQElType* X, Waktu *time, int idx)
{
    // Kamus Lokal
    int i,oldCap,newCap;
    PQInfoType* tmpTab;
    // Algoritma
    if (idx == 0){
        Dequeue(Q, X, time);
    } else {
        *X = GetElmtInfo(*Q,idx);
        for (i = idx+1+Q->Head;i <= Q->Tail;i++){
            Q->Tab[i-1] = Q->Tab[i];
        }
        Q->Tail--;
        if (Q->Cap !=  PQ_DEF_SIZE && LengthPQ(*Q) <= Q->Cap/4){
            oldCap = Q->Cap;
            newCap = (Q->Cap/2 >  PQ_DEF_SIZE ? Q->Cap/2 :  PQ_DEF_SIZE);
           ReallocatePQ(Q,newCap);
        }
    }
}

void DeleteElmtPQ(PrioQueue* Q, PQElType X, Waktu time)
/* Proses: Menghapus elemen pada Q yang memiliki nilai X dan waktu time */
/* I.S. Q tidak mungkin kosong.*/
/* F.S. Elemen dengan nilai X dan waktu time dihapus, elemen sebelumnya akan dimajukan jika Q tidak menjadi kosong.
        Elemen dapat tidak ditemukan (tidak dilakukan apa-apa). Kapasitas Q akan direalokasikan menjadi setengahnya jika Q sepi,
        yaitu ketika length(Q) <= Q.cap div 4 */
{
    int idx, length, temp;
    Waktu t;
    boolean found;

    found = false;
    idx = 0;
    length =  LengthPQ(*Q);

    while (idx < LengthPQ(*Q) && !found)
    {
        if (Q->Tab[idx].Info == X && Q->Tab[idx].Time == time)
        {
            found = true;
            DeleteAtPQ(Q, &X, &t, idx);
        }

        else
        {
            idx++;
        }
    }
}
void DisplayInfoTypePQ(PQInfoType p){
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
