#ifndef SET_H
#define SET_H

/* ADT */
#include "../../boolean.h"
#include "../wordmachine/wordmachine.h"

#define IDX_UNDEF -1

typedef struct{
    int val;
    int cnt;
} SetElmt;

typedef struct{
    SetElmt data[100];
    int length;
    int id;
} Set;

/**
 * @brief Create a Set object with length 0
 * 
 * @param s The set to be initialized
 */
void CreateSet(Set *s);

/**
 * @brief Check if the set is empty
 * 
 * @param s The set to be checked
 * @return Empty status of the set
 */
boolean IsSetEmpty(Set s);

/**
 * @brief Check if the set is full
 * 
 * @param s THe set to be checked
 * @return Full status of the set
 */
boolean IsSetFull(Set s);

/**
 * @brief Get the length of the set
 * 
 * @param s The set to be checked
 * @return Length of the set
 */
int Length(Set s);

/**
 * @brief Check if the set contains the element
 * 
 * @param s The set to be checked
 * @param e Element to be checked
 * @return Is e in s
 */
boolean IsMember(Set s, int e);

/**
 * @brief Get the index of element e, return IDX_UNDEF if not found
 * 
 * @param s The set to be searched
 * @param e Element to be searched
 */
int SetGetIdx(Set s, int e);

/**
 * @brief Add cnt elements to the set. Add new if e isn't found and set is not full
 * 
 * @param s The set to be modified
 * @param e Element to be added
 * @param cnt How many elements to be added
 */
void SetAdd(Set *s, int e, int cnt);

/**
 * @brief Remove cnt elements from the set if found. If the count of e isn't more than 1 after subtracted, the element will be removed from the set.
 * 
 * @param s The set to be modified
 * @param e Element to be removed
 * @param e How many elements to be removed
 */
void RemoveSet(Set *s, int e, int cnt);

/**
 * 
 * @param s The set to be printed
 */
void PrintSet(Set s);

/**
 * 
 * @param s1 
 * @param s2 
 * @return The union from s1 and s2
 */
Set UnionSet(Set s1, Set s2);

/**
 * 
 * @param s1 
 * @param s2 
 * @return The intersection from s1 and s2
 */
Set Intersection(Set s1, Set s2);

/**
 * 
 * @param s1 
 * @param s2 
 * @return The difference of s1 and s2 (s1 - s2)
 */
Set Difference(Set s1, Set s2);

/**
 * @brief Check if the set is subset of another set
 * 
 * @param s1 
 * @param s2 
 * @return Is s1 subset of s2
 */
boolean IsSubset(Set s1, Set s2);

/**
 * @brief Copy a set (s2) to another set (s1)
 */
void CopySet(Set *s1, Set s2);

/**
 * @brief Set the set id
 * 
 * @param s 
 * @param id 
 */
void SetId(Set *s, int id);

/**
 * @brief Get the set id
 * 
 * @param s 
 * @return int 
 */
int GetSetId(Set s);

#endif