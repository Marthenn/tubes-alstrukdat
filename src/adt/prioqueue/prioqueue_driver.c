/* C libraries */
#include <stdio.h>
#include <stdlib.h>

/* ADT */
#include "prioqueue.h"
#include "../eltype/eltype.h"

/* APP */
#include "../../app/parser/parser.h"

#define strbol(x) (x) ? "True\n" : "False\n"

int main(){
    // Kamus
    PrioQueue Q,P;
    Waktu time;
    int tmp;
    int i;
    // Algoritma
    /* Notes : ganti seed dibawah jika ingin mengganti hasil rand()*/
    /* rand() pseudorandom jd kalau seednya ngga diganti, seq angkanya selalu sama*/
    srand(129);
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
    Dequeue(&Q,&tmp, &time);
    printf("%d\n",tmp);
    DisplayPQ(Q);
    printf("****** Cek sifat queue yang tetap ketika enque ke Head dan deque dilakukan bergantian ******\n");
    for (i = 0;i < 20;i++){
        Enqueue(&Q,-1,0);
        Dequeue(&Q,&tmp, &time);
    }
    DisplayPQ(Q);
    printf("****** Cek DeleteAt ******\n");
    printf("Hapus Elemen ke-2\n");
    DeleteAtPQ(&Q,&tmp, &time, 2);
    printf("Hapus %d\n",tmp);
    DisplayPQ(Q);
    printf("****** Cek DeleteElmt ******\n");
    printf("Hapus < 7, 3 >\n");
    DeleteElmtPQ(&Q,7,3);
    DisplayPQ(Q);
    printf("****** Cek operasi Assign ******\n");
    CreateEmptyPQ(&P);
    AssignPQ(Q, &P);
    printf("Salinan Q : \n");
    DisplayPQ(P);
    printf("Mengosongkan queue...\n");
    while (!IsEmptyPQ(Q)){
        Dequeue(&Q,&tmp, &time);
    }
    DisplayPQ(Q);
    printf("****** Cek realokasi jika queue tidak muat ******\n");
    printf("Length : %d ; Capacity : %d\n",LengthPQ(Q),Q.Cap);
    Enqueue(&Q,0,0);
    printf("Length : %d ; Capacity : %d\n",LengthPQ(Q),Q.Cap);
    for (i = 1;i <= 2;i++){
        Enqueue(&Q,i,i);    
    }
    printf("Length : %d ; Capacity : %d\n",LengthPQ(Q),Q.Cap);
    for (i = 3;i <= 40;i++){
        Enqueue(&Q,i,i);    
    }
    printf("Length : %d ; Capacity : %d\n",LengthPQ(Q),Q.Cap);
    
    printf("****** Cek realokasi jika queue sepi ******\n");
    printf("Length : %d ; Capacity : %d\n",LengthPQ(Q),Q.Cap);
    while (LengthPQ(Q) > 16){
        Dequeue(&Q,&tmp, &time);
    }
    printf("Length : %d ; Capacity : %d\n",LengthPQ(Q),Q.Cap);
        while (LengthPQ(Q) > 4){
        Dequeue(&Q,&tmp, &time);
    }
    printf("Length : %d ; Capacity : %d\n",LengthPQ(Q),Q.Cap);
        printf("****** Uji Q ketika full ******\n");
    tmp = LengthPQ(Q);
    printf("Mengisi queue hingga penuh...\n");
    for (i = 0;i < Q.Cap-tmp;i++){
        Enqueue(&Q,i,i);    
    }
    printf("Length : %d ; Capacity : %d\n",LengthPQ(Q),Q.Cap);    
    printf(strbol(IsFullPQ(Q)));

    CreateEmptyPQ(&Q);
    while (true){
        printf("----- Free Testing -----\n");
        printf("[1] GetHeadInfo\n");
        printf("[2] GetHeadTime\n");
        printf("[3] GetElmtInfo\n");
        printf("[4] GetElmtTime\n");
        printf("[5] SetElmtTime\n");
        printf("[6] IsEarlier\n");
        printf("[7] IsEmptyPQ\n");
        printf("[8] IsFullPQ\n");
        printf("[9] LengthPQ\n");
        printf("[10] CreateEmptyPQ\n");
        printf("    (Note : tidak ada dealokasi pada Q lama)\n");
        printf("[11] DeallocatePQ\n");
        printf("    (Note : menjadikan Q tidak terdefenisi, bukan membuat Q menjadi Q kosong)\n");
        printf("[12] ReallocatePQ\n");
        printf("[13] IndexOfPQ\n");
        printf("[14] Enqueue\n");
        printf("[15] Dequeue\n");
        printf("[16] DeleteAtPQ\n");
        printf("[17] DeleteElmtPQ\n");
        printf("[18] AssignPQ\n");
        printf("    (Q akan diassign ke dirinya sendiri)\n");
        printf("[19] DisplayInfoTypePQ\n");
        printf("[20] DisplayPQ\n");
        printf("[21] Enqueue random (info \% 10, time kurang dr sejam) \n");
        printf("[0] Exit\n");
        printf("Current Head idx : %d\n",Q.Head);
        printf("Current Tail idx : %d\n",Q.Tail);
        printf("Current Cap : %d\n",Q.Cap);
        DisplayPQ(Q);
        int p,arg1, arg2,arg3,arg4;
        printf("Masukkan pilihan : ");
        scanf("%d",&p);
        switch (p){
        case 1:
            if (IsEmptyPQ(Q)){
                printf("Kosong!\n");
            } else {
                printf("%d\n",GetHeadInfo(Q));
            }
            break;
        case 2:
            if (IsEmptyPQ(Q)){
                printf("Kosong!\n");
            } else {
                CetakWaktuLengkap(GetHeadTime(Q));
                printf("\n");
            }
            break;
        case 3:
            printf("Masukkan idx : "); scanf("%d",&arg1);
            if (arg1 < 0 || arg1 >= LengthPQ(Q)){
                printf("Out Of Bounds!\n");
            } else {
                printf("%d\n",GetElmtInfo(Q,arg1));
            }
            break;
        case 4:
            printf("Masukkan idx : "); scanf("%d",&arg1);
            if (arg1 < 0 || arg1 >= LengthPQ(Q)){
                printf("Out Of Bounds!\n");
            } else {
                CetakWaktuLengkap(GetElmtTime(Q,arg1));
                printf("\n");
            }
            break;
        case 5:
            printf("Masukkan idx : "); scanf("%d",&arg1);
            printf("Masukkan time baru : "); scanf("%d",&arg2);
            if (arg1 < 0 || arg1 >= LengthPQ(Q)){
                printf("Out Of Bounds!\n");
            } else {
                SetElmtTime(&Q,arg1,arg2);
            }
            break;
        case 6:
            printf("Masukkan info1 : "); scanf("%d",&arg1);
            printf("Masukkan time1 : "); scanf("%d",&arg2);
            printf("Masukkan info2 : "); scanf("%d",&arg3);
            printf("Masukkan time2 : "); scanf("%d",&arg4);
            PQInfoType p1,p2;
            p1.Info = arg1; p1.Time = arg2;
            p2.Info = arg3; p2.Time = arg4;
            strbol(IsEarlier(p1,p2));
            break;
        case 7:
            strbol(IsEmptyPQ(Q));
            break;
        case 8:
            strbol(IsFullPQ(Q));
            break;
        case 9:
            printf("%d\n",LengthPQ(Q));
            break;
        case 10:
            CreateEmptyPQ(&Q);
            break;
        case 11:
            DeallocatePQ(&Q);
            break;
        case 12:
            printf("Masukkan ukuran baru : "); scanf("%d",&arg1);
            if (arg1 < LengthPQ(Q)){
                printf("Ukuran baru lebih kecil dari banyak elemen Q!\n");
            } else {
                ReallocatePQ(&Q,arg1);
            }
            break;
        case 13:
            printf("Masukkan info yang dicari : "); scanf("%d",&arg1);
            printf("%d berada di idx ke %d\n", arg1, IndexOfPQ(Q,arg1));
            break;
        case 14:
            printf("Masukkan info : "); scanf("%d",&arg1);
            printf("Masukkan time : "); scanf("%d",&arg2);
            Enqueue(&Q,arg1,arg2);
            break;
        case 15:
            if (IsEmptyPQ(Q)){
                printf("Q empty!\n");
            } else {
                int info; Waktu time;
                Dequeue(&Q,&info,&time);
                printf("%d ",info);
                CetakWaktuLengkap(time);
                printf("\n");
            }
            break;
        case 16:
            printf("Masukkan idx : "); scanf("%d",&arg1);
            if (arg1 < 0 || arg1 >= LengthPQ(Q)){
                printf("Out Of Bounds!\n");
            } else {
                int info; Waktu time;
                DeleteAtPQ(&Q,&info,&time,arg1);
                printf("%d ",info);
                CetakWaktuLengkap(time);
                printf("\n");
            } 
            break;
        case 17:
            printf("Masukkan info : "); scanf("%d",&arg1);
            printf("Masukkan time : "); scanf("%d",&arg2);
            DeleteElmtPQ(&Q,arg1,arg2);
            break;
        case 18:
            PrioQueue tmp;
            CreateEmptyPQ(&tmp);
            AssignPQ(Q,&tmp);
            free(Q.Tab);
            Q = tmp;
            break;
        case 19:
            printf("Masukkan info : "); scanf("%d",&arg1);
            printf("Masukkan time : "); scanf("%d",&arg2);
            PQInfoType p;
            p.Info = arg1; p.Time = arg2;
            DisplayInfoTypePQ(p);
            printf("\n");
            break;
        case 20:
            DisplayPQ(Q);
            break;
        case 21:
            int a,b;
            a = rand() % 10;
            b = rand() % 60;
            Enqueue(&Q,a,b);
            break;
        case 0:
            return 0;
        default:
            printf("Out of bounds!\n");
            break;
        }
        getchar();
        printf("Press Enter to Continue");
        
        getchar();
    }
}