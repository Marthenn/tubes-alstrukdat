/* C libraries */
#include <stdio.h>
#include <stdlib.h>

/* ADT */
#include "tree.h"

Address NewTreeNode(int val){
    Address new = (Address)malloc(sizeof(TreeNode));
    if(new!=NULL){
        new->info = val;
        new->firstChild = NULL;
        new->nextSibling = NULL;
    }
    return new;
}

Tree NewTree (int root){
    Tree p = NewTreeNode(root);
    if(p!=NULL){
        p->firstChild = NULL;
        p->nextSibling = NULL;
    }
    return p;
}

void AddChild(Tree *p, int val, Address *newNode){
    Address new = NewTreeNode(val);
    if(new!=NULL){

        *newNode = new;
        
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

void AddChildNode(Tree *p, Address node){
    if(node!=NULL && !IsChild(*p, node->info)){
        if((*p)->firstChild==NULL){
            (*p)->firstChild = node;
        }else{
            Address temp = (*p)->firstChild;
            while(temp->nextSibling!=NULL){
                temp = temp->nextSibling;
            }
            temp->nextSibling = node;
        }
    }
}

boolean IsChild(Tree p, int val){
    if(p->firstChild==NULL){
        return false;
    }else{
        Address temp = p->firstChild;
        while(temp!=NULL){
            if(temp->info == val){
                return true;
            }
            temp = temp->nextSibling;
        }
        return false;
    }
}

boolean IsPartOf(Tree p, int val){
    if(p->info == val){
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
    printf("%d ", p->info);
    if(p->firstChild!=NULL){
        Address temp = p->firstChild;
        while(temp!=NULL){
            PrintTree(temp);
            temp = temp->nextSibling;
        }
    }
    printf(")");
}

Tree GetSubTree(Tree p, int val){
    if(p->info == val){
        return p;
    }else{
        if(p->firstChild==NULL){
            return NULL;
        }else{
            Address temp = p->firstChild;
            while(temp!=NULL){
                Tree sub = GetSubTree(temp,val);
                if(sub!=NULL){
                    return sub;
                }
                temp = temp->nextSibling;
            }
            return NULL;
        }
    }
}

ListDin GetChildren(Tree p){
    ListDin l;
    CreateListDin(&l, 10);
    if(p->firstChild!=NULL){
        Address temp = p->firstChild;
        while(temp!=NULL){
            if(IsListDinFull(l)){
                ExpandListDin(&l);
            }
            InsertLastListDin(&l, temp->info);
            temp = temp->nextSibling;
        }
    }
    CompressListDin(&l);
    return l;
}