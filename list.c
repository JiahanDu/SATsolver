/* This library implements dynamically resizable arrays including arbitrary nested lists.
To initialize a list: list* mylist=newlist();
To append x to a list: append(list,x);
To pop the last element of a list and return it; pop(list);
To get the ith element of a list: get(list,i);
To print the list: print(list);*/
#include<stdio.h>
#include<stdlib.h>
typedef enum{
    INT,
    LIST
}TYPE;

typedef struct{
    TYPE type;
    void* val;
}item;

typedef struct{
    item** data;
    size_t size;
    size_t capacity;
}list;


list* newlist(){
    list* self=malloc(sizeof(list));
    self->size=0;
    self->capacity=10;
    self->data=calloc(10,sizeof(item*));
    return self;
}

void append(list* self, TYPE type,void* entry){
    if((1+self->size)*2>self->capacity){
        self->capacity*=2;
        self->data=realloc(self->data,self->capacity*sizeof(item));
    }
    self->size+=1;
    item* newitem=malloc(sizeof(item));
    if(type==INT){
        newitem->type=INT;
        newitem->val=(int*)(entry);
    }else{
        newitem->type=LIST;
        newitem->val=(list*)(entry);
    }
    self->data[self->size-1]=newitem;
}

item* poplast(list* self){
    item* last=self->data[self->size-1];
    self->size-=1;
    if(self->size*4<self->capacity){
        self->capacity/=4;
        self->data=realloc(self->data,self->capacity*sizeof(int));
    }
    return last;
}

item* get(list* self,int index){
    return self->data[index];
}

void printnoescape(list* self){
     printf("[");
     for(int i=0;i<self->size;i++){
         if(self->data[i]->type==INT){
            printf("%d",*(int*)self->data[i]->val);
        }else{
            printnoescape((list*)self->data[i]->val);
        }
        if(i<self->size-1){
            printf(",");
        }
    }
    printf("]");
}

void print(list*self){
    printnoescape(self);
    printf("\n");
}

void pop(list*self, int index){
    for(int i=index;i<self->size-1;i++){
        self->data[i]=self->data[i+1];
    }
    self->size-=1;
}

void delete(list* self){
    for(int i=0;i<self->size;i++){
        free(self->data[i]);
    }
    free(self->data);
    free(self);
}

int main(){
    list* y=newlist();
    item* var=malloc(sizeof(item));
    var->type=INT;
    int* myint=malloc(sizeof(int));
    *myint=5;
    var->val=myint;
    append(y,INT,myint);
    printf("%d\n",y->size);
    print(y);
    list* x=newlist();
    append(x,LIST,y);
    print(x);
    int* myint2=malloc(sizeof(int));
    *myint2=3;
    list* z=newlist();
    append(z,INT,myint2);
    int myint3=9;
    append(x,LIST,z);
    list* w=newlist();
    append(w,INT,&myint3);
    append(z,LIST,w);
    print(x);
}
