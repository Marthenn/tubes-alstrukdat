#ifndef SET_H
#define SET_H

/* ADT */
#include "boolean.h"
#include "eltype.h"

typedef struct{
    ElType data[100];
    int length;
} Set;

/**
 * @brief Create a Set object with length 0
 * 
 * @param s 
 */
void CreateSet(Set *s);

/**
 * @brief Check if the set is empty
 * 
 * @param s 
 * @return boolean 
 */
boolean IsSetEmpty(Set s);

/**
 * @brief Check if the set is full
 * 
 * @param s 
 * @return boolean 
 */
boolean IsSetFull(Set s);

/**
 * @brief Get the length of the set
 * 
 * @param s 
 * @return int 
 */
int Length(Set s);

/**
 * @brief Check if the set contains the element
 * 
 * @param s 
 * @param e 
 * @return boolean 
 */
boolean IsMember(Set s, ElType e);

/**
 * @brief Add an element to the set
 * 
 * @param s 
 * @param e 
 */
void SetAdd(Set *s, ElType e);

/**
 * @brief Remove an element from the set
 * 
 * @param s 
 * @param e 
 */
void RemoveSet(Set *s, ElType e);

/**
 * @brief Print the set
 * 
 * @param s 
 */
void PrintSet(Set s);

/**
 * @brief Get the union of two sets
 * 
 * @param s1 
 * @param s2 
 * @return set 
 */
Set UnionSet(Set s1, Set s2);

/**
 * @brief Get the intersection of two sets
 * 
 * @param s1 
 * @param s2 
 * @return set 
 */
Set Intersection(Set s1, Set s2);

/**
 * @brief Get the difference of two sets (s1 - s2)
 * 
 * @param s1 
 * @param s2 
 * @return set 
 */
Set Difference(Set s1, Set s2);

/**
 * @brief Check if the set is subset of another set
 * 
 * @param s1 
 * @param s2 
 * @return boolean 
 */
boolean IsSubset(Set s1, Set s2);

/**
 * @brief Copy a set to another set
 * 
 * @param s1 
 * @param s2 
 */
void CopySet(Set *s1, Set s2);

#endif