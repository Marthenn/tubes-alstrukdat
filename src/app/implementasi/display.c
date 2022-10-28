#include <stdio.h>
#include "../headers/display.h"

void SplashScreen(){
    printf("        -------\n");
    printf("       | meow! |\n");
    printf("|\\__/| /--------\n");
    printf("(_^-^)\n");
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