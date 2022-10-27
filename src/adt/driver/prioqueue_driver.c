#include <stdio.h>
#include "../headers/prioqueue.h"
#include "../headers/makanan.h"
#include "../headers/parser.h"

#define strbol(x) (x) ? "True\n" : "False\n"

makanan newDummy(int id,int mKadar,int mKirim)
/* Membuat makanan untuk dijadikan komponen queue*/
{
    // Kamus Lokal
    makanan tmp;
    waktu kirim, kadar;
    point p;
    Word name = NewWord("-",1);
    // Algoritma
    createPoint(&p,0,0);
    createWaktu(&kadar,0,0,mKadar);
    createWaktu(&kirim,0,0,mKirim);
    createMakanan(&tmp,id,name,kadar,kirim,p);
    return tmp;
}

int main(){
    // Kamus
    PrioQueue Q;
    makanan tmp;
    int i;
    // Algoritma
    createEmptyPQ(&Q);
    printf("****** Cek isEmptyPQ dan isFullPQ ******\n");
    printf(strbol(isEmptyPQ(Q)));
    printf(strbol(isFullPQ(Q)));
    printf("****** Cek displayPQ ******\n");
    displayPQ(Q);
    printf("****** Cek enqueue ******\n");
    for (i = 0;i < 4;i++){
        enqueue(&Q,newDummy(i,i,3-i),i);
    }
    displayPQ(Q);
    printf("****** Cek getter ******\n");
    displayMakanan(getHeadInfo(Q));
    displayMakanan(getElmtPQ(Q,lengthPQ(Q)-1));
    printf("****** Cek length ******\n");
    printf("length : %d\n",lengthPQ(Q));
    printf("****** Cek dequeue ******\n");

    dequeue(&Q,&tmp);
    displayMakanan(tmp);
    displayPQ(Q);
    printf("****** Cek sifat queue yang tetap ketika enque dan deque dilakukan bergantian ******\n");
    for (i = 0;i < 20;i++){
        enqueue(&Q,newDummy(-1,0,0),0);
        dequeue(&Q,&tmp);
    }
    displayPQ(Q);
    printf("Mengosongkan queue...\n");
    while (!isEmptyPQ(Q)){
        dequeue(&Q,&tmp);
    }
    displayPQ(Q);
    printf("****** Uji Q ketika full ******\n");
    printf("Mengisi queue hingga penuh...\n");
    for (i = 0;i < Q.Cap;i++){
        enqueue(&Q,newDummy(i,0,0),0);    
    }
    printf(strbol(isFullPQ(Q)));
    printf("****** Cek realokasi jika queue tidak muat ******\n");
    printf("Capacity : %d\n",Q.Cap);
    enqueue(&Q,newDummy(20,0,0),0);
    printf("Capacity : %d\n",Q.Cap);
    for (i = 0;i < 40;i++){
        enqueue(&Q,newDummy(i,0,0),0);    
    }
    printf("Capacity : %d\n",Q.Cap);
    printf("****** Cek deleteAt ******\n");
    deleteAtPQ(&Q,&tmp,4);
    displayMakanan(tmp);
    printf("****** Cek realokasi jika queue sepi ******\n");
    printf("Capacity awal : %d\n",Q.Cap);
    while (lengthPQ(Q) > 20){
        dequeue(&Q,&tmp);
    }
    printf("Capacity akhir : %d\n",Q.Cap);

}