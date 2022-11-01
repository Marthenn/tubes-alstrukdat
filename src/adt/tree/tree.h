#ifndef TREE_H
#define TREE_H

/* ADT */
#include "../../boolean.h"
#include "../listdin/listdin.h"

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
 * @param val The value held by the new tree node
 * 
 * @return Address of the new tree node
 * 
 */
Address NewTreeNode(int val);

/**
 * @brief Create a tree object with known root value
 * 
 * @param Root  The value of the root
 * 
 * @return Tree with only root
 * 
 */
Tree NewTree (int root);

/**
 * @brief add a children to a tree
 * 
 * @param p The tree to be modified
 * @param val value of the new child
 * @param newNode Address of the new child
 * 
 */
void AddChild(Tree *p, int val, Address *newNode);

/**
 * @brief add a node as a child to a tree
 * 
 * @param p The tree to be modified
 * @param node The node of the new child
 */
void AddChildNode(Tree *p, Address node);

/**
 * @brief check if val is a children of p
 * 
 * @param p tree to be searched
 * @param val value held by the child
 * @return is there a child with value val with parent p
 */
boolean IsChild(Tree p, int val);

/**
 * @brief check if val is part of the tree
 * 
 * @param p tree to be searched
 * @param val value held by the node
 * @return is there a node with value val in the tree
 */
boolean IsPartOf(Tree p, int val);

/**
 * @brief return the number of children of a tree
 * 
 * @param p the parent node/root of the tree (first level node)
 * @return number of children (number of nodes in the second level)
 */
int NumberChildren(Tree p);

/**
 * @brief print a tree and all of its children represented by brackets e.g. (1(2(4)(5))(3))
 * 
 * @param p tree to be printed
 */
void PrintTree(Tree p);

/**
 * @brief Get the Sub Tree object with root val, return NULL if not found
 * 
 * @param p the universal tree
 * @param val value of the root of the subtree
 * @return SubTree with root val
 */
Tree GetSubTree(Tree p, int val);

/**
 * @brief Get the children of the tree
 * 
 * @param p Root of the tree
 * @return List of children from parent node p
 */
ListDin GetChildren(Tree p);

#endif