/* C libraries */
#include <stdio.h>
#include <stdlib.h>
/* APP */
#include "../headers/commands.h"

Makanan GetMakananFromId(ListStatik foods, int id){
    int i;
    for(i=0;i<foods.idxEff;i++){
        if(GetVal(LIST_ELMT(foods,i)).m.Id==id){
            return GetVal(LIST_ELMT(foods,i)).m;
        }
    }
    Makanan m;Point p;
    CreatePoint(&p,0,0);
    CreateMakanan(&m, -999, NewWord("Not Found", 9), 0, 0, p);
    return m;
}

void Start(Simulator* simulator, ListStatik* foods, ListStatik* recipes, Map* map, ListDinElType* BuyFoods, ListDinElType* MixFoods, ListDinElType* ChopFoods, ListDinElType* FryFoods, ListDinElType* BoilFoods){
    ReadAllConfig(map, foods, recipes);
    int i;
    for(i=0;i<ListLength(*foods);i++){
        if(IsEqualPoint(T(*map), GetLokasiAksi(GetVal((*foods).contents[i]).m))){
            if(IsListDinElTypeFull(*BuyFoods)){
                ExpandListDinElType(BuyFoods);
            }
            InsertLastListDinElType(BuyFoods, (*foods).contents[i]);
        } else if (IsEqualPoint(M(*map), GetLokasiAksi(GetVal((*foods).contents[i]).m))){
            if(IsListDinElTypeFull(*MixFoods)){
                ExpandListDinElType(MixFoods);
            }
            InsertLastListDinElType(MixFoods, (*foods).contents[i]);
        } else if (IsEqualPoint(C(*map), GetLokasiAksi(GetVal((*foods).contents[i]).m))){
            if(IsListDinElTypeFull(*ChopFoods)){
                ExpandListDinElType(ChopFoods);
            }
            InsertLastListDinElType(ChopFoods, (*foods).contents[i]);
        } else if (IsEqualPoint(F(*map), GetLokasiAksi(GetVal((*foods).contents[i]).m))){
            if(IsListDinElTypeFull(*FryFoods)){
                ExpandListDinElType(FryFoods);
            }
            InsertLastListDinElType(FryFoods, (*foods).contents[i]);
        } else if (IsEqualPoint(B(*map), GetLokasiAksi(GetVal((*foods).contents[i]).m))){
            if(IsListDinElTypeFull(*BoilFoods)){
                ExpandListDinElType(BoilFoods);
            }
            InsertLastListDinElType(BoilFoods, (*foods).contents[i]);
        }
    }
    printf("Masukkan nama Anda: ");STARTWORD();(*simulator).NamaPengguna = currentWord;
    printf("Selamat datang ");DisplayWord((*simulator).NamaPengguna);printf("!\n");
}

void Exit(){
    printf("Exiting the simulator...\n");
    exit(0);
}

