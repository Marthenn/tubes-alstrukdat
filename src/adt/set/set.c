/* C libraries */
#include <stdio.h>

/* ADT */
#include "set.h"

void CreateSet(Set *s){
    (*s).length = 0;
}

boolean IsSetEmpty(Set s){
    return s.length == 0;
}

boolean IsSetFull(Set s){
    return s.length == 100;
}

boolean IsMember(Set s, ElType e){
    int i = 0;
    boolean found = false;
    while(i < s.length && !found){
        if(Compare(s.data[i], e)){
            found = true;
        }
        i++;
    }
    return found;
}

void SetAdd(Set *s, ElType e){
    if(IsSetFull(*s)){
        printf("Set penuh!\n");
    }
    if(!IsMember(*s, e) && !IsSetFull(*s)){
        (*s).data[(*s).length] = e;
        (*s).length++;
    }
}

void RemoveSet(Set *s, ElType e){
    if(IsMember(*s,e)){
        int i = 0;
        boolean found = false;
        while(i < (*s).length && !found){
            if(Compare((*s).data[i], e)){
                found = true;
            }
            i++;
        }
        for(int j = i; j < (*s).length; j++){
            (*s).data[j-1] = (*s).data[j];
        }
        (*s).length--;
    }
}

void PrintSet(Set s){
    printf("{");
    for(int i = 0; i < s.length; i++){
        PrintElType(s.data[i]);
        if(i != s.length-1){
            printf(", ");
        }
    }
    printf("}");
}

Set UnionSet(Set s1, Set s2){
    Set s;
    CreateSet(&s);
    for(int i = 0; i < s1.length; i++){
        SetAdd(&s, s1.data[i]);
    }
    for(int i = 0; i < s2.length; i++){
        SetAdd(&s, s2.data[i]);
    }
    return s;
}

Set Intersection(Set s1, Set s2){
    Set s;
    CreateSet(&s);
    for(int i = 0; i < s1.length; i++){
        if(IsMember(s2, s1.data[i])){
            SetAdd(&s, s1.data[i]);
        }
    }
    return s;
}

Set Difference(Set s1, Set s2){
    Set s;
    CreateSet(&s);
    for(int i = 0; i < s1.length; i++){
        if(!IsMember(s2, s1.data[i])){
            SetAdd(&s, s1.data[i]);
        }
    }
    return s;
}

boolean IsSubset(Set s1, Set s2){
    boolean subset = true;
    int i = 0;
    while(i < s1.length && subset){
        if(!IsMember(s2, s1.data[i])){
            subset = false;
        }
        i++;
    }
    return subset;
}

void CopySet(Set *s1, Set s2){
    CreateSet(s1);
    for(int i = 0; i < s2.length; i++){
        SetAdd(s1, s2.data[i]);
    }
}