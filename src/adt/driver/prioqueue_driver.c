#include <stdio.h>
#include "../headers/prioqueue.h"
#include "../headers/makanan.h"
#include "../headers/parser.h"

#define strbol(x) (x) ? "True\n" : "False\n"

Makanan NewDummy(int id,int mKadar,int mKirim)
/* Membuat makanan untuk dijadikan komponen queue*/
{
    // Kamus Lokal
    Makanan tmp;
    Waktu kirim, kadar;
    Point p;
    Word name = NewWord("-",1);
    // Algoritma
    CreatePoint(&p,0,0);
    CreateWaktu(&kadar,0,0,mKadar);
    CreateWaktu(&kirim,0,0,mKirim);
    CreateMakanan(&tmp,id,name,kadar,kirim,p);
    return tmp;
}

int main(){
    // Kamus
    PrioQueue Q;
    Makanan tmp;
    int i;
    // Algoritma
    CreateEmptyPQ(&Q);
    printf("****** Cek isEmptyPQ dan isFullPQ ******\n");
    printf(strbol(IsEmptyPQ(Q)));
    printf(strbol(IsFullPQ(Q)));
    printf("****** Cek displayPQ ******\n");
    DisplayPQ(Q);
    printf("****** Cek enqueue ******\n");
    for (i = 0;i < 4;i++){
        Enqueue(&Q,NewDummy(i,i,3-i),i);
    }
    DisplayPQ(Q);
    printf("****** Cek getter ******\n");
    DisplayMakanan(GetHeadInfo(Q));
    DisplayMakanan(GetElmtPQ(Q,LengthPQ(Q)-1));
    printf("****** Cek length ******\n");
    printf("length : %d\n",lengthPQ(Q));
    printf("****** Cek dequeue ******\n");

    Dequeue(&Q,&tmp);
    DisplayMakanan(tmp);
    DisplayPQ(Q);
    printf("****** Cek sifat queue yang tetap ketika enque dan deque dilakukan bergantian ******\n");
    for (i = 0;i < 20;i++){
        Enqueue(&Q,NewDummy(-1,0,0),0);
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
        enqueue(&Q,NewDummy(i,0,0),0);    
    }
    printf(strbol(isFullPQ(Q)));
    printf("****** Cek realokasi jika queue tidak muat ******\n");
    printf("Capacity : %d\n",Q.Cap);
    Enqueue(&Q,NewDummy(20,0,0),0);
    printf("Capacity : %d\n",Q.Cap);
    for (i = 0;i < 40;i++){
        Enqueue(&Q,NewDummy(i,0,0),0);    
    }
    printf("Capacity : %d\n",Q.Cap);
    printf("****** Cek deleteAt ******\n");
    DeleteAtPQ(&Q,&tmp,4);
    DisplayMakanan(tmp);
    printf("****** Cek realokasi jika queue sepi ******\n");
    printf("Capacity awal : %d\n",Q.Cap);
    while (LengthPQ(Q) > 20){
        Dequeue(&Q,&tmp);
    }
    printf("Capacity akhir : %d\n",Q.Cap);

}