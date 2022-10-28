/* C libraries */
#include <stdio.h>

/* ADT */
#include "../headers/prioqueue.h"
#include "../headers/eltype.h"

/* APP */
#include "../../app/headers/parser.h"

#define strbol(x) (x) ? "True\n" : "False\n"

int main(){
    // Kamus
    PrioQueue Q;
    ElType tmp;
    int i;
    // Algoritma
    printf("Membuat queue kosong...\n");
    CreateEmptyPQ(&Q);
    printf("****** Cek IsEmptyPQ dan isFullPQ ******\n");
    printf(strbol(IsEmptyPQ(Q)));
    printf(strbol(IsFullPQ(Q)));
    printf("****** Cek DisplayPQ ******\n");
    DisplayPQ(Q);
    printf("****** Cek Enqueue ******\n");
    for (i = 0;i < 4;i++){
        Enqueue(&Q,NewElType(0,(union Data){.i=i}),i);
    }
    DisplayPQ(Q);
    printf("****** Cek getter ******\n");
    PrintElType(GetHeadInfo(Q)); printf("\n");
    PrintElType(GetElmtPQ(Q,LengthPQ(Q)-1)); printf("\n");
    printf("****** Cek Length ******\n");
    printf("Length : %d\n",LengthPQ(Q));
    printf("****** Cek dequeue ******\n");

    Dequeue(&Q,&tmp);
    PrintElType(tmp); printf("\n");
    DisplayPQ(Q);
    printf("****** Cek sifat queue yang tetap ketika enque dan deque dilakukan bergantian ******\n");
    for (i = 0;i < 20;i++){
        Enqueue(&Q,NewElType(0,(union Data){.i=0}),0);
        Dequeue(&Q,&tmp);
    }
    DisplayPQ(Q);
    printf("Mengosongkan queue...\n");
    while (!IsEmptyPQ(Q)){
        Dequeue(&Q,&tmp);
    }
    DisplayPQ(Q);
    printf("****** Uji Q ketika full ******\n");
    printf("Mengisi queue hingga penuh...\n");
    for (i = 0;i < Q.Cap;i++){
        Enqueue(&Q,NewElType(0,(union Data){.i=i}),i);    
    }
    printf(strbol(IsFullPQ(Q)));
    printf("****** Cek realokasi jika queue tidak muat ******\n");
    printf("Capacity : %d\n",Q.Cap);
    Enqueue(&Q,NewElType(0,(union Data){.i=20}),20);
    printf("Capacity : %d\n",Q.Cap);
    for (i = 0;i < 40;i++){
        Enqueue(&Q,NewElType(0,(union Data){.i=21+i}),21+i);    
    }
    printf("Capacity : %d\n",Q.Cap);
    printf("****** Cek deleteAt ******\n");
    DeleteAtPQ(&Q,&tmp,4);
    PrintElType(tmp); printf("\n");
    printf("****** Cek realokasi jika queue sepi ******\n");
    printf("Capacity awal : %d\n",Q.Cap);
    while (LengthPQ(Q) > 20){
        Dequeue(&Q,&tmp);
    }
    printf("Capacity akhir : %d\n",Q.Cap);

}