// FIX: Buy gak ada prerequiste kebutuhan, hapus
void Buy(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType BuyFoods, PrioQueue *delivery){
    if(!(IsAdjacent((*simulator).Lokasi,T(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area telepon!\n");
    } else {
        BuyMenu(BuyFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(BuyFoods)){
                printf("Out of range!\n");
            } else {
                //beli makanan disini
                Enqueue(delivery, GetVal(BuyFoods.buffer[x]).m.Id, GetMakananFromId(foods,GetVal(BuyFoods.buffer[x]).m.Id).Pengiriman);
            }
        }
    }
}

void Mix(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType MixFoods){
    if(!(IsAdjacent((*simulator).Lokasi,M(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area mixing!\n");
    } else {
        MixMenu(MixFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(MixFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(MixFoods.buffer[x]).m.Id);
                ListDin need; CreateListDin(&need,10);
                while(IsListDinEmpty(need)){
                    need = GetChildren(GetVal(LIST_ELMT(recipes,x)).t);
                }
                ListDin needLeft; //copy listdin need
                CopyListDin(need, &needLeft);
                int needLength = ListDinLength(need);
                int needCount = 0;
                int i,temp;
                for(i=0;i<needLength;i++){
                    //cek apakah ada di inventory
                    int j;
                    for(j=0;j<LengthPQ((*simulator).Inventory);j++){
                        if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                            needCount++;
                            break;
                        }
                    }
                    //hapus dari needLeft
                    DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                }
                if(needCount==needLength){
                    success = true;
                    //kurangi inventory
                    for(i=0;i<needLength;i++){
                        DeleteAtPQ(&(*simulator).Inventory, &temp, need.buffer[i]);
                    }
                    //tambah ke inventory
                    Enqueue(&(*simulator).Inventory, dibuat.Id, dibuat.Kedaluarsa);
                } else {
                    printf("Gagal membuat ");
                    DisplayWord(dibuat.Nama);
                    printf(" karena kamu tidak memiliki bahan berikut:\n");
                    for(i=0;i<ListDinLength(needLeft);i++){
                        //print yang kurang apa aja
                        printf("   %d. ",i+1);
                        DisplayWordLine(GetMakananFromId(foods,needLeft.buffer[i]).Nama);
                    }
                    printf("\n");
                }
            }
        }
    }
}

void Chop(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType ChopFoods){
    if(!(IsAdjacent((*simulator).Lokasi,C(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area pemotongan!\n");
    } else {
        ChopMenu(ChopFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(ChopFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(ChopFoods.buffer[x]).m.Id);
                ListDin need; CreateListDin(&need,10);
                while(IsListDinEmpty(need)){
                    need = GetChildren(GetVal(LIST_ELMT(recipes,x)).t);
                }
                ListDin needLeft; //copy listdin need
                CopyListDin(need, &needLeft);
                int needLength = ListDinLength(need);
                int needCount = 0;
                int i,temp;
                for(i=0;i<needLength;i++){
                    //cek apakah ada di inventory
                    int j;
                    for(j=0;j<LengthPQ((*simulator).Inventory);j++){
                        if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                            needCount++;
                            break;
                        }
                    }
                    //hapus dari needLeft
                    DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                }
                if(needCount==needLength){
                    success = true;
                    //kurangi inventory
                    for(i=0;i<needLength;i++){
                        DeleteAtPQ(&(*simulator).Inventory, &temp, need.buffer[i]);
                    }
                    //tambah ke inventory
                    Enqueue(&(*simulator).Inventory, dibuat.Id, dibuat.Kedaluarsa);
                } else {
                    printf("Gagal membuat ");
                    DisplayWord(dibuat.Nama);
                    printf(" karena kamu tidak memiliki bahan berikut:\n");
                    for(i=0;i<ListDinLength(needLeft);i++){
                        //print yang kurang apa aja
                        printf("   %d. ",i+1);
                        DisplayWordLine(GetMakananFromId(foods,needLeft.buffer[i]).Nama);
                    }
                    printf("\n");
                }
            }
        }
    }
}

void Fry(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType FryFoods){
    if(!(IsAdjacent((*simulator).Lokasi,F(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area penggorengan!\n");
    } else {
        FryMenu(FryFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(FryFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(FryFoods.buffer[x]).m.Id);
                ListDin need; CreateListDin(&need,10);
                while(IsListDinEmpty(need)){
                    need = GetChildren(GetVal(LIST_ELMT(recipes,x)).t);
                }
                ListDin needLeft; //copy listdin need
                CopyListDin(need, &needLeft);
                int needLength = ListDinLength(need);
                int needCount = 0;
                int i,temp;
                for(i=0;i<needLength;i++){
                    //cek apakah ada di inventory
                    int j;
                    for(j=0;j<LengthPQ((*simulator).Inventory);j++){
                        if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                            needCount++;
                            break;
                        }
                    }
                    //hapus dari needLeft
                    DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                }
                if(needCount==needLength){
                    success = true;
                    //kurangi inventory
                    for(i=0;i<needLength;i++){
                        DeleteAtPQ(&(*simulator).Inventory, &temp, need.buffer[i]);
                    }
                    //tambah ke inventory
                    Enqueue(&(*simulator).Inventory, dibuat.Id, dibuat.Kedaluarsa);
                } else {
                    printf("Gagal membuat ");
                    DisplayWord(dibuat.Nama);
                    printf(" karena kamu tidak memiliki bahan berikut:\n");
                    for(i=0;i<ListDinLength(needLeft);i++){
                        //print yang kurang apa aja
                        printf("   %d. ",i+1);
                        DisplayWordLine(GetMakananFromId(foods,needLeft.buffer[i]).Nama);
                    }
                    printf("\n");
                }
            }
        }
    }
}

void Boil(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType BoilFoods){
    if(!(IsAdjacent((*simulator).Lokasi,B(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area perebusan!\n");
    } else {
        BoilMenu(BoilFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(BoilFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(BoilFoods.buffer[x]).m.Id);
                ListDin need; CreateListDin(&need,10);
                while(IsListDinEmpty(need)){
                    need = GetChildren(GetVal(LIST_ELMT(recipes,x)).t);
                }
                ListDin needLeft; //copy listdin need
                CopyListDin(need, &needLeft);
                int needLength = ListDinLength(need);
                int needCount = 0;
                int i,temp;
                for(i=0;i<needLength;i++){
                    //cek apakah ada di inventory
                    int j;
                    for(j=0;j<LengthPQ((*simulator).Inventory);j++){
                        if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                            needCount++;
                            break;
                        }
                    }
                    //hapus dari needLeft
                    DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                }
                if(needCount==needLength){
                    success = true;
                    //kurangi inventory
                    for(i=0;i<needLength;i++){
                        DeleteAtPQ(&(*simulator).Inventory, &temp, need.buffer[i]);
                    }
                    //tambah ke inventory
                    Enqueue(&(*simulator).Inventory, dibuat.Id, dibuat.Kedaluarsa);
                } else {
                    printf("Gagal membuat ");
                    DisplayWord(dibuat.Nama);
                    printf(" karena kamu tidak memiliki bahan berikut:\n");
                    for(i=0;i<ListDinLength(needLeft);i++){
                        //print yang kurang apa aja
                        printf("   %d. ",i+1);
                        DisplayWordLine(GetMakananFromId(foods,needLeft.buffer[i]).Nama);
                    }
                    printf("\n");
                }
            }
        }
    }
}