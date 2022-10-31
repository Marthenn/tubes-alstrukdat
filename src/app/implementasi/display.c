/* C libraries */
#include <stdio.h>

/* APP */
#include "../headers/display.h"

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
    STARTWORD();
}

void BuyMenu(ListDinElType BuyFoods){
    printf("======================\n");
    printf("=        BUY         =\n");
    printf("======================\n");
    printf("List Bahan Makanan:\n");
    int i;
    for(i=1;i<=BuyFoods.nEff;i++){
        printf("   %d. ",i);DisplayWordLine(GetVal(BuyFoods.buffer[i]).m.Nama);
    }
    printf("\nKirim 0 untuk exit.\n\n");
}

void MixMenu(ListDinElType MixFoods){
    printf("======================\n");
    printf("=        MIX         =\n");
    printf("======================\n");
    printf("List Bahan Makanan:\n");
    int i;
    for(i=1;i<=MixFoods.nEff;i++){
        printf("   %d. ",i);DisplayWordLine(GetVal(MixFoods.buffer[i]).m.Nama);
    }
    printf("\nKirim 0 untuk exit.\n\n");
}

void ChopMenu(ListDinElType ChopFoods){
    printf("======================\n");
    printf("=        CHOP        =\n");
    printf("======================\n");
    printf("List Bahan Makanan:\n");
    int i;
    for(i=1;i<=ChopFoods.nEff;i++){
        printf("   %d. ",i);DisplayWordLine(GetVal(ChopFoods.buffer[i]).m.Nama);
    }
    printf("\nKirim 0 untuk exit.\n\n");
}

void FryMenu(ListDinElType FryFoods){
    printf("======================\n");
    printf("=        FRY         =\n");
    printf("======================\n");
    printf("List Bahan Makanan:\n");
    int i;
    for(i=1;i<=FryFoods.nEff;i++){
        printf("   %d. ",i);DisplayWordLine(GetVal(FryFoods.buffer[i]).m.Nama);
    }
    printf("\nKirim 0 untuk exit.\n\n");
}

void BoilMenu(ListDinElType BoilFoods){
    printf("======================\n");
    printf("=        BOIL        =\n");
    printf("======================\n");
    printf("List Bahan Makanan:\n");
    int i;
    for(i=1;i<=BoilFoods.nEff;i++){
        printf("   %d. ",i);DisplayWordLine(GetVal(BoilFoods.buffer[i]).m.Nama);
    }
    printf("\nKirim 0 untuk exit.\n\n");
}