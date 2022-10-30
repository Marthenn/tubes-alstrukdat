/* C libraries */
#include <stdio.h>
#include <stdlib.h>
/* APP */
#include "../headers/commands.h"
#include "../headers/display.h"

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

void Buy(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType BuyFoods){
    if(!(IsAdjacent((*simulator).Lokasi,T(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area telepon!\n");
    } else {
        BuyMenu(BuyFoods);
        int x;
        printf("Enter Command: ");scanf("%d",&x);
        while(!(0<=x && x<=ListDinElTypeLength(BuyFoods))){
            printf("Makanan tidak ada!\n");
            printf("Enter Command: ");scanf("%d",&x);
        }
        x--;
        if(x==-1){
            printf("Kembali ke menu utama...\n");
        } else {
            Makanan dibuat = GetMakananFromId(foods, GetVal(BuyFoods.buffer[x]).m.Id);
            ListDin need; CreateListDin(&need,10);
            while(IsListDinEmpty(need)){
                need = GetChildren(GetVal(LIST_ELMT(recipes,x)).t);
            }
            int needLength = ListDinLength(need);
            int needCount = 0;
            int i;
            for(i=0;i<needLength;i++){
                //cek apakah ada di inventory
            }
            if(needCount==needLength){
                //kurangi inventory
                //tambah ke inventory
            } else {
                printf("Gagal membuat ");
                DisplayWord(dibuat.Nama);
                printf(" karena kamu tidak memiliki bahan berikut:\n");
                for(i=0;i<needLength;i++){
                    //print yang kurang apa aja
                }
            }
        }
    }
}