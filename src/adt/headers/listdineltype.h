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
 * @param L The list to be initialized
 * @param capacity The capacity of the list
 */
void CreateListDinElType(ListDinElType *L, int capacity);

/**
 * @brief Deallocate a ListDinElType
 * 
 * @param L The ListDinElType to be deallocated
 */
void DeallocateListDinElType(ListDinElType *L);

/**
 * @param L the ListDinElType to be checked
 * @return the length of the list
 */
int ListDinElTypeLength(ListDinElType L);

/**
 * @param L the list to be checked
 * @return is L empty 
 */
boolean IsListDinElTypeEmpty(ListDinElType L);

/**
 * @param L the list to be checked
 * @return is L full
 */
boolean IsListDinElTypeFull(ListDinElType L);

/**
 * @brief Check if index is valid
 * 
 * @param L The list to be checked
 * @param index the index to be checked
 * @return is index a valid index
 */
boolean IsListDinElTypeIdxValid(ListDinElType L, int index);

/**
 * @brief Check if index is in range of the ListDinElType with element
 * 
 * @param L the list to be checked
 * @param index the index to be checked
 * @return Is index a valid index with element
 */
boolean IsListDinElTypeIdxEff(ListDinElType L, int index);

/**
 * @brief Print the ListDinElType
 * 
 * @param L The list to be printed
 */
void PrintListDinElType(ListDinElType L);

/**
 * @param L the list to be checked
 * @param e the element in which the index will be searched
 * @return the index of e, -1 if not found
 */
int ListDinElTypeIdxOf(ListDinElType L, ElType e);

/**
 * @brief Insert e to the ListDinElType at first index
 */
void InsertFirstListDinElType(ListDinElType *L, ElType e);

/**
 * @brief Insert e to the ListDinElType at last index
 */
void InsertLastListDinElType(ListDinElType *L, ElType e);

/**
 * @brief Expand the capacity of the ListDinElType by 1.5
 */
void ExpandListDinElType(ListDinElType *L);

/**
 * @brief Shrink the capacity of the ListDinElType by 0.5
 */
void ShrinkListDinElType(ListDinElType *L);

/**
 * @brief Compress ListDinElType to the minimum capacity (capacity = nEff)
 */
void CompresListDinElType(ListDinElType *L);

#endif