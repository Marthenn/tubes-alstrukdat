#include <stdio.h>
#include "../headers/set.h"

void createSet(set *s){
    (*s).length = 0;
}

boolean isEmpty(set s){
    return s.length == 0;
}

boolean isFull(set s){
    return s.length == 100;
}

boolean isMember(set s, ElType e){
    int i = 0;
    boolean found = false;
    while(i < s.length && !found){
        if(compare(s.data[i], e)){
            found = true;
        }
        i++;
    }
    return found;
}

void add(set *s, ElType e){
    if(!isMember(*s, e) && !isFull(*s)){
        (*s).data[(*s).length] = e;
        (*s).length++;
    }
}

void removeSet(set *s, ElType e){
    if(isMember(*s,e)){
        int i = 0;
        boolean found = false;
        while(i < (*s).length && !found){
            if(compare((*s).data[i], e)){
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

void printSet(set s){
    printf("{");
    for(int i = 0; i < s.length; i++){
        printElType(s.data[i]);
        if(i != s.length-1){
            printf(", ");
        }
    }
    printf("}");
}

set unionSet(set s1, set s2){
    set s;
    createSet(&s);
    for(int i = 0; i < s1.length; i++){
        add(&s, s1.data[i]);
    }
    for(int i = 0; i < s2.length; i++){
        add(&s, s2.data[i]);
    }
    return s;
}

set intersection(set s1, set s2){
    set s;
    createSet(&s);
    for(int i = 0; i < s1.length; i++){
        if(isMember(s2, s1.data[i])){
            add(&s, s1.data[i]);
        }
    }
    return s;
}

set difference(set s1, set s2){
    set s;
    createSet(&s);
    for(int i = 0; i < s1.length; i++){
        if(!isMember(s2, s1.data[i])){
            add(&s, s1.data[i]);
        }
    }
    return s;
}

boolean isSubset(set s1, set s2){
    boolean subset = true;
    int i = 0;
    while(i < s1.length && subset){
        if(!isMember(s2, s1.data[i])){
            subset = false;
        }
        i++;
    }
    return subset;
}

void copySet(set *s1, set s2){
    createSet(s1);
    for(int i = 0; i < s2.length; i++){
        add(s1, s2.data[i]);
    }
}