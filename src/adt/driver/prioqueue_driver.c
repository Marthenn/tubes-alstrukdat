/* C libraries */
#include <stdio.h>
#include <stdlib.h>

/* ADT */
#include "../headers/prioqueue.h"
#include "../headers/eltype.h"

/* APP */
#include "../../app/headers/parser.h"

#define strbol(x) (x) ? "True\n" : "False\n"

int main(){
    // Kamus
    PrioQueue Q;
    int tmp;
    int i;
    // Algoritma
    printf("Membuat queue kosong...\n");
    CreateEmptyPQ(&Q);
    printf("****** Cek IsEmptyPQ dan IsFullPQ ******\n");
    printf(strbol(IsEmptyPQ(Q)));
    printf(strbol(IsFullPQ(Q)));
    printf("****** Cek DisplayPQ ******\n");
    DisplayPQ(Q);
    printf("****** Cek Enqueue ******\n");
    Enqueue(&Q,7,2);
    Enqueue(&Q,5,3);
    Enqueue(&Q,8,1);
    Enqueue(&Q,5,7);
    Enqueue(&Q,7,3);
    Enqueue(&Q,1,3);
    DisplayPQ(Q);
    printf("****** Cek Getter ******\n");
    printf("Head : %d\n",GetHeadInfo(Q));
    printf("Time : "); CetakWaktuLengkap(GetHeadTime(Q)); printf("\n");
    printf("Elemen indeks ke-2 : %d\n",GetElmtInfo(Q,2));
    printf("Time : "); CetakWaktuLengkap(GetElmtTime(Q,2)); printf("\n");
    printf("****** Cek Setter ******\n");
    printf("Ubah Time indeks ke-3 menjadi 0\n");
    SetElmtTime(&Q,3,0);
    DisplayPQ(Q);
    printf("Ubah Time indeks ke-0 menjadi 3\n");
    SetElmtTime(&Q,0,3);
    DisplayPQ(Q);
    printf("****** Cek Length ******\n");
    printf("Length : %d\n",LengthPQ(Q));
    printf("****** Cek IndexOf ******\n");
    printf("5 pertama berada pada indeks ke-%d\n",IndexOfPQ(Q,5));
    printf("****** Cek Dequeue ******\n");
    Dequeue(&Q,&tmp);
    printf("%d\n",tmp);
    DisplayPQ(Q);
    printf("****** Cek sifat queue yang tetap ketika enque ke Head dan deque dilakukan bergantian ******\n");
    for (i = 0;i < 20;i++){
        Enqueue(&Q,-1,0);
        Dequeue(&Q,&tmp);
    }
    DisplayPQ(Q);
    printf("****** Cek DeleteAt ******\n");
    printf("Hapus Elemen ke-2\n");
    DeleteAtPQ(&Q,&tmp,2);
    printf("Hapus %d\n",tmp);
    DisplayPQ(Q);
    printf("Mengosongkan queue...\n");
    while (!IsEmptyPQ(Q)){
        Dequeue(&Q,&tmp);
    }
    DisplayPQ(Q);
    printf("****** Uji Q ketika full ******\n");
    printf("Mengisi queue hingga penuh...\n");
    for (i = 0;i < Q.Cap;i++){
        Enqueue(&Q,i,i);    
    }
    printf(strbol(IsFullPQ(Q)));
    printf("****** Cek realokasi jika queue tidak muat ******\n");
    printf("Capacity : %d\n",Q.Cap);
    Enqueue(&Q,20,20);
    printf("Capacity : %d\n",Q.Cap);
    for (i = 0;i < 40;i++){
        Enqueue(&Q,21+i,21+i);    
    }
    printf("Capacity : %d\n",Q.Cap);
    printf("****** Cek realokasi jika queue sepi ******\n");
    printf("Capacity : %d\n",Q.Cap);
    while (LengthPQ(Q) > 20){
        Dequeue(&Q,&tmp);
    }
    printf("Capacity : %d\n",Q.Cap);
        while (LengthPQ(Q) > 10){
        Dequeue(&Q,&tmp);
    }
    printf("Capacity : %d\n",Q.Cap);
}