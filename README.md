# Wengrow
Tugas Besar IF2110 Algoritma dan Struktur Data mengenai suatu simulator dapur. Pada simulator ini pengguna akan menjadi seseorang yang ditempatkan pada dapur dengan peta tertentu (tergantung dengan berkas konfigurasi). Pengguna dapat memesan makanan melalui telepon dan memroses makanan-makanan tersebut.

## Cara Kompilasi
Apabila menggunakan sistem operasi windows, cukup jalankan berkas main.bat<br>
Akan tetapi bila menggunakan sistem operasi lain maka posisi terminal Anda pada directory utama program ini dan masukkan command berikut:<br>
`gcc src/main.c src/adt/charmachine/charmachine.c src/adt/eltype/eltype.c src/adt/listdin/listdin.c src/adt/listdineltype/listdineltype.c src/adt/liststatik/liststatik.c src/adt/makanan/makanan.c src/adt/map/map.c src/adt/matriks/matriks.c src/adt/point/point.c src/adt/prioqueue/prioqueue.c src/adt/set/set.c src/adt/simulator/simulator.c src/adt/stack/stack.c src/adt/tree/tree.c src/adt/waktu/waktu.c src/adt/wordmachine/wordmachine.c src/app/commands/commands.c src/app/display/display.c src/app/filereader/filereader.c src/app/parser/parser.c -o main`<br>
Setelah kompilasi program berhasil maka anda dapat menjalankan program dengan memasukkan command berikut:<br>
`./main`<br>

## Pembagian Tugas
### 1. 13521112 - Rayhan Hanif Maulana P
- ADT List Statik
- ADT Matriks
- Mekanisme Waktu
### 2. 13521137 - Michael Utama
- ADT Point
- ADT Waktu
- ADT Makanan
- ADT Simulator
### 3. 13521144 - Bintang Dwi Marthen
- ADT Set
- ADT ElType
- ADT ListDinElType
- ADT Tree
- Pengolahan Makanan
- Inisialisasi
- Pemesanan Makanan
- Kulkas
### 4. 13521148 - Johanes Lee
- ADT ElType
- ADT ListDinElType
- ADT Mesin Karakter dan Mesin Kata
- ADT List Dinamis
- ADT Stack
- ADT Map
- Inisialisasi
- Command Parser
- File Reader
- Undo/Redo
- Notifikasi
- Alur Main Program
### 5. 13521169 - Muhammad Habibi Husni
- ADT Set
- ADT Queue
- Rekomendasi Makanan

## Daftar Fitur
- Inisiasi Simulator (Selesai)
- Simulator (Selesai)
- Makanan (Selesai)
- Resep (Selesai)
- Inventory (Selesai)
- Pemesanan Bahan Makanan (Selesai)
- Peta (Selesai)
- Pengolahan Makanan (Selesai)
- Mekanisme Waktu (Selesai)
- Waktu Pengolahan Makanan (Selesai)
- Undo/Redo (Selesai)
- Catalog dan Cookbook (Selesai)
- Notifikasi (Selesai)
- Kulkas (Selesai)
- Rekomendasi Makanan (Selesai)
