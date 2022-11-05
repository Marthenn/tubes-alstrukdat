/* C libraries */
#include <stdio.h>

/* ADT */
#include "../../boolean.h"
#include "../eltype/eltype.h"
#include "../matriks/matriks.h"
#include "map.h"
#include "../../app/parser/parser.h"

/* *** Selektor *** */

void CreateMap(Map *map, int row, int col)
// I.S. map tidak terdefinisi
// F.S. map berisi tabel matriks ukuran row x col dengan isi belum terdefinisi serta masing-masing lokasi simulator, telepon, dan lainnya tidak terdefinisi
{
    CreateMatriks(row, col, &map->tab);
    CREATE_POINT_UNDEF(S(*map));
    CREATE_POINT_UNDEF(T(*map));
    CREATE_POINT_UNDEF(M(*map));
    CREATE_POINT_UNDEF(C(*map));
    CREATE_POINT_UNDEF(F(*map));
    CREATE_POINT_UNDEF(B(*map));
}

void MoveSimulator(Map *map, Point p)
// I.S. map terdefinisi, command valid (yaitu antara 4 command MOVE)
// F.S. posisi simulator di update
{
    // KAMUS LOKAL
    char temp;

    // ALGORITMA

    temp = MAT_ELMT(TAB(*map), GetAbsis(p), GetOrdinat(p));
    MAT_ELMT(TAB(*map), GetAbsis(p), GetOrdinat(p)) = 'S';
    MAT_ELMT(TAB(*map), GetAbsis(S(*map)), GetOrdinat(S(*map))) = temp;

    S(*map).x = GetAbsis(p);
    S(*map).y = GetOrdinat(p);
}

void DisplayMap(Map map)
{
    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    for(i = -1; i <= GetLastIdxRow(TAB(map)) + 1; i++){

        for(j = -1; j <= GetLastIdxCol(TAB(map)) + 1; j++){

            if (i >= 0 && i <= GetLastIdxRow(TAB(map)))
            {
                if (j >= 0 && j <= GetLastIdxCol(TAB(map)))
                {
                    if (MAT_ELMT(TAB(map), i, j) != '#')
                    {
                        printf("%c", MAT_ELMT(TAB(map), i, j));
                    }
                    
                    else
                    {
                        printf(" ");
                    }
                }

                else {
                    printf("*");
                }
            }

            else {
                printf("*");
            }

            if (j < GetLastIdxCol(TAB(map)) + 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}