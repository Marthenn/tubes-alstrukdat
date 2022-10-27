#ifndef ELTYPE_H
#define ELTYPE_H

#include "boolean.h"

union Data{
    /*type 0*/ int i;
    /*type 1*/ float f;
    /*type 2*/ char c;
};

typedef struct ElType{
    int type;
    union Data val;
} ElType;

/**
 * @brief Create a new ElType object
 * 
 * @param type 
 * @param val 
 * @return ElType 
 */
ElType NewElType(int type, union Data val);

/**
 * @brief Get the Type of an ElType object
 * 
 * @param e 
 * @return int 
 */
int GetType(ElType e);

/**
 * @brief Get the value of an ElType object
 * 
 * @param e 
 * @return int 
 */
union Data GetVal(ElType e);

/**
 * @brief Set the Val of an ElType object
 * 
 * @param e 
 * @param val 
 */
void SetVal(ElType *e, union Data val);

/**
 * @brief copy the value of an ElType object
 * 
 * @param a 
 * @param b 
 */
void CopyElType(ElType *a, ElType b);

/**
 * @brief compare the val of two ElType
 * 
 * @param e 
 * @param val 
 */
boolean Compare(ElType a, ElType b);

/**
 * @brief print the val of an ElType
 * 
 * @param e 
 */
void PrintElType(ElType a);

#endif