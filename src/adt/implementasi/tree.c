#include <stdio.h>
#include <stdlib.h>
#include "../headers/tree.h"

Address NewTreeNode(ElType val){
    Address new = (Address)malloc(sizeof(TreeNode));
    if(new!=NULL){
        new->info = val;
        new->firstChild = NULL;
        new->nextSibling = NULL;
    }
    return new;
}

Tree NewTree (ElType root){
    Tree p = NewTreeNode(root);
    if(p!=NULL){
        p->firstChild = NULL;
        p->nextSibling = NULL;
    }
    return p;
}

void AddChild(Tree *p, ElType val){
    Address new = NewTreeNode(val);
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

boolean IsChild(Tree p, ElType val){
    if(p->firstChild==NULL){
        return false;
    }else{
        Address temp = p->firstChild;
        while(temp!=NULL){
            if(Compare(temp->info,val)){
                return true;
            }
            temp = temp->nextSibling;
        }
        return false;
    }
}

boolean IsPartOf(Tree p, ElType val){
    if(Compare(p->info,val)){
        return true;
    }else{
        if(p->firstChild==NULL){
            return false;
        }else{
            Address temp = p->firstChild;
            while(temp!=NULL){
                if(IsPartOf(temp,val)){
                    return true;
                }
                temp = temp->nextSibling;
            }
            return false;
        }
    }
}

int NumberChildren(Tree p){
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

void PrintTree(Tree p){
    printf("( ");
    PrintElType(p->info);printf(" ");
    if(p->firstChild!=NULL){
        Address temp = p->firstChild;
        while(temp!=NULL){
            PrintTree(temp);
            temp = temp->nextSibling;
        }
    }
    printf(")");
}