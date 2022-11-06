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

    inverseNotif = aksi;
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

    printf("Masukkan nama Anda: ");
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
        while(!*success&!end){
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

                    food = GetMakananFromId(foods,GetVal(BuyFoods.buffer[x]).m.Id);
                    Enqueue(&simulator->Delivery, GetVal(BuyFoods.buffer[x]).m.Id, 
                        food.WaktuAksi + GetTime(simulator) + 1);



                    // notifikasi
                    notif = BLANK_WORD;
                    ConcatWord(&notif, food.Nama);
                    ConcatWord(&notif, NewWord(" berhasil ditambahkan ke delivery", 33));

                    inverseNotif = BLANK_WORD;
                    ConcatWord(&inverseNotif, food.Nama);
                    ConcatWord(&inverseNotif, NewWord(" dibatalkan dari delivery", 25));

                    InsertFirstListDinElType(&simulator->Notification, NewElType(4, (union Data){.w=notif}));
                    InsertFirstListDinElType(&simulator->InverseNotif, NewElType(4, (union Data){.w=inverseNotif}));
         
                    // tambah waktu
                    TakeTime(simulator, 0, 0, 1, foods);

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

                        //tambah ke inventory
                        InsertMakanan(simulator, dibuat.Id, dibuat.Kedaluarsa);

                        // tambah waktu
                        TakeTime(simulator, GetHari(dibuat.WaktuAksi), GetJam(dibuat.WaktuAksi), GetMenit(dibuat.WaktuAksi), foods);

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
                        CreateNotif(simulator, MIX_WORD, dibuat.Nama);

                        //tambah ke inventory
                        InsertMakanan(simulator, dibuat.Id, dibuat.Kedaluarsa);

                        // tambah waktu
                        TakeTime(simulator, GetHari(dibuat.WaktuAksi), GetJam(dibuat.WaktuAksi), GetMenit(dibuat.WaktuAksi), foods);

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
                        CreateNotif(simulator, MIX_WORD, dibuat.Nama);

                        //tambah ke inventory
                        InsertMakanan(simulator, dibuat.Id, dibuat.Kedaluarsa);

                        // tambah waktu
                        TakeTime(simulator, GetHari(dibuat.WaktuAksi), GetJam(dibuat.WaktuAksi), GetMenit(dibuat.WaktuAksi), foods);

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
                        CreateNotif(simulator, MIX_WORD, dibuat.Nama);

                        //tambah ke inventory
                        InsertMakanan(simulator, dibuat.Id, dibuat.Kedaluarsa);

                        // tambah waktu
                        TakeTime(simulator, GetHari(dibuat.WaktuAksi), GetJam(dibuat.WaktuAksi), GetMenit(dibuat.WaktuAksi), foods);
                        
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

void resetState(Simulator* simulator, Record record, Map *map)
{
    int id;
    Waktu time;
    PrioQueue p;

    CreateEmptyPQ(&p);

    SetTime(simulator, record.Time);
    SetLokasi(simulator, record.SimulatorLoc);
    MoveSimulator(map, record.SimulatorLoc);

    
    SetNotif(simulator, record.InverseNotification, record.Notification);
    printf("undo finished\n");
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
    
}
void Undo (Simulator* simulator, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *undoStack, Stack *redoStack, Waktu timeRecord, Point locRecord, Map *map)
{
    Record undoRecord;

    if (!IsStackEmpty(*undoStack))
    {
        PopStack(undoStack, &undoRecord);

        resetState(simulator, undoRecord, map);

        UpdateInverse(*simulator, undoRecord, redoStack, timeRecord, locRecord);
    }
}

void Redo (Simulator* simulator, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *undoStack, Stack *redoStack, Waktu timeRecord, Point locRecord, Map *map)
{   
    Record prevRecord, redoRecord;

    if (!IsStackEmpty(*redoStack))
    {

        PopStack(redoStack, &redoRecord);

        resetState(simulator, redoRecord, map);

        UpdateInverse(*simulator, redoRecord, undoStack, timeRecord, locRecord);

    }
}

void UpdateStack(Simulator simulator, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *stack, Waktu timeRecord, Point locRecord)
{
    Record newRecord;
    newRecord.Time = timeRecord;
    newRecord.SimulatorLoc.x = GetAbsis(locRecord);
    newRecord.SimulatorLoc.y = GetOrdinat(locRecord);

    CopyListDinElType(simulator.Notification, &newRecord.Notification);
    CopyListDinElType(simulator.InverseNotif, &newRecord.InverseNotification);

    CreateEmptyPQ(&newRecord.DeliveryAdd);
    CreateEmptyPQ(&newRecord.DeliveryDel);
    CreateEmptyPQ(&newRecord.InventoryAdd);
    CreateEmptyPQ(&newRecord.InventoryDel);


    GetQueueChanges(&newRecord.DeliveryAdd, &newRecord.DeliveryDel, deliveryRecord, simulator.Delivery);
    GetQueueChanges(&newRecord.InventoryAdd, &newRecord.InventoryDel, inventoryRecord, simulator.Inventory);


    PushStack(stack, newRecord);
}

void UpdateInverse(Simulator simulator, Record inverseRecord, Stack *stack, Waktu timeRecord, Point locRecord)
{
    Record newRecord;

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

    PushStack(stack, newRecord);

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