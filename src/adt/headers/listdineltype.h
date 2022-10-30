#ifndef LISTDINELTYPE_H
#define LISTDINELTYPE_H

#include "boolean.h"
#include "eltype.h"

typedef struct{
    ElType *buffer;
    int nEff;
    int capacity;
} ListDinElType;

/**
 * @brief Create a ListDinElType object with known capacity
 * 
 * @param L 
 * @param capacity 
 */
void CreateListDinElType(ListDinElType *L, int capacity);

/**
 * @brief Deallocate a ListDinElType
 * 
 * @param L 
 */
void DeallocateListDinElType(ListDinElType *L);

/**
 * @brief Return the length of the ListDinElType
 * 
 * @param L 
 * @return int 
 */
int ListDinElTypeLength(ListDinElType L);

/**
 * @brief Check if the ListDinElType is empty
 * 
 * @param L 
 * @return boolean 
 */
boolean IsListDinElTypeEmpty(ListDinElType L);

/**
 * @brief Check if the ListDinElType is full
 * 
 * @param L 
 * @return boolean 
 */
boolean IsListDinElTypeFull(ListDinElType L);

/**
 * @brief Cehck if index is valid
 * 
 * @param L 
 * @param index 
 * @return boolean 
 */
boolean IsListDinElTypeIdxValid(ListDinElType L, int index);

/**
 * @brief Check if index is in range of the ListDinElType with element
 * 
 * @param L 
 * @param index 
 * @return boolean 
 */
boolean IsListDinElTypeIdxEff(ListDinElType L, int index);

/**
 * @brief Print the ListDinElType
 * 
 * @param L 
 */
void PrintListDinElType(ListDinElType L);

/**
 * @brief Get the index of e, return -1 if not found
 * 
 * @param L 
 * @param index 
 * @return
 */
int ListDinElTypeIdxOf(ListDinElType L, ElType e);

/**
 * @brief Insert e to the ListDinElType at first index
 * 
 * @param L 
 * @param e 
 */
void InsertFirstListDinElType(ListDinElType *L, ElType e);

/**
 * @brief Insert e to the ListDinElType at last index
 * 
 * @param L 
 * @param e 
 */
void InsertLastListDinElType(ListDinElType *L, ElType e);

/**
 * @brief Expand the capacity of the ListDinElType by 1.5
 * 
 * @param L 
 * @param index 
 * @param e 
 */
void ExpandListDinElType(ListDinElType *L);

/**
 * @brief Shrink the capacity of the ListDinElType by 0.5
 * 
 * @param L 
 */
void ShrinkListDinElType(ListDinElType *L);

/**
 * @brief Compress ListDinElType to the minimum capacity (capacity = nEff)
 * 
 * @param L 
 */
void CompresListDinElType(ListDinElType *L);

#endif