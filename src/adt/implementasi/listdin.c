/* C libraries */
#include <stdio.h>
#include <stdlib.h>

/* ADT */
#include "../headers/boolean.h"
#include "../headers/listdin.h"


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas nilai maksimum antara capacity dan MIN_LISTDIN_CAP */
{
    // KAMUS LOKAL
    int cap;
    // ALGORITMA
    
    cap = MIN_LISTDIN_CAP > capacity? MIN_LISTDIN_CAP : capacity;
    LISTDIN_BUFFER(*l) = (ListDinElType *) malloc(cap * sizeof(ListDinElType));
    LISTDIN_CAP(*l) = cap;
    LISTDIN_NEFF(*l) = 0;
}

void DealocateListDin(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, LISTDIN_CAP(l)=0; LISTDIN_NEFF(l)=0 */
{
    // KAMUS LOKAL
    // ALGORITMA
    free(LISTDIN_BUFFER(*l));
    LISTDIN_CAP(*l) = 0;
    LISTDIN_NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int ListDinLength(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    // KAMUS LOKAL
    // ALGORITMA
    
    return LISTDIN_NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType GetListDinFirstIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    // KAMUS LOKAL
    // ALGORITMA
    
   return LISTDIN_IDX_MIN;
}

IdxType GetListDinLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    // KAMUS LOKAL
    // ALGORITMA
    
    return (LISTDIN_NEFF(l) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsListDinIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    // KAMUS LOKAL
    // ALGORITMA
    
	if (i >= GetListDinFirstIdx(l) && i < LISTDIN_CAP(l))
	{
		return true;
	}
	
	return false;
}

boolean IsListDinIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..LISTDIN_NEFF(l)-1 */
{
    // KAMUS LOKAL
    // ALGORITMA
    
    if (i >= GetListDinFirstIdx(l) && i <= GetListDinLastIdx(l))
	{
		return true;
	}
	
	return false;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsListDinEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    // KAMUS LOKAL
    // ALGORITMA
    
    if (LISTDIN_NEFF(l) == 0)
    {
		return true;
	}
	
	return false;
    
}

/* *** Test list penuh *** */
boolean IsListDinFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    // KAMUS LOKAL
    // ALGORITMA
    
    if (LISTDIN_NEFF(l) == LISTDIN_CAP(l))
    {
		return true;
	}
	
	return false;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */

void PrintListDin(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    printf("[");
    
    if (IsListDinEmpty(l) == false)
    {
		for (i = GetListDinFirstIdx(l); i < GetListDinLastIdx(l); i++)
		{
			printf("%d,", LISTDIN_ELMT(l, i));
		}
		
		printf("%d", LISTDIN_ELMT(l, GetListDinLastIdx(l)));
	}
	
	printf("]");  
    
    
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean IsListDinEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    
    if (LISTDIN_NEFF(l1) != LISTDIN_NEFF(l2))
    {
		return false;
	}
    
    for (i = GetListDinFirstIdx(l1); i < ListDinLength(l1); i++)
    {
		if (LISTDIN_ELMT(l1, i) != LISTDIN_ELMT(l2, i))
		{
			return false;
		}
	}
	
	return true;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType ListDinIndexOf(ListDin l, ListDinElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan LISTDIN_IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (LISTDIN_IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    // KAMUS LOKAL
    boolean found = false;
    int i;
    
    // ALGORITMA
    i = 0;
    
    while (found == false && i < ListDinLength(l))
    {
		if (LISTDIN_ELMT(l, i) == val)
		{
			found = true;
		}
		
		else {
			i++;
		}
	}
	
	if (found == false)
	{
		return LISTDIN_IDX_UNDEF;
	}
	
	return i;
}

/* ********** OPERASI LAIN ********** */
void CopyListDin(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
	// KAMUS LOKAL
	int i;
    // ALGORITMA
    
    CreateListDin(lOut, LISTDIN_CAP(lIn));
	LISTDIN_NEFF(*lOut) = LISTDIN_NEFF(lIn);
	
	for (i = 0; i < ListDinLength(lIn); i++)
	{
		LISTDIN_ELMT(*lOut, i) = LISTDIN_ELMT(lIn, i);
	}
}

int CountListDinVal(ListDin l, ListDinElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
	// KAMUS LOKAL
    ListDinElType total = 0;
    int i;
    
    // ALGORITMA
    for (i = GetListDinFirstIdx(l); i < ListDinLength(l); i++)
    {
		if (LISTDIN_ELMT(l, i) == val)
		{
			total++;
		}
	}

    return total;
}

/* ********** SORTING ********** */
void SortListDin(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    // KAMUS LOKAL
    
    int i, j;
    ListDinElType temp;
    // ALGORITMA
    
    for (i = GetListDinFirstIdx(*l) + 1; i < ListDinLength(*l); i++)
    {
		j = i;
		
		while(j > 0)
		{
			if ((asc == true && LISTDIN_ELMT(*l, j) < LISTDIN_ELMT(*l, j-1)) 
                || (asc == false && LISTDIN_ELMT(*l, j) > LISTDIN_ELMT(*l, j-1)))
			{	
				temp = LISTDIN_ELMT(*l, j);
				
				LISTDIN_ELMT(*l, j) = LISTDIN_ELMT(*l, j-1);
				LISTDIN_ELMT(*l, j-1) = temp;
			}
			
			j--;
		}
	}
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void InsertFirstListDin(ListDin *l, ListDinElType val)
/* Proses: Menambahkan val sebagai elemen pertama List dinamis */
/* I.S. List l boleh kosong, jika penuh maka kapasitas ditambah */
/* F.S. val adalah elemen pertama l yang baru, kapasitas dapat bertambah */
/* *** Menambahkan elemen pada index tertentu *** */
{
	// KAMUS LOKAL
    // ALGORITMA

    InsertAtListDin(l, val, 0);
}

void InsertAtListDin(ListDin *l, ListDinElType val, IdxType idx)
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong, jika penuh maka kapasitas ditambah, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l, kapasitas dapat bertambah */
{
	// KAMUS LOKAL
    int i;
    ListDin temp;
    // ALGORITMA

    if (ListDinLength(*l) >= LISTDIN_CAP(*l))
    {
        ExpandListDin(l);
    }

    for (i =  GetListDinLastIdx(*l); i >= idx; i--)

    {
        LISTDIN_ELMT(*l, i + 1) = LISTDIN_ELMT(*l, i);
    }

    LISTDIN_ELMT(*l, idx) = val;
    LISTDIN_NEFF(*l)++;
}

/* *** Menambahkan elemen terakhir *** */
void InsertLastListDin(ListDin *l, ListDinElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, jika penuh maka kapasitas ditambah */
/* F.S. val adalah elemen terakhir l yang baru, kapasitas dapat bertambah */
{
	// KAMUS LOKAL
    // ALGORITMA

    if (ListDinLength(*l) >= LISTDIN_CAP(*l))
    {
        ExpandListDin(l);
    }

    LISTDIN_ELMT(*l, ListDinLength(*l)) = val;
    LISTDIN_NEFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void DeleteFirstListDin(ListDin *l, ListDinElType *val)
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong, kapasitas dapat dikurangi */
/* *** Menghapus elemen pada index tertentu *** */
{
	// KAMUS LOKAL
    // ALGORITMA

    DeleteAtListDin(l, val, 0);
}

void DeleteAtListDin(ListDin *l, ListDinElType *val, IdxType idx)
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong, kapasitas dapat dikurangi */
/* *** Menghapus elemen terakhir *** */
{
	// KAMUS LOKAL
    int i;

    // ALGORITMA

    *val = LISTDIN_ELMT(*l, idx);

    if (idx < GetListDinLastIdx(*l))
    {
        for (i = idx; i <= GetListDinLastIdx(*l) - 1; i++)
        {
            LISTDIN_ELMT(*l, i) = LISTDIN_ELMT(*l, i + 1);
        }
    }

    LISTDIN_NEFF(*l)--;

    if (ListDinLength(*l) <= LISTDIN_CAP(*l) / 4)
    {
        ShrinkListDin(l);
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void DeleteLastListDin(ListDin *l, ListDinElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong, kapasitas dapat dikurangi */
{
	// KAMUS LOKAL
    // ALGORITMA

    DeleteAtListDin(l, val, GetListDinLastIdx(*l));
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void ExpandListDin(ListDin *l)
/* Proses : Menambahkan capacity l menjadi 1.5 kali capacity semula */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah menjadi 1.5 kali ukuran semula */
{
    // KAMUS LOKAL
    int newCap;
    // ALGORITMA
    
    newCap = LISTDIN_CAP(*l) * 3 / 2;
    LISTDIN_BUFFER(*l) = realloc(LISTDIN_BUFFER(*l), newCap * sizeof(ListDinElType));
    LISTDIN_CAP(*l) = newCap;
   
}

void ShrinkListDin(ListDin *l)
/* Proses : Mengurangi capacity menjadi setengah semula atau MIN_LISTDIN_CAP*/
/* I.S. List sudah terdefinisi, isi list dinamis <= 1/4 capacity */
/* F.S. Ukuran list berkurang menjadi setengah ukuran awal atau MIN_LISTDIN_CAP. */
{
    // KAMUS LOKAL
    int newCap;
    // ALGORITMA
    
    newCap = (MIN_LISTDIN_CAP > LISTDIN_CAP(*l) / 2)? MIN_LISTDIN_CAP : LISTDIN_CAP(*l) / 2;
    LISTDIN_BUFFER(*l) = realloc(LISTDIN_BUFFER(*l), newCap * sizeof(ListDinElType));
    LISTDIN_CAP(*l) = newCap;
}

void CompressListDin(ListDin *l)
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    // KAMUS LOKAL
    // ALGORITMA
    
    int newCap;
    // ALGORITMA
    
    newCap = (MIN_LISTDIN_CAP > LISTDIN_NEFF(*l))? MIN_LISTDIN_CAP : LISTDIN_NEFF(*l);
    LISTDIN_BUFFER(*l) = realloc(LISTDIN_BUFFER(*l), newCap * sizeof(ListDinElType));
    LISTDIN_CAP(*l) = newCap;
}
