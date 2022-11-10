#ifndef SET_H
#define SET_H

/* ADT */
#include "../../boolean.h"
#include "../wordmachine/wordmachine.h"

typedef struct{
    int data[100];
    int length;
    Word name;
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
 * @brief Add an element to the set if set is not full
 * 
 * @param s The set to be modified
 * @param e Element to be added
 */
void SetAdd(Set *s, int e);

/**
 * @brief Remove an element from the set
 * 
 * @param s The set to be modified
 * @param e Element to be removed
 */
void RemoveSet(Set *s, int e);

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
 * @brief Set the Name object
 * 
 * @param s 
 * @param name 
 */
void SetName(Set *s, Word name);

/**
 * @brief Get the Set Name object
 * 
 * @param s 
 * @return Word 
 */
Word GetSetName(Set s);

#endif