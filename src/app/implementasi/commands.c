/* C libraries */
#include <stdio.h>
#include <stdlib.h>
/* APP */
#include "../headers/commands.h"

//LOCAL FUNCTION, TIDAK DAPAT DIPANGGIL DI LUAR COMMMANDS.C
Makanan GetMakananFromId(ListStatik foods, int id){
    int i;
    for(i=0;i<foods.idxEff;i++){
        if(GetVal(LIST_ELMT(foods,i)).m.Id==id){
            return GetVal(LIST_ELMT(foods,i)).m;
        }
    }
    Makanan m;Point p;
    CreatePoint(&p,0,0);
    // MARK SEBAGAI TIDAK ADA DENGAN ID -999
    CreateMakanan(&m, -999, NewWord("Not Found", 9), 0, 0, p);
    return m;
}

void Start(Simulator* simulator, ListStatik* foods, ListStatik* recipes, Map* map, ListDinElType* buyFoods, ListDinElType* mixFoods, ListDinElType* chopFoods, ListDinElType* fryFoods, ListDinElType* boilFoods, Stack undoRecord, Stack redoRecord){
    ReadAllConfig(map, foods, recipes);
    int i;
    for(i=0;i<ListLength(*foods);i++){
        if(IsEqualPoint(T(*map), GetLokasiAksi(GetVal((*foods).contents[i]).m))){
            InsertLastListDinElType(buyFoods, (*foods).contents[i]);

        } else if (IsEqualPoint(M(*map), GetLokasiAksi(GetVal((*foods).contents[i]).m))){

            InsertLastListDinElType(mixFoods, (*foods).contents[i]);
        } else if (IsEqualPoint(C(*map), GetLokasiAksi(GetVal((*foods).contents[i]).m))){

            InsertLastListDinElType(chopFoods, (*foods).contents[i]);

        } else if (IsEqualPoint(F(*map), GetLokasiAksi(GetVal((*foods).contents[i]).m))){

            InsertLastListDinElType(fryFoods, (*foods).contents[i]);
        } else if (IsEqualPoint(B(*map), GetLokasiAksi(GetVal((*foods).contents[i]).m))){

            InsertLastListDinElType(boilFoods, (*foods).contents[i]);
        }
    }
    printf("Masukkan nama Anda: ");STARTWORD();(*simulator).NamaPengguna = currentWord;
    printf("Selamat datang ");DisplayWord((*simulator).NamaPengguna);printf("!\n");
}

void Exit(){
    printf("Exiting the simulator...\n");
    exit(0);
}

void Buy(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType BuyFoods, PrioQueue *delivery, Stack undoRecord, Stack redoRecord){
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

void Mix(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType mixFoods, Stack undoRecord, Stack redoRecord){
    if(!(IsAdjacent((*simulator).Lokasi,M(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area mixing!\n");
    } else {
        MixMenu(mixFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(mixFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(mixFoods.buffer[x]).m.Id);
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

void Chop(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType chopFoods, Stack undoRecord, Stack redoRecord){
    if(!(IsAdjacent((*simulator).Lokasi,C(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area pemotongan!\n");
    } else {
        ChopMenu(chopFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(chopFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(chopFoods.buffer[x]).m.Id);
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

void Fry(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType fryFoods, Stack undoRecord, Stack redoRecord){
    if(!(IsAdjacent((*simulator).Lokasi,F(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area penggorengan!\n");
    } else {
        FryMenu(fryFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(fryFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(fryFoods.buffer[x]).m.Id);
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

void Boil(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType boilFoods, Stack undoRecord, Stack redoRecord){
    if(!(IsAdjacent((*simulator).Lokasi,B(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area perebusan!\n");
    } else {
        BoilMenu(boilFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(boilFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(boilFoods.buffer[x]).m.Id);
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

void Undo (Simulator* simulator, ListStatik* foods, ListStatik* recipes, Map* map, ListDinElType* buyFoods, ListDinElType* mixFoods, ListDinElType* chopFoods, ListDinElType* fryFoods, ListDinElType* boilFoods, Stack undoRecord, Stack redoRecord)
{
    
}