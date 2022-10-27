#include <stdio.h>
#include <stdlib.h>
#include "../headers/tree.h"

Address newTreeNode(ElType val){
    Address new = (Address)malloc(sizeof(treeNode));
    if(new!=NULL){
        new->info = val;
        new->firstChild = NULL;
        new->nextSibling = NULL;
    }
    return new;
}

tree newTree (ElType root){
    tree p = newTreeNode(root);
    if(p!=NULL){
        p->firstChild = NULL;
        p->nextSibling = NULL;
    }
    return p;
}

void addChild(tree *p, ElType val){
    Address new = newTreeNode(val);
    if(new!=NULL){
        if((*p)->firstChild==NULL){
            (*p)->firstChild = new;
        }else{
            Address temp = (*p)->firstChild;
            while(temp->nextSibling!=NULL){
                temp = temp->nextSibling;
            }
            temp->nextSibling = new;
        }
    }
}

boolean isChild(tree p, ElType val){
    if(p->firstChild==NULL){
        return false;
    }else{
        Address temp = p->firstChild;
        while(temp!=NULL){
            if(compare(temp->info,val)){
                return true;
            }
            temp = temp->nextSibling;
        }
        return false;
    }
}

boolean isPartOf(tree p, ElType val){
    if(compare(p->info,val)){
        return true;
    }else{
        if(p->firstChild==NULL){
            return false;
        }else{
            Address temp = p->firstChild;
            while(temp!=NULL){
                if(isPartOf(temp,val)){
                    return true;
                }
                temp = temp->nextSibling;
            }
            return false;
        }
    }
}

int numberChildren(tree p){
    if(p->firstChild==NULL){
        return 0;
    }else{
        int count = 0;
        Address temp = p->firstChild;
        while(temp!=NULL){
            count++;
            temp = temp->nextSibling;
        }
        return count;
    }
}

void printTree(tree p){
    printf("( ");
    printElType(p->info);printf(" ");
    if(p->firstChild!=NULL){
        Address temp = p->firstChild;
        while(temp!=NULL){
            printTree(temp);
            temp = temp->nextSibling;
        }
    }
    printf(")");
}