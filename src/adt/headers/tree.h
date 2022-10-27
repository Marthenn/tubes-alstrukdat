#ifndef TREE_H
#define TREE_H

#include "eltype.h"
#include "boolean.h"

typedef struct treeNode* Address;
typedef struct treeNode {
    ElType info;
    Address firstChild;
    Address nextSibling;
} TreeNode;

typedef Address Tree;

/**
 * @brief Create a new tree node
 * 
 * @param val 
 */
Address newTreeNode(ElType val);

/**
 * @brief Create a tree object with known root value
 * 
 * @param Root 
 * @return Tree 
 */
Tree newTree (ElType root);

/**
 * @brief add a children to a tree
 * 
 * @param p 
 * @param val 
 * @return tree 
 */
void addChild(Tree *p, ElType val);

/**
 * @brief check if val is a children of p
 * 
 * @param p 
 * @param val 
 * @return boolean 
 */
boolean isChild(Tree p, ElType val);

/**
 * @brief check if val is part of the tree
 * 
 * @param p 
 * @param val 
 * @return boolean 
 */
boolean isPartOf(Tree p, ElType val);

/**
 * @brief return the number of children of a tree
 * 
 * @param p 
 * @return int 
 */
int numberChildren(Tree p);

/**
 * @brief print a tree and all of its children represented by brackets e.g. (1(2(4)(5))(3))
 * 
 * @param p 
 */
void printTree(Tree p);

#endif