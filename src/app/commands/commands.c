/* C libraries */
#include <stdio.h>
#include <stdlib.h>

/* ADT */
#include "../../adt/waktu/waktu.h"

/* APP */
#include "commands.h"

void CreateNotif(Simulator *simulator, Word aksi, Word namaMakanan)
{
    Word notif, inverseNotif;

    notif = BLANK_WORD;
    ConcatWord(&notif, namaMakanan);
    ConcatWord(&notif, NewWord(" berhasil dibuat dan dimasukkan ke inventory", 44));

    inverseNotif = NewWord("Aksi ", 5);
    ConcatWord(&inverseNotif, aksi);
    ConcatWord(&inverseNotif, BLANK_WORD);
    ConcatWord(&inverseNotif, namaMakanan);
    ConcatWord(&inverseNotif, NewWord(" dibatalkan", 11));

    InsertFirstListDinElType(&simulator->Notification, NewElType(4, (union Data){.w = notif}));
    InsertFirstListDinElType(&simulator->InverseNotif, NewElType(4, (union Data){.w = inverseNotif}));
}

void Start(Simulator* simulator, ListStatik* foods, ListStatik* recipes, Map* map, ListDinElType* buyFoods, ListDinElType* mixFoods, ListDinElType* chopFoods, ListDinElType* fryFoods, ListDinElType* boilFoods, Stack *undoRecord, Stack *redoRecord){
    ReadAllConfig(map, foods, recipes);
    int i;

    CreateListDinElType(buyFoods, 0);
    CreateListDinElType(mixFoods, 0);
    CreateListDinElType(chopFoods, 0);
    CreateListDinElType(fryFoods, 0);
    CreateListDinElType(boilFoods, 0);

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

    CompressListDinElType(buyFoods);
    CompressListDinElType(mixFoods);
    CompressListDinElType(chopFoods);
    CompressListDinElType(fryFoods);
    CompressListDinElType(boilFoods);

    CreateEmptyStack(undoRecord);
    CreateEmptyStack(redoRecord);

    printf("\nMasukkan nama Anda: ");
    ADVWORD();
    CopyDefinedWord(&(*simulator).NamaPengguna, currentWord);

    CreateEmptySimulator(simulator, GetNamaPengguna(simulator));

    printf("Selamat datang ");
    DisplayWordLine(GetNamaPengguna(simulator));
}

void Buy(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType BuyFoods, Stack *undoRecord, boolean *success){

    Word notif, inverseNotif; 
    Makanan food;

    if(!(IsAdjacent((*simulator).Lokasi,T(map)))){
        DisplayWord(GetNamaPengguna(simulator));
        printf(" tidak berada di area telepon!\n");
    } else {
        BuyMenu(BuyFoods);
        int x;
        boolean end = false;
        while(!*success && !end){
            printf("Kirim 0 untuk exit\n");
            printf("Enter Command: ");
            ADVWORD();
            x = WordToInt(currentWord);
            if((x/10)+1!=currentWord.Length){
                printf("Input tidak valid!\n");
            } else {    
                x--;
                if(x==-1){
                    end = true;
                } else if (x>ListDinElTypeLength(BuyFoods)-1){
                    printf("Input tidak valid!\n");
                } else {
                    //beli makanan disini

                    // tambah waktu
                    TakeTime(simulator, 0, 0, 1, foods);

                    food = GetMakananFromId(foods,GetVal(BuyFoods.buffer[x]).m.Id);
                    Enqueue(&simulator->Delivery, GetVal(BuyFoods.buffer[x]).m.Id, 
                        food.WaktuAksi + GetTime(simulator));



                    // notifikasi
                    notif = BLANK_WORD;
                    ConcatWord(&notif, food.Nama);
                    ConcatWord(&notif, NewWord(" berhasil ditambahkan ke delivery", 33));

                    inverseNotif = BLANK_WORD;
                    ConcatWord(&inverseNotif, food.Nama);
                    ConcatWord(&inverseNotif, NewWord(" dibatalkan dari delivery", 25));

                    InsertFirstListDinElType(&simulator->Notification, NewElType(4, (union Data){.w=notif}));
                    InsertFirstListDinElType(&simulator->InverseNotif, NewElType(4, (union Data){.w=inverseNotif}));

                    *success = true;
                }
            }
        }
    }
}

void Mix(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType mixFoods, Stack *undoRecord, boolean *success){
    Waktu time;
    Word notif, inverseNotif; 
    boolean end;

    if(!(IsAdjacent((*simulator).Lokasi,M(map)))){
        DisplayWord(GetNamaPengguna(simulator));
        printf(" tidak berada di area mixing!\n");
    } else {
        MixMenu(mixFoods);
        if(IsListDinElTypeEmpty(mixFoods)){
            *success = true;
        }
        int x;
        end = false;
        while(!end && !*success){    
            printf("Kirim 0 untuk exit\n");
            //handle input harus integer
            printf("Enter Command: ");
            ADVWORD();
            x = WordToInt(currentWord);
            if((x/10)+1!=currentWord.Length){
                printf("Input tidak valid!\n");
            } else {
                x--;
                if(x==-1){
                    end = true;
                } else if (x>ListDinElTypeLength(mixFoods)-1){
                    printf("Input tidak valid!\n");
                } else {
                    Makanan dibuat = GetMakananFromId(foods, GetVal(mixFoods.buffer[x]).m.Id);
                    ListDin need; CreateListDin(&need,10);
                    int i,temp;
                    i=0;
                    while(IsListDinEmpty(need)){
                        if(IsPartOf(GetVal(LIST_ELMT(recipes,i)).t, dibuat.Id)){
                            need = GetChildren(GetSubTree(GetVal(LIST_ELMT(recipes,i)).t, dibuat.Id));
                        }
                        i++;
                    }
                    ListDin needLeft; //copy listdin need
                    CopyListDin(need, &needLeft);
                    int needLength = ListDinLength(need);
                    int needCount = 0;
                    for(i=0;i<needLength;i++){
                        //cek apakah ada di inventory
                        int j;
                        for(j=simulator->Inventory.Head;j<=simulator->Inventory.Tail;j++){
                            if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                                needCount++;
                                //hapus dari needLeft jika ada
                                DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                                break;
                            }
                        }
                    }
                    if(needCount==needLength){
                        *success = true;
                        //kurangi inventory
                        for(i=0;i<needLength;i++){
                            temp = DeleteMakanan(simulator, need.buffer[i]);
                        }

                        // notifikasi
                        CreateNotif(simulator, MIX_WORD, dibuat.Nama);

                        // tambah waktu
                        TakeTime(simulator, GetHari(dibuat.WaktuAksi), GetJam(dibuat.WaktuAksi), GetMenit(dibuat.WaktuAksi), foods);
                        
                        //tambah ke inventory
                        InsertMakanan(simulator, dibuat.Id, dibuat.Kedaluarsa);

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
}

void Chop(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType chopFoods, Stack *undoRecord, boolean *success){
    Waktu time;
    boolean end;

    if(!(IsAdjacent((*simulator).Lokasi,C(map)))){
        DisplayWord(GetNamaPengguna(simulator));
        printf(" tidak berada di area chopping!\n");
    } else {
        ChopMenu(chopFoods);
        if(IsListDinElTypeEmpty(chopFoods)){
            *success = true;
        }
        int x;
        while(!end && !*success){      
            printf("Kirim 0 untuk exit\n");
            //handle input harus integer
            printf("Enter Command: ");
            ADVWORD();
            x = WordToInt(currentWord);
            if((x/10)+1!=currentWord.Length){
                printf("Input tidak valid!\n");
            } else {
                x--;
                if(x==-1){
                    end = true;
                } else if (x>ListDinElTypeLength(chopFoods)-1){
                    printf("Input tidak valid!\n");
                } else {
                    Makanan dibuat = GetMakananFromId(foods, GetVal(chopFoods.buffer[x]).m.Id);
                    ListDin need; CreateListDin(&need,10);
                    int i,temp;
                    i=0;
                    while(IsListDinEmpty(need)){
                        if(IsPartOf(GetVal(LIST_ELMT(recipes,i)).t, dibuat.Id)){
                            need = GetChildren(GetSubTree(GetVal(LIST_ELMT(recipes,i)).t, dibuat.Id));
                        }
                        i++;
                    }
                    ListDin needLeft; //copy listdin need
                    CopyListDin(need, &needLeft);
                    int needLength = ListDinLength(need);
                    int needCount = 0;
                    for(i=0;i<needLength;i++){
                        //cek apakah ada di inventory
                        int j;
                        for(j=simulator->Inventory.Head;j<=simulator->Inventory.Tail;j++){
                            if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                                needCount++;
                                //hapus dari needLeft jika ada
                                DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                                break;
                            }
                        }
                    }
                    if(needCount==needLength){
                        *success = true;
                        //kurangi inventory
                        for(i=0;i<needLength;i++){
                            temp = DeleteMakanan(simulator, need.buffer[i]);
                        }

                        // notifikasi
                        CreateNotif(simulator, CHOP_WORD, dibuat.Nama);

                        // tambah waktu
                        TakeTime(simulator, GetHari(dibuat.WaktuAksi), GetJam(dibuat.WaktuAksi), GetMenit(dibuat.WaktuAksi), foods);

                        //tambah ke inventory
                        InsertMakanan(simulator, dibuat.Id, dibuat.Kedaluarsa);

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
}

void Fry(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType fryFoods, Stack *undoRecord, boolean *success){
    Waktu time;
    boolean end;
    if(!(IsAdjacent((*simulator).Lokasi,F(map)))){
        DisplayWord(GetNamaPengguna(simulator));
        printf(" tidak berada di area frying!\n");
    } else {
        FryMenu(fryFoods);
        if(IsListDinElTypeEmpty(fryFoods)){
            *success = true;
        }
        int x;
        end = false;
        while(!end && !*success){    
            printf("Kirim 0 untuk exit\n");
            //handle input harus integer
            printf("Enter Command: ");
            ADVWORD();
            x = WordToInt(currentWord);
            if((x/10)+1!=currentWord.Length){
                printf("Input tidak valid!\n");
            } else {
                x--;
                if(x==-1){
                    end = true;
                } else if (x>ListDinElTypeLength(fryFoods)-1){
                    printf("Input tidak valid!\n");
                } else {
                    Makanan dibuat = GetMakananFromId(foods, GetVal(fryFoods.buffer[x]).m.Id);
                    ListDin need; CreateListDin(&need,10);
                    int i,temp;
                    i=0;
                    while(IsListDinEmpty(need)){
                        if(IsPartOf(GetVal(LIST_ELMT(recipes,i)).t, dibuat.Id)){
                            need = GetChildren(GetSubTree(GetVal(LIST_ELMT(recipes,i)).t, dibuat.Id));
                        }
                        i++;
                    }
                    ListDin needLeft; //copy listdin need
                    CopyListDin(need, &needLeft);
                    int needLength = ListDinLength(need);
                    int needCount = 0;
                    for(i=0;i<needLength;i++){
                        //cek apakah ada di inventory
                        int j;
                        for(j=simulator->Inventory.Head;j<=simulator->Inventory.Tail;j++){
                            if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                                needCount++;
                                //hapus dari needLeft jika ada
                                DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                                break;
                            }
                        }
                    }
                    if(needCount==needLength){
                        *success = true;
                        //kurangi inventory
                        for(i=0;i<needLength;i++){
                            temp = DeleteMakanan(simulator, need.buffer[i]);
                        }

                        // notifikasi
                        CreateNotif(simulator, FRY_WORD, dibuat.Nama);

                        // tambah waktu
                        TakeTime(simulator, GetHari(dibuat.WaktuAksi), GetJam(dibuat.WaktuAksi), GetMenit(dibuat.WaktuAksi), foods);

                        //tambah ke inventory
                        InsertMakanan(simulator, dibuat.Id, dibuat.Kedaluarsa);


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
}

void Boil(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType boilFoods, Stack *undoRecord, boolean *success){
    Waktu time;
    boolean end;

    if(!(IsAdjacent((*simulator).Lokasi,B(map)))){
        DisplayWord(GetNamaPengguna(simulator));
        printf(" tidak berada di area mixing!\n");
    } else {
        BoilMenu(boilFoods);
        if(IsListDinElTypeEmpty(boilFoods)){
            *success = true;
        }
        end = false;
        int x;
        while(!*success && !end){
            printf("Kirim 0 untuk exit\n");
            //handle input harus integer
            printf("Enter Command: ");
            ADVWORD();
            x = WordToInt(currentWord);
            if((x/10)+1!=currentWord.Length){
                printf("Input tidak valid!\n");
            } else {
                x--;
                if(x==-1){
                    end = true;
                } else if (x>ListDinElTypeLength(boilFoods)-1){
                    printf("Input tidak valid!\n");
                } else {
                    Makanan dibuat = GetMakananFromId(foods, GetVal(boilFoods.buffer[x]).m.Id);
                    ListDin need; CreateListDin(&need,10);
                    int i,temp;
                    i=0;
                    while(IsListDinEmpty(need)){
                        if(IsPartOf(GetVal(LIST_ELMT(recipes,i)).t, dibuat.Id)){
                            need = GetChildren(GetSubTree(GetVal(LIST_ELMT(recipes,i)).t, dibuat.Id));
                        }
                        i++;
                    }
                    ListDin needLeft; //copy listdin need
                    CopyListDin(need, &needLeft);
                    int needLength = ListDinLength(need);
                    int needCount = 0;
                    for(i=0;i<needLength;i++){
                        //cek apakah ada di inventory
                        int j;
                        for(j=simulator->Inventory.Head;j<=simulator->Inventory.Tail;j++){
                            if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                                needCount++;
                                //hapus dari needLeft jika ada
                                DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                                break;
                            }
                        }
                    }
                    if(needCount==needLength){
                        *success = true;

                        //kurangi inventory
                        for(i=0;i<needLength;i++){
                            temp = DeleteMakanan(simulator, need.buffer[i]);
                        }

                        // notifikasi
                        CreateNotif(simulator, BOIL_WORD, dibuat.Nama);

                        // tambah waktu
                        TakeTime(simulator, GetHari(dibuat.WaktuAksi), GetJam(dibuat.WaktuAksi), GetMenit(dibuat.WaktuAksi), foods);

                        //tambah ke inventory
                        InsertMakanan(simulator, dibuat.Id, dibuat.Kedaluarsa);
                        
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
}

void Move(Simulator *simulator, Map *map, int moveCode, ListStatik foods, boolean *success)
// 0 : east, 1 : west, 2 : north, 3 : south
{
    Point currentLocation = GetLokasi(simulator);
    Point newPoint = currentLocation;

    // command move tidak valid
    if (moveCode == 0 && ((GetOrdinat(currentLocation) + 1 > GetLastIdxCol(TAB(*map))) 
            || (MAT_ELMT(TAB(*map), GetAbsis(currentLocation), GetOrdinat(currentLocation) + 1) != '#'))

        || (moveCode == 1 && ((GetOrdinat(currentLocation) - 1 < 0) 
            || MAT_ELMT(TAB(*map), GetAbsis(currentLocation), GetOrdinat(currentLocation) - 1) != '#'))

        || (moveCode == 2 && ((GetAbsis(currentLocation) - 1 < 0) 
            || MAT_ELMT(TAB(*map), GetAbsis(currentLocation) - 1, GetOrdinat(currentLocation)) != '#'))

        || (moveCode == 3 && ((GetAbsis(currentLocation) + 1 > GetLastIdxRow(TAB(*map))) 
            || MAT_ELMT(TAB(*map), GetAbsis(currentLocation) + 1, GetOrdinat(currentLocation)) != '#')))

    {
        printf("Input move tidak valid karena lokasi tidak dapat ditempati!\n");
    }

    else {
        if (moveCode == 0)
        {
            MovePointEast(&newPoint);
        }

        else if (moveCode == 1)
        {
            MovePointWest(&newPoint);
        }

        else if (moveCode == 2)
        {
            MovePointNorth(&newPoint);
        }

        else if (moveCode == 3)
        {
            MovePointSouth(&newPoint);
        }

        SetLokasi(simulator, newPoint);
        MoveSimulator(map, newPoint);
        TakeTime(simulator, 0, 0, 1, foods);
        *success = true;

    }
}

void resetState(Simulator* simulator, Record record, Map *map, ListStatik foods)
{
    int id, i;
    Waktu time;
    PrioQueue p;
    ListDinElType l;
    ElType val;

    CreateEmptyPQ(&p);

    SetTime(simulator, record.Time);
    SetLokasi(simulator, record.SimulatorLoc);
    MoveSimulator(map, record.SimulatorLoc);

    
    SetNotif(simulator, record.InverseNotification, record.Notification);

    AssignPQ(record.DeliveryAdd, &p);
    while(!IsEmptyPQ(p))
    {
        Dequeue(&p, &id, &time);
        DeleteElmtPQ(&simulator->Delivery, id, time);
    }

    AssignPQ(record.DeliveryDel, &p);
    while(!IsEmptyPQ(p))
    {
        Dequeue(&p, &id, &time);
        Enqueue(&simulator->Delivery, id, time);
    }

    AssignPQ(record.InventoryAdd, &p);
    while(!IsEmptyPQ(p))
    {
        Dequeue(&p, &id, &time);
        DeleteElmtPQ(&simulator->Inventory, id, time);
    }

    AssignPQ(record.InventoryDel, &p);
    while(!IsEmptyPQ(p))
    {
        Dequeue(&p, &id, &time);
        Enqueue(&simulator->Inventory, id, time);
    }

    DeallocatePQ(&p);

    CopyListDinElType(record.KulkasAdd, &l);
    
    // HANYA SALAH SATU YANG DAPAT TERJADI, YAITU ANTARA BEBERAPA MAKANAN DIKELUARKAN ATAU DIMASUKKAN KE DALAM KULKAS
    for(i = ListDinElTypeLength(l) - 1; i >= 0; i--)
    {
        TakeFood(simulator, l.buffer[i].val.mk.idx + 1, false);
    }

    CopyListDinElType(record.KulkasDel, &l);
    for(i = 0; i < ListDinElTypeLength(l); i++)
    {
        // printf("undo idx : %d", l.buffer[i].val.mk.idx);
        PutFood(simulator, l.buffer[i].val.mk.makanan, l.buffer[i].val.mk.kiriAtas.x, l.buffer[i].val.mk.kiriAtas.y, false, foods, false, l.buffer[i].val.mk.idx);
    }
    
}
void Undo (Simulator* simulator, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *undoStack, Stack *redoStack, Waktu timeRecord, Point locRecord, Map *map, ListStatik foods)
{
    Record undoRecord;

    if (!IsStackEmpty(*undoStack))
    {
        PopStack(undoStack, &undoRecord);

        resetState(simulator, undoRecord, map, foods);

        UpdateInverse(simulator, undoRecord, redoStack, timeRecord, locRecord);
    }

    else{
        printf("Tidak ada aksi yang dapat di undo!\n");
    }
}

void Redo (Simulator* simulator, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *undoStack, Stack *redoStack, Waktu timeRecord, Point locRecord, Map *map, ListStatik foods)
{   
    Record prevRecord, redoRecord;

    if (!IsStackEmpty(*redoStack))
    {

        PopStack(redoStack, &redoRecord);

        resetState(simulator, redoRecord, map, foods);

        UpdateInverse(simulator, redoRecord, undoStack, timeRecord, locRecord);

    }

    else{
        printf("Tidak ada aksi yang dapat di redo!\n");
    }
}

void UpdateStack(Simulator *simulator, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *stack, Waktu timeRecord, Point locRecord, ListDinElType kulkasRecord)
{
    Record newRecord;
    newRecord.Time = timeRecord;
    newRecord.SimulatorLoc.x = GetAbsis(locRecord);
    newRecord.SimulatorLoc.y = GetOrdinat(locRecord);

    CopyListDinElType(simulator->Notification, &newRecord.Notification);
    CopyListDinElType(simulator->InverseNotif, &newRecord.InverseNotification);

    CreateEmptyPQ(&newRecord.DeliveryAdd);
    CreateEmptyPQ(&newRecord.DeliveryDel);
    CreateEmptyPQ(&newRecord.InventoryAdd);
    CreateEmptyPQ(&newRecord.InventoryDel);

    GetQueueChanges(&newRecord.DeliveryAdd, &newRecord.DeliveryDel, deliveryRecord, simulator->Delivery);
    GetQueueChanges(&newRecord.InventoryAdd, &newRecord.InventoryDel, inventoryRecord, simulator->Inventory);

    GetListChanges(simulator, &newRecord.KulkasAdd, &newRecord.KulkasDel, kulkasRecord, simulator->MakananKulkas);

    PushStack(stack, newRecord);
}

void UpdateInverse(Simulator *simulator, Record inverseRecord, Stack *stack, Waktu timeRecord, Point locRecord)
{
    Record newRecord;
    int i;

    newRecord.Time = timeRecord;
    newRecord.SimulatorLoc.x = GetAbsis(locRecord);
    newRecord.SimulatorLoc.y = GetOrdinat(locRecord);
    
    CopyListDinElType(inverseRecord.InverseNotification, &newRecord.Notification);
    CopyListDinElType(inverseRecord.Notification, &newRecord.InverseNotification);
    
    CreateEmptyPQ(&newRecord.DeliveryAdd);
    CreateEmptyPQ(&newRecord.DeliveryDel);
    CreateEmptyPQ(&newRecord.InventoryAdd);
    CreateEmptyPQ(&newRecord.InventoryDel);

    AssignPQ(inverseRecord.DeliveryDel,&newRecord.DeliveryAdd);
    AssignPQ(inverseRecord.DeliveryAdd,&newRecord.DeliveryDel);
    AssignPQ(inverseRecord.InventoryDel,&newRecord.InventoryAdd);
    AssignPQ(inverseRecord.InventoryAdd,&newRecord.InventoryDel);

    CopyListDinElType(inverseRecord.KulkasAdd, &newRecord.KulkasDel);
    CopyListDinElType(inverseRecord.KulkasDel, &newRecord.KulkasAdd);

    PushStack(stack, newRecord);

    for(i=0; i<ListDinElTypeLength(simulator->MakananKulkas); i++)
    {
        simulator->MakananKulkas.buffer[i].val.mk.idx = i;
    }

}

void GetListChanges (Simulator *simulator, ListDinElType *addChanges, ListDinElType *delChanges, ListDinElType prevListRef, ListDinElType currentListRef)
{
    int i, count, length;

    boolean found;
    ElType val;

    if (ListDinElTypeLength(prevListRef) > ListDinElTypeLength(currentListRef))
    {
        length = ListDinElTypeLength(prevListRef) - ListDinElTypeLength(currentListRef);
        CreateListDinElType(addChanges, 0);
        CreateListDinElType(delChanges, length);

        for (count = 0; count < length; count++)
        {
            i = 0;
            found = false;
            while(i < ListDinElTypeLength(currentListRef) && !found)
            {
                if (prevListRef.buffer[i].val.mk.idx != currentListRef.buffer[i].val.mk.idx)
                {
                    // printf("idx saat found :%d\n", prevListRef.buffer[i].val.mk.idx);
                    found = true;
                }

                else
                {
                    i++;
                }
            }

            val =  prevListRef.buffer[i];
            // printf("idx undo now :%d\n", val.val.mk.idx);
            InsertLastListDinElType(delChanges, val);
            
        }
    }

    else if (ListDinElTypeLength(prevListRef) < ListDinElTypeLength(currentListRef))
    {
        length = ListDinElTypeLength(currentListRef) - ListDinElTypeLength(prevListRef);
        CreateListDinElType(addChanges, length);
        CreateListDinElType(delChanges, 0);

        for(i = ListDinElTypeLength(prevListRef); i < ListDinElTypeLength(currentListRef); i++)
        {
            val = currentListRef.buffer[i];
            InsertLastListDinElType(addChanges, val);
        }
    }

}

void GetQueueChanges(PrioQueue *addChanges, PrioQueue *delChanges, PrioQueue prevQueueRef, PrioQueue currentQueueRef)
{
    int i;
    int val;
    Waktu t;
    PrioQueue prevQueue, currentQueue;

    CreateEmptyPQ(&prevQueue);
    CreateEmptyPQ(&currentQueue);
    AssignPQ(prevQueueRef, &prevQueue);
    AssignPQ(currentQueueRef, &currentQueue);
    
    while (!IsEmptyPQ(prevQueue) && !IsEmptyPQ(currentQueue))
    {
        
        if (GetHeadTime(prevQueue) == GetHeadTime(currentQueue))
        {
            if (GetHeadInfo(prevQueue) == GetHeadInfo(currentQueue))
            {
                Dequeue(&prevQueue, &val, &t);
                Dequeue(&currentQueue, &val, &t);
            }

            else if (GetHeadInfo(prevQueue) > GetHeadInfo(currentQueue)) {
                Dequeue(&currentQueue, &val, &t);
                Enqueue(addChanges, val, t);
            }

            else {
                Dequeue(&prevQueue, &val, &t);
                Enqueue(delChanges, val, t);
            }
        }

        else if (GetHeadTime(prevQueue) > GetHeadTime(currentQueue)) {
            Dequeue(&currentQueue, &val, &t);
            Enqueue(addChanges, val, t);
        }
        else {
            Dequeue(&prevQueue, &val, &t);
            Enqueue(delChanges, val, t);
        }
    }
    
    while(!IsEmptyPQ(prevQueue))
    {
        Dequeue(&prevQueue, &val, &t);
        Enqueue(delChanges, val, t);
    }

    while(!IsEmptyPQ(currentQueue))
    {
        Dequeue(&currentQueue, &val, &t);
        Enqueue(addChanges, val, t);
    }

    DeallocatePQ(&prevQueue);
    DeallocatePQ(&currentQueue);
}

boolean CheckSizeKulkas(Simulator sim, Makanan food, int X, int Y, boolean rotated){
    if(rotated){
        food.SizeX = food.SizeX ^ food.SizeY;
        food.SizeY = food.SizeX ^ food.SizeY;
        food.SizeX = food.SizeX ^ food.SizeY;
    }
    int endX = food.SizeX + X - 1;
    int endY = food.SizeY + Y - 1;
    if(endX>GetLastIdxCol(sim.Kulkas) || endY>GetLastIdxRow(sim.Kulkas)){
        return false;
    }
    int i,j;
    for(i=X;i<=endX;i++){
        for(j=Y;j<=endY;j++){
            if(MAT_ELMT(sim.Kulkas,j,i)!=0){
                return false;
            }
        }
    }
    return true;
}

void Kulkas(Simulator *simulator, ListStatik foods, Map map, boolean *success){
    boolean end;
    Waktu time;
    Word notif, inverseNotif;

    if(!(IsAdjacent(simulator->Lokasi,K(map)))){
        DisplayWord(GetNamaPengguna(simulator));
        printf(" tidak berada di area kulkas!\n");
    } else {
        DisplayKulkas(foods, *simulator);
        end = false;
        int x,i;
        while(!end){
            printf("Kirim 0 untuk exit\n");
            printf("Enter Command: ");
            ADVWORD();
            x = WordToInt(currentWord);
            if((x/10)+1!=currentWord.Length || x<0 || x>2){
                printf("Input tidak valid!\n");
            } else{
                x--;
                if(x==-1){
                    end = true;
                } else {
                    if(x==0){
                        // Handling bila inventory kosong
                        if(IsEmptyPQ(simulator->Inventory)){
                            printf("Inventory kosong!\n");
                            return;
                        }
                        boolean berhasil;
                        // Pilih Makanan yang ingin Dimasukkan
                        printf("Makanan di inventory:\n");
                        printf("( Makanan - Kedaluwarsa - Ukuran(X,Y) )\n");
                        for(i=0;i<LengthPQ(simulator->Inventory);i++){
                            printf(" %d. ",i+1);
                            time = GetElmtTime(simulator->Inventory,i) - GetTime(simulator);
                            DisplayWord(GetNama(GetMakananFromId(foods,GetElmtInfo(simulator->Inventory,i))));
                            printf(" - ");
                            if(GetHari(time)!=0){
                                printf("%d hari ",GetHari(time));
                            }
                            if(GetJam(time)!=0){
                                printf("%d jam ",GetJam(time));
                            }
                            if(GetMenit(time)!=0){
                                printf("%d menit ",GetMenit(time));
                            }
                            printf(" - ");
                            printf("(%d,%d)\n",GetSizeX(GetMakananFromId(foods,GetElmtInfo(simulator->Inventory,i))),GetSizeY(GetMakananFromId(foods,GetElmtInfo(simulator->Inventory,i))));
                        }
                        berhasil = false;
                        while(!berhasil){
                            printf("Masukkan nomor makanan yang ingin diletakkan: ");
                            ADVWORD();
                            x = WordToInt(currentWord);
                            if((x/10)+1!=currentWord.Length){
                                printf("Input tidak valid!\n");
                            } else if (x>LengthPQ(simulator->Inventory) || x<1){
                                printf("Input tidak valid!\n");
                            } else {
                                berhasil = true;
                            }
                        }
                        x--;
                        // Pilih posisi makanan di kulkas (koordinat kiri atas)
                        int a,b;
                        berhasil = false;
                        while(!berhasil){
                            printf("Koordinat atas kiri adalah (0,0)\n");
                            printf("Koordinat kiri atas makanan yang ingin diletakkan\n");
                            printf("Masukkan koordinat X yang ingin ditempati: ");
                            ADVWORD();
                            a = WordToInt(currentWord);
                            if((a/10)+1!=currentWord.Length){
                                printf("Input tidak valid!\n");
                            } else if(a>19 || a<0){
                                printf("Input tidak valid!\n");
                            } else{
                                printf("Masukkan koordinat Y yang ingin ditempati: ");
                                ADVWORD();
                                b = WordToInt(currentWord);
                                if((b/10)+1!=currentWord.Length){
                                    printf("Input tidak valid!\n");
                                } else if (b>9 || b<0){
                                    printf("Input tidak valid!\n");
                                } else{
                                    berhasil = true;
                                }
                            }
                        }
                        boolean putar;
                        berhasil = false;
                        while(!berhasil){
                            printf("Putar? (y/n): ");
                            ADVWORD();
                            if(currentWord.Length==1){
                                if(currentWord.TabWord[0]=='y'){
                                    putar = true;
                                    berhasil = true;
                                } else if (currentWord.TabWord[0]=='n'){
                                    putar = false;
                                    berhasil = true;
                                } else {
                                    printf("Input tidak valid!\n");
                                }
                            } else {
                                printf("Input tidak valid!\n");
                            }
                        }
                        Makanan makanan = GetMakananFromId(foods,GetElmtInfo(simulator->Inventory,x));
                        makanan.Kedaluarsa  = GetElmtTime(simulator->Inventory,x) - GetTime(simulator);
                        if(CheckSizeKulkas(*simulator, makanan, a, b, putar)){
                            PutFood(simulator, makanan, a, b, putar, foods, true, -1);
                            end = true;
                            *success = true;
                            TakeTime(simulator, 0, 0, 1, foods);
                        } else{
                            printf("Makanan tidak muat!\n");
                        }
                    } else{
                        if(IsKulkasEmpty(*simulator)){
                            printf("Kulkas kosong!\n");
                        } else {
                            printf("Masukkan id dari makanan yang ingin diambil: ");
                            ADVWORD();
                            x = WordToInt(currentWord);
                            if((x/10)+1!=currentWord.Length){
                                printf("Input tidak valid!\n");
                            } else{
                                TakeFood(simulator, x, true);
                                *success = true;
                                TakeTime(simulator, 0, 0, 1, foods);
                            }
                        }
                        end = true;
                    }
                }
            }
        }
    }
}