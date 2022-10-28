#ifndef TREE_H
#define TREE_H

/* ADT */
#include "eltype.h"
#include "boolean.h"

typedef struct treeNode* Address;
typedef struct treeNode {
    int info;
    Address firstChild;
    Address nextSibling;
} TreeNode;

typedef Address Tree;

/**
 * @brief Create a new tree node
 * 
 * @param val 
 */
Address NewTreeNode(int val);

/**
 * @brief Create a tree object with known root value
 * 
 * @param Root 
 * @return Tree 
 */
Tree NewTree (int root);

/**
 * @brief add a children to a tree
 * 
 * @param p 
 * @param val 
 * @return tree 
 */
void AddChild(Tree *p, int val);

/**
 * @brief add a node as a child to a tree
 * 
 * @param p 
 * @param node 
 */
void AddChildNode(Tree *p, Address node);

/**
 * @brief check if val is a children of p
 * 
 * @param p 
 * @param val 
 * @return boolean 
 */
boolean IsChild(Tree p, int val);

/**
 * @brief check if val is part of the tree
 * 
 * @param p 
 * @param val 
 * @return boolean 
 */
boolean IsPartOf(Tree p, int val);

/**
 * @brief return the number of children of a tree
 * 
 * @param p 
 * @return int 
 */
int NumberChildren(Tree p);

/**
 * @brief print a tree and all of its children represented by brackets e.g. (1(2(4)(5))(3))
 * 
 * @param p 
 */
void PrintTree(Tree p);

#endif