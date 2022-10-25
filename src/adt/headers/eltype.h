#ifndef ELTYPE_H
#define ELTYPE_H

#include "boolean.h"

union data{
    /*type 0*/ int i;
    /*type 1*/ float f;
};

typedef struct ElType{
    int type;
    union data val;
} ElType;

/**
 * @brief Create a new ElType object
 * 
 * @param type 
 * @param val 
 * @return ElType 
 */
ElType newElType(int type, union data val);

/**
 * @brief Get the Type of an ElType object
 * 
 * @param e 
 * @return int 
 */
int getType(ElType e);

/**
 * @brief Get the value of an ElType object
 * 
 * @param e 
 * @return int 
 */
union data getVal(ElType e);

/**
 * @brief Set the Val of an ElType object
 * 
 * @param e 
 * @param val 
 */
void setVal(ElType *e, union data val);

/**
 * @brief copy the value of an ElType object
 * 
 * @param a 
 * @param b 
 */
void copyElType(ElType *a, ElType b);

/**
 * @brief compare the val of two ElType
 * 
 * @param e 
 * @param val 
 */
boolean compare(ElType a, ElType b);

/**
 * @brief print the val of an ElType
 * 
 * @param e 
 */
void printElType(ElType a);

#endif