#ifndef SET_H
#define SET_H

#include "boolean.h"
#include "eltype.h"

typedef struct{
    ElType data[100];
    int length;
} set;

/**
 * @brief Create a Set object with length 0
 * 
 * @param s 
 */
void createSet(set *s);

/**
 * @brief Check if the set is empty
 * 
 * @param s 
 * @return boolean 
 */
boolean isEmpty(set s);

/**
 * @brief Check if the set is full
 * 
 * @param s 
 * @return boolean 
 */
boolean isFull(set s);

/**
 * @brief Get the length of the set
 * 
 * @param s 
 * @return int 
 */
int length(set s);

/**
 * @brief Check if the set contains the element
 * 
 * @param s 
 * @param e 
 * @return boolean 
 */
boolean isMember(set s, ElType e);

/**
 * @brief Add an element to the set
 * 
 * @param s 
 * @param e 
 */
void add(set *s, ElType e);

/**
 * @brief Remove an element from the set
 * 
 * @param s 
 * @param e 
 */
void removeSet(set *s, ElType e);

/**
 * @brief Print the set
 * 
 * @param s 
 */
void printSet(set s);

/**
 * @brief Get the union of two sets
 * 
 * @param s1 
 * @param s2 
 * @return set 
 */
set unionSet(set s1, set s2);

/**
 * @brief Get the intersection of two sets
 * 
 * @param s1 
 * @param s2 
 * @return set 
 */
set intersection(set s1, set s2);

/**
 * @brief Get the difference of two sets (s1 - s2)
 * 
 * @param s1 
 * @param s2 
 * @return set 
 */
set difference(set s1, set s2);

/**
 * @brief Check if the set is subset of another set
 * 
 * @param s1 
 * @param s2 
 * @return boolean 
 */
boolean isSubset(set s1, set s2);

/**
 * @brief Copy a set to another set
 * 
 * @param s1 
 * @param s2 
 */
void copySet(set *s1, set s2);

#endif