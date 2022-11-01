/* C libraries */
#include <stdio.h>
#include <stdlib.h>
/* APP */
#include "../headers/commands.h"

void Start(Simulator* simulator, ListStatik* foods, ListStatik* recipes, Map* map, ListDinElType* buyFoods, ListDinElType* mixFoods, ListDinElType* chopFoods, ListDinElType* fryFoods, ListDinElType* boilFoods, PrioQueue *delivery, Stack *undoRecord, Stack *redoRecord){
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
    // CopyDefinedWord(&(*simulator).NamaPengguna, currentWord);
    (*simulator).NamaPengguna = currentWord;

    printf("Selamat datang ");
    DisplayWordLine(GetNamaPengguna(simulator));

    CreateEmptySimulator(simulator, GetNamaPengguna(simulator));
}

void Exit(){
    printf("Exiting the simulator...\n");
    exit(0);
}

void Buy(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType BuyFoods, PrioQueue *delivery, Stack *undoRecord){
    if(!(IsAdjacent((*simulator).Lokasi,T(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area telepon!\n");
    } else {
        BuyMenu(BuyFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(BuyFoods)){
                printf("Out of range!\n");
            } else {
                //beli makanan disini
                Enqueue(delivery, GetVal(BuyFoods.buffer[x]).m.Id, GetMakananFromId(foods,GetVal(BuyFoods.buffer[x]).m.Id).Pengiriman);
            }
        }
    }
}

void Mix(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType mixFoods, Stack *undoRecord){
    Waktu time;

    if(!(IsAdjacent((*simulator).Lokasi,M(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area mixing!\n");
    } else {
        MixMenu(mixFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(mixFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(mixFoods.buffer[x]).m.Id);
                ListDin need; CreateListDin(&need,10);
                while(IsListDinEmpty(need)){
                    need = GetChildren(GetVal(LIST_ELMT(recipes,x)).t);
                }
                ListDin needLeft; //copy listdin need
                CopyListDin(need, &needLeft);
                int needLength = ListDinLength(need);
                int needCount = 0;
                int i,temp;
                for(i=0;i<needLength;i++){
                    //cek apakah ada di inventory
                    int j;
                    for(j=0;j<LengthPQ((*simulator).Inventory);j++){
                        if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                            needCount++;
                            break;
                        }
                    }
                    //hapus dari needLeft
                    DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                }
                if(needCount==needLength){
                    success = true;
                    //kurangi inventory
                    for(i=0;i<needLength;i++){
                        DeleteAtPQ(&(*simulator).Inventory, &temp, &time, need.buffer[i]);
                    }
                    //tambah ke inventory
                    Enqueue(&(*simulator).Inventory, dibuat.Id, dibuat.Kedaluarsa);
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

void Chop(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType chopFoods, Stack *undoRecord){
    Waktu time;

    if(!(IsAdjacent((*simulator).Lokasi,C(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area pemotongan!\n");
    } else {
        ChopMenu(chopFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(chopFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(chopFoods.buffer[x]).m.Id);
                ListDin need; CreateListDin(&need,10);
                while(IsListDinEmpty(need)){
                    need = GetChildren(GetVal(LIST_ELMT(recipes,x)).t);
                }
                ListDin needLeft; //copy listdin need
                CopyListDin(need, &needLeft);
                int needLength = ListDinLength(need);
                int needCount = 0;
                int i,temp;
                for(i=0;i<needLength;i++){
                    //cek apakah ada di inventory
                    int j;
                    for(j=0;j<LengthPQ((*simulator).Inventory);j++){
                        if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                            needCount++;
                            break;
                        }
                    }
                    //hapus dari needLeft
                    DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                }
                if(needCount==needLength){
                    success = true;
                    //kurangi inventory
                    for(i=0;i<needLength;i++){
                        DeleteAtPQ(&(*simulator).Inventory, &temp, &time, need.buffer[i]);
                    }
                    //tambah ke inventory
                    Enqueue(&(*simulator).Inventory, dibuat.Id, dibuat.Kedaluarsa);
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

void Fry(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType fryFoods, Stack *undoRecord){
    Waktu time;

    if(!(IsAdjacent((*simulator).Lokasi,F(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area penggorengan!\n");
    } else {
        FryMenu(fryFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(fryFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(fryFoods.buffer[x]).m.Id);
                ListDin need; CreateListDin(&need,10);
                while(IsListDinEmpty(need)){
                    need = GetChildren(GetVal(LIST_ELMT(recipes,x)).t);
                }
                ListDin needLeft; //copy listdin need
                CopyListDin(need, &needLeft);
                int needLength = ListDinLength(need);
                int needCount = 0;
                int i,temp;
                for(i=0;i<needLength;i++){
                    //cek apakah ada di inventory
                    int j;
                    for(j=0;j<LengthPQ((*simulator).Inventory);j++){
                        if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                            needCount++;
                            break;
                        }
                    }
                    //hapus dari needLeft
                    DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                }
                if(needCount==needLength){
                    success = true;
                    //kurangi inventory
                    for(i=0;i<needLength;i++){
                        DeleteAtPQ(&(*simulator).Inventory, &temp, &time, need.buffer[i]);
                    }
                    //tambah ke inventory
                    Enqueue(&(*simulator).Inventory, dibuat.Id, dibuat.Kedaluarsa);
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

void Boil(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map, ListDinElType boilFoods, Stack *undoRecord){
    Waktu time;
    if(!(IsAdjacent((*simulator).Lokasi,B(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area perebusan!\n");
    } else {
        BoilMenu(boilFoods);
        int x; boolean success = false;
        while(!success){
            printf("Enter Command: ");scanf("%d",&x);
            x--;
            if(x==-1){
                success = true;
            } else if (x>ListDinElTypeLength(boilFoods)){
                printf("Out of range!\n");
            } else {
                Makanan dibuat = GetMakananFromId(foods, GetVal(boilFoods.buffer[x]).m.Id);
                ListDin need; CreateListDin(&need,10);
                while(IsListDinEmpty(need)){
                    need = GetChildren(GetVal(LIST_ELMT(recipes,x)).t);
                }
                ListDin needLeft; //copy listdin need
                CopyListDin(need, &needLeft);
                int needLength = ListDinLength(need);
                int needCount = 0;
                int i,temp;
                for(i=0;i<needLength;i++){
                    //cek apakah ada di inventory
                    int j;
                    for(j=0;j<LengthPQ((*simulator).Inventory);j++){
                        if(need.buffer[i]==(*simulator).Inventory.Tab[j].Info){
                            needCount++;
                            break;
                        }
                    }
                    //hapus dari needLeft
                    DeleteAtListDin(&needLeft, &temp,ListDinIndexOf(needLeft, need.buffer[i]));
                }
                if(needCount==needLength){
                    success = true;
                    //kurangi inventory
                    for(i=0;i<needLength;i++){
                        DeleteAtPQ(&(*simulator).Inventory, &temp, &time, need.buffer[i]);
                    }
                    //tambah ke inventory
                    Enqueue(&(*simulator).Inventory, dibuat.Id, dibuat.Kedaluarsa);
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

void Move(Simulator *simulator, Map *map, int moveCode)
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
    }
}

void Undo (Simulator* simulator, PrioQueue delivery, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *undoStack, Stack *redoStack)
{
    Record prevRecord, redoRecord;

    PopStack(undoStack, &prevRecord);

    UpdateStack(*simulator, delivery, inventoryRecord, deliveryRecord, redoStack);
    UpdateInverse(*simulator, prevRecord, undoStack);
}

void UpdateStack(Simulator simulator, PrioQueue delivery, PrioQueue inventoryRecord, PrioQueue deliveryRecord, Stack *stack)
{
    Record newRecord;

    newRecord.Time = GetTime(&simulator);
    newRecord.SimulatorLoc = GetLokasi(&simulator);

    GetQueueChanges(&newRecord.DeliveryAdd, &newRecord.DeliveryDel, deliveryRecord, delivery);
    GetQueueChanges(&newRecord.InventoryAdd, &newRecord.InventoryDel, inventoryRecord, simulator.Inventory);

    PushStack(stack, newRecord);
}

void UpdateInverse(Simulator simulator, Record inverseRecord, Stack *stack)
{
    Record newRecord;

    newRecord.Time = GetTime(&simulator);
    newRecord.SimulatorLoc = GetLokasi(&simulator);

    newRecord.DeliveryAdd = inverseRecord.DeliveryDel;
    newRecord.DeliveryDel = inverseRecord.DeliveryAdd;
    newRecord.InventoryAdd = inverseRecord.DeliveryDel;
    newRecord.InventoryDel = inverseRecord.DeliveryAdd;

    PushStack(stack, newRecord);

}

void GetQueueChanges(PrioQueue *addChanges, PrioQueue *delChanges, PrioQueue prevQueue, PrioQueue currentQueue)
{
    int i;
    PrioQueue prev, current;
    PQElType val;
    Waktu t;

    prev = prevQueue;
    currentQueue = currentQueue;

    while (IsEmptyPQ(prevQueue) == false && IsEmptyPQ(currentQueue) == false)
    {
        if (GetHeadTime(prevQueue) == GetHeadTime(currentQueue))
        {
            if (GetHeadInfo(prevQueue) == currentQueue.Tab[i].Info)
            {
                Dequeue(&prevQueue, &val, &t);
                Dequeue(&currentQueue, &val, &t);
            }

            else if (GetHeadInfo(prevQueue) > currentQueue.Tab[i].Info) {
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

    while(IsEmptyPQ(prevQueue) == false)
    {
        Dequeue(&prevQueue, &val, &t);
        Enqueue(delChanges, val, t);
    }

    while(IsEmptyPQ(currentQueue) == false)
    {
        Dequeue(&currentQueue, &val, &t);
        Enqueue(addChanges, val, t);
    }
}