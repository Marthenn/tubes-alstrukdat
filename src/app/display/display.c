/* C libraries */
#include <stdio.h>

/* APP */
#include "display.h"

Makanan GetMakananFromId(ListStatik foods, int id){

    Makanan m;
    Point p;

    int idx = ListIndexOf(foods, NewElType(0, (union Data){.i=id}));

    if (idx != LISTSTATIK_IDX_UNDEF)
    {
        return GetVal(LIST_ELMT(foods,idx)).m;
    }

    else {
        CreatePoint(&p,0,0);
        // MARK SEBAGAI TIDAK ADA DENGAN ID -999
        CreateMakanan(&m, -999, NewWord("Not Found", 9), 0, 0, EMPTY_WORD, p, 0, 0);
        return m;
    }
}

void SplashScreen(){
    printf("    (\\\n");
    printf("     \\ \\\n");
    printf(" __    \\/ ___,.-------..__        __\n");
    printf("//\\\\ _,-'\\\\               `'--._ //\\\\\n");
    printf("\\\\ ;'      \\\\                   `: //\n");
    printf(" `(          \\\\                   )'\n");
    printf("   :.          \\\\,----,         ,;\n");
    printf("    `.`--.___   (    /  ___.--','\n");
    printf("      `.     ``-----'-''     ,'\n");
    printf("         -.               ,-\n");
    printf("            `-._______.-'\n");
    printf("\n");
    printf("Welcome to Wengrow!\n");
    printf("A simple program to simulate a kitchen\n");
    printf("======================================\n");
}

void StartScreen(){
    SplashScreen();
    printf("1. START\n");
    printf("2. EXIT\n");
}

void Help(){
    printf("Perintah yang Tersedia:\n");
    printf("1.  BUY\n");
    printf("    Melakukan pemesanan bahan makanan\n");
    printf("2.  DELIVERY\n");
    printf("    Melihat pemesanan makanan\n");
    printf("3.  MOVE NORTH\n");
    printf("    Bergerak ke arah utara\n");
    printf("4.  MOVE EAST\n");
    printf("    Bergerak ke arah timur\n");
    printf("5.  MOVE WEST\n");
    printf("    Bergerak ke arah barat\n");
    printf("6.  MOVE SOUTH\n");
    printf("    Bergerak ke arah selatan\n");
    printf("7.  MIX\n");
    printf("    Mencampurkan dua atau lebih bahan makanan\n");
    printf("8.  CHOP\n");
    printf("    Memotong suatu bahan makanan\n");
    printf("9.  FRY\n");
    printf("    Menggoreng satu atau lebih bahan makanan\n");
    printf("10. BOIL\n");
    printf("    Merebus suatu bahan makanan\n");
    printf("11. WAIT x y\n");
    printf("    Menunggu selama x jam dan y menit\n");
    printf("12. UNDO\n");
    printf("    Membatalkan perintah terakhir\n");
    printf("13. REDO\n");
    printf("    Melakukan perintah yang dibatalkan\n");
    printf("14. CATALOG\n");
    printf("    Melihat daftar bahan makanan yang tersedia\n");
    printf("15. COOKBOOK\n");
    printf("    Melihat daftar resep yang tersedia\n");
    printf("16. INVENTORY\n");
    printf("    Melihat bahan makanan yang ada di inventory\n");
    printf("17. HELP\n");
    printf("    Menampilkan semua perintah yang tersedia\n");
    printf("18. EXIT\n");
    printf("    Keluar dari simulasi\n");
}

void EnterCommand(){
    printf("Enter Command: ");
    ADVWORD();
}

void BuyMenu(ListDinElType BuyFoods){
    printf("======================\n");
    printf("=        BUY         =\n");
    printf("======================\n");
    if(ListDinElTypeLength(BuyFoods)==0){
        printf("Tidak ada bahan makanan yang bisa dibeli\n");
    } else {
        printf("List Bahan Makanan:\n");
        int i;
        for(i=1;i<=BuyFoods.nEff;i++){
            printf("   %d. ",i);DisplayWordLine(GetVal(BuyFoods.buffer[i-1]).m.Nama);
        }
    }
    printf("\nKirim 0 untuk exit\n\n");
}

void MixMenu(ListDinElType MixFoods){
    printf("======================\n");
    printf("=        MIX         =\n");
    printf("======================\n");
    if(ListDinElTypeLength(MixFoods)==0){
        printf("Tidak ada bahan makanan yang perlu dicampur\n");
    } else {
        printf("List Bahan Makanan:\n");
        int i;
        for(i=1;i<=MixFoods.nEff;i++){
            printf("   %d. ",i);DisplayWordLine(GetVal(MixFoods.buffer[i-1]).m.Nama);
        }
    }
    printf("\nKirim 0 untuk exit\n\n");
}

void ChopMenu(ListDinElType ChopFoods){
    printf("======================\n");
    printf("=        CHOP        =\n");
    printf("======================\n");
    if(ListDinElTypeLength(ChopFoods)==0){
        printf("Tidak ada bahan makanan yang perlu dipotong\n");
    } else {        
        printf("List Bahan Makanan:\n");
        int i;
        for(i=1;i<=ChopFoods.nEff;i++){
            printf("   %d. ",i);DisplayWordLine(GetVal(ChopFoods.buffer[i-1]).m.Nama);
        }
    }
    printf("\nKirim 0 untuk exit\n\n");
}

void FryMenu(ListDinElType FryFoods){
    printf("======================\n");
    printf("=        FRY         =\n");
    printf("======================\n");
    if(ListDinElTypeLength(FryFoods)==0){
        printf("Tidak ada resep yang perlu digoreng\n");
    } else {
        printf("List Bahan Makanan:\n");
        int i;
        for(i=1;i<=FryFoods.nEff;i++){
            printf("   %d. ",i);DisplayWordLine(GetVal(FryFoods.buffer[i-1]).m.Nama);
        }
    }
    printf("\nKirim 0 untuk exit\n\n");
}

void BoilMenu(ListDinElType BoilFoods){
    printf("======================\n");
    printf("=        BOIL        =\n");
    printf("======================\n");
    if(ListDinElTypeLength(BoilFoods)==0){
        printf("Tidak ada resep yang perlu direbus\n");
    } else {
        printf("List Bahan Makanan:\n");
        int i;
        for(i=1;i<=BoilFoods.nEff;i++){
            printf("   %d. ",i);DisplayWordLine(GetVal(BoilFoods.buffer[i-1]).m.Nama);
        }
    }
    printf("\nKirim 0 untuk exit\n\n");
}

void CookBook(ListStatik foods, ListStatik recipes, ListDinElType mixFoods, ListDinElType chopFoods, ListDinElType fryFoods, ListDinElType boilFoods){
    int i,j; ListDin need;
    printf("======================\n");
    printf("=      COOKBOOK      =\n");
    printf("======================\n");
    printf("FORMAT\n");
    printf("   x. Nama makanan\n");
    printf("   --> [Bahan Makanan yang dibutuhkan]\n");
    printf("======= MIXING =======\n");
    if(IsListDinElTypeEmpty(mixFoods)){
        printf("Tidak ada resep yang membutuhkan mixing\n");
    }
    for(i=0;i<ListDinElTypeLength(mixFoods);i++){
        printf("%d. ",i+1);
        DisplayWordLine(GetVal(mixFoods.buffer[i]).m.Nama);
        CreateListDin(&need,3);
        j=0;
        while(IsListDinEmpty(need)){
            if(IsPartOf(GetVal(recipes.contents[j]).t,GetVal(mixFoods.buffer[i]).m.Id)){
                need = GetChildren(GetSubTree(GetVal(recipes.contents[j]).t,GetVal(mixFoods.buffer[i]).m.Id));
            }
            j++;
        }
        printf("--> ");
        for(j=0;j<ListDinLength(need);j++){
            DisplayWord(GetMakananFromId(foods, need.buffer[j]).Nama);
            if(j<ListDinLength(need)-1){
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("====== CHOPPING ======\n");
    if(IsListDinElTypeEmpty(chopFoods)){
        printf("Tidak ada resep yang membutuhkan chopping\n");
    }
    for(i=0;i<ListDinElTypeLength(chopFoods);i++){
        printf("%d. ",i+1);
        DisplayWordLine(GetVal(chopFoods.buffer[i]).m.Nama);
        CreateListDin(&need,3);
        j=0;
        while(IsListDinEmpty(need)){
            if(IsPartOf(GetVal(recipes.contents[j]).t,GetVal(chopFoods.buffer[i]).m.Id)){
                need = GetChildren(GetSubTree(GetVal(recipes.contents[j]).t,GetVal(chopFoods.buffer[i]).m.Id));
            }
            j++;
        }
        printf("--> ");
        for(j=0;j<ListDinLength(need);j++){
            DisplayWord(GetMakananFromId(foods, need.buffer[j]).Nama);
            if(j<ListDinLength(need)-1){
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("======= FRYING =======\n");
    if(IsListDinElTypeEmpty(fryFoods)){
        printf("Tidak ada resep yang membutuhkan frying\n");
    }
    for(i=0;i<ListDinElTypeLength(fryFoods);i++){
        printf("%d. ",i+1);
        DisplayWordLine(GetVal(fryFoods.buffer[i]).m.Nama);
        CreateListDin(&need,3);
        j=0;
        while(IsListDinEmpty(need)){
            if(IsPartOf(GetVal(recipes.contents[j]).t,GetVal(fryFoods.buffer[i]).m.Id)){
                need = GetChildren(GetSubTree(GetVal(recipes.contents[j]).t,GetVal(fryFoods.buffer[i]).m.Id));
            }
            j++;
        }
        printf("--> ");
        for(j=0;j<ListDinLength(need);j++){
            DisplayWord(GetMakananFromId(foods, need.buffer[j]).Nama);
            if(j<ListDinLength(need)-1){
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("====== BOILING =======\n");
    if(IsListDinElTypeEmpty(boilFoods)){
        printf("Tidak ada resep yang membutuhkan boiling\n");
    }
    for(i=0;i<ListDinElTypeLength(boilFoods);i++){
        printf("%d. ",i+1);
        DisplayWordLine(GetVal(boilFoods.buffer[i]).m.Nama);
        CreateListDin(&need,3);
        j=0;
        while(IsListDinEmpty(need)){
            if(IsPartOf(GetVal(recipes.contents[j]).t,GetVal(boilFoods.buffer[i]).m.Id)){
                need = GetChildren(GetSubTree(GetVal(recipes.contents[j]).t,GetVal(boilFoods.buffer[i]).m.Id));
            }
            j++;
        }
        printf("--> ");
        for(j=0;j<ListDinLength(need);j++){
            DisplayWord(GetMakananFromId(foods, need.buffer[j]).Nama);
            if(j<ListDinLength(need)-1){
                printf(", ");
            }
        }
        printf("\n");
    }
}

void Catalog(ListStatik foods)
{
    int i;
    printf("======LIST BAHAN DAN MAKANAN======\n");
    
    for (i = 0; i < ListLength(foods); i++)
    {
        printf("[%d] ", i + 1);
        DisplayMakanan(GetVal(LIST_ELMT(foods, i)).m);
        printf("\n");
    }
    printf("\n");
}

void DisplayDelivery(ListStatik foods, Simulator simulator){
    int i, h, j, m;
    Waktu delta;
    PrioQueue delivery = simulator.Delivery;

    printf("======LIST PESANAN======\n");
    if(IsEmptyPQ(delivery)){
        printf("Tidak ada pesanan yang sedang dalam perjalanan\n");
    } else {
        printf("(nama - sisa waktu)\n");
        for(i=delivery.Head;i<=delivery.Tail;i++){
            printf("%d. ",i+1);
            DisplayWord(GetMakananFromId(foods,delivery.Tab[i].Info).Nama);
            printf(" - ");

            delta = delivery.Tab[i].Time - GetTime(&simulator);

            CetakWaktuLengkap(delta);
            printf("\n");
        }
    }
}