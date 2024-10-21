#include <stdio.h>
#include <stdlib.h>
#include "dict.h"
#include "list.h"
/* The following code implements a dictionary that takes integer keys and integer values. We then implement sets using dictionaries.*/
typedef struct{
    list** buckets;
    int size;
    int capacity;
}dict;

dict* newdict(){
    dict* self=malloc(sizeof(dict));
    self->size=0;
    self->capacity=10;
    self->buckets=calloc(self->capacity,sizeof(list*));
    for(int i=0;i<self->capacity;i++){
        self->buckets[i]=newlist();
    }
    return self;
}

int contains(dict*self,int key){
    int hash=key%self->capacity;
    int res=0;
    for(int i=0;i<self->buckets[hash]->size;i++){
        if(self->buckets[hash][i][0]==key){
            res=1;
        }
    }
    return res;
}

int* get(dict*self, int key){
    int hash=key%self->capacity;
    for(int i=0;i<self->buckets[hash]->size;i++){
        if(self->buckets[hash][i][0]==key){
            return self->buckets[hash][i][1];
        }
    }
    
}

void add(dict* self, int key, int value){
    if(self->size+1>self->capacity){
        self->hashvals=realloc(self->hashvals,self->capacity*2*sizeof(int*))
    }
    int hash=key%self->capacity;
    if (contains(self,key)){
        
    }
    list* entry=newlist();
    append(entry,INT,&key);
    append(entry,INT,&value);
    append(self->data[hash],LIST,entry);
}

void pop(self,int key);
