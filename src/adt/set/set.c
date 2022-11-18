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

boolean IsMember(Set s, int e){
    int i = 0;
    boolean found = false;
    while(i < s.length && !found){
        if(s.data[i].val == e){
            found = true;
        } else {
            i++;
        }
    }
    return found;
}

int SetGetIdx(Set s, int e){
    int i = 0;
    boolean found = false;
    while(i < s.length && !found){
        if(s.data[i].val == e){
            found = true;
        } else {
            i++;
        }
    }
    if (s.data[i].val == e)
        return i;
    else return IDX_UNDEF;
}

void SetAdd(Set *s, int e,int cnt){
    if(IsSetFull(*s)){
        printf("Set penuh!\n");
    }
    else if (IsMember(*s,e)){
        (*s).data[SetGetIdx(*s,e)].cnt += cnt;
    } else {
        (*s).data[(*s).length].val = e;
        (*s).data[(*s).length].cnt = cnt;
        (*s).length++;
    }
}

void RemoveSet(Set *s, int e, int cnt){
    int idx;
    if(IsMember(*s,e)){
        idx = SetGetIdx(*s,e);
        if ((*s).data[idx].cnt > cnt){
            (*s).data[idx].cnt -= cnt;
        } else {
            for(int i = idx; i < (*s).length-1; i++){
                (*s).data[i] = (*s).data[i+1];
            } 
            (*s).length--;
        }
    }
}

void PrintSet(Set s){
    printf("{");
    for(int i = 0; i < s.length; i++){
        printf("<%d,cnt=%d>",s.data[i].val,s.data[i].cnt);
        if(i != s.length-1){
            printf(", ");
        }
    }
    printf("}");
}

Set UnionSet(Set s1, Set s2){
    Set s;
    int pos;
    CreateSet(&s);
    for(int i = 0; i < s1.length; i++){
        SetAdd(&s, s1.data[i].val, s1.data[i].cnt);
    }
    for(int i = 0; i < s2.length; i++){
        if (!IsMember(s,s2.data[i].val))
            SetAdd(&s, s2.data[i].val, s2.data[i].cnt);
        else {
            pos = SetGetIdx(s,s2.data[i].val);
            if (s2.data[i].cnt > s.data[pos].cnt)
                s.data[pos].cnt = s2.data[i].cnt;
        }
    }
    return s;
}

Set Intersection(Set s1, Set s2){
    Set s;
    CreateSet(&s);
    for(int i = 0; i < s1.length; i++){
        for(int j = 0;j < s2.length;j++){
            if(s1.data[i].val == s2.data[j].val){
                if (s1.data[i].cnt <= s2.data[j].cnt)
                    SetAdd(&s,s1.data[i].val,s1.data[i].cnt);
                else
                    SetAdd(&s,s1.data[i].val,s2.data[j].cnt);
            }
        }
    }
    return s;
}

Set Difference(Set s1, Set s2){
    Set s;
    int pos;
    CreateSet(&s);
    for(int i = 0; i < s1.length; i++){
        SetAdd(&s, s1.data[i].val, s1.data[i].cnt);
    }
    for(int i = 0; i < s2.length; i++){
        RemoveSet(&s, s2.data[i].val, s2.data[i].cnt);
    }
    return s;
}

boolean IsSubset(Set s1, Set s2){
    boolean subset = true;
    int idx;
    int i = 0;
    while(i < s1.length && subset){
        idx = SetGetIdx(s2, s1.data[i].val);
        if (idx == IDX_UNDEF || s1.data[i].cnt > s2.data[idx].cnt){
            subset = false;
        }
        i++;
    }
    return subset;
}

void CopySet(Set *s1, Set s2){
    CreateSet(s1);
    for(int i = 0; i < s2.length; i++){
        SetAdd(s1, s2.data[i].val,s2.data[i].cnt);
    }
}

void SetId(Set *s, int id){
    (*s).id = id;
}

int GetSetId(Set s){
    return s.id;
}