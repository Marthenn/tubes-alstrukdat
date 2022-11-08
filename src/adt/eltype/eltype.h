#ifndef ELTYPE_H
#define ELTYPE_H

/* ADT */
#include "../../boolean.h"
#include "../makanan/makanan.h"
#include "../tree/tree.h"

typedef struct MakananKulkas{
    Makanan makanan;
    Point kiriAtas;
    boolean rotated;
    int idx;
} MakananKulkas;

union Data{
    /*type 0*/ int i;
    /*type 1*/ float f;
    /*type 2*/ char c;
    /*type 3*/ Makanan m;
    /*type 4*/ Word w;
    /*type 5*/ Tree t;
    /*type 6*/ MakananKulkas mk;
};

typedef struct ElType{
    int type;
    union Data val;
} ElType;

/**
 * @brief Create a new ElType object
 * 
 * @param type Key to determine the type of the ElType
 * @param val The value held by the ElType
 * @return The new ElType object
 */
ElType NewElType(int type, union Data val);

/**
 * @brief Get the Type of an ElType object
 * 
 * @param e The ElType object to be checked
 * @return Key to determine the type of the ElType
 */
int GetType(ElType e);

/**
 * @brief Get the value of an ElType object
 * 
 * @param e The ElType object to be checked
 * @return union Data The value held by the ElType
 */
union Data GetVal(ElType e);

/**
 * @brief Set the Val of an ElType object
 * 
 * @param e The ElType object to be modified
 * @param type Key to determine the type of the ElType
 * @param val The value that will be held by the ElType
 */
void SetVal(ElType *e, int type, union Data val);

/**
 * @brief copy the value of an ElType (b) object to another ElType (a) object
 * 
 */
void CopyElType(ElType *a, ElType b);

/**
 * @brief compare the val of two ElType
 * 
 * @return is a equals to b 
 */
boolean Compare(ElType a, ElType b);

/**
 * @brief print the val of an ElType
 * 
 * @param e the ElType to be printed
 */
void PrintElType(ElType a);

#endif