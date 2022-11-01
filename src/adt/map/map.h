#ifndef MAP_H
#define MAP_H

/* ADT */
#include "../eltype/eltype.h"
#include "../matriks/matriks.h"

typedef struct{
    Matriks tab;
    Point S, T, M, C, F, B, X;
} Map;

/* *** Selektor *** */
#define MAP_ROW(map) ROW_EFF(map.tab)
#define MAP_COL(map) COL_EFF(map.tab)
#define Place(map, i, j) MAT_ELMT((map).tab, (i), (j))
#define TAB(map) (map).tab
#define S(map) (map).S
#define T(map) (map).T
#define M(map) (map).M
#define C(map) (map).C
#define F(map) (map).F
#define B(map) (map).B
#define CREATE_POINT_UNDEF(point) CreatePoint(&(point), -1, -1)
#define WALL_MAP_CHAR 'X'
#define SPACE_MAP_CHAR '#'

void CreateMap(Map *map, int row, int col);
// I.S. map tidak terdefinisi
// F.S. map berisi tabel matriks ukuran row x col dengan isi belum terdefinisi serta masing-masing lokasi simulator, telepon, dan lainnya tidak terdefinisi

void MoveSimulator(Map *map, Point p);
// I.S. map terdefinisi, command valid (yaitu antara 4 command MOVE)
// F.S. posisi simulator di update

void DisplayMap(Map map);
// I.S. map terdefinisi
// F.S. map ditampilkan ke layar
#endif