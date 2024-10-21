#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main(){
    list* mylist=newlist();
    append(mylist,1);
    append(mylist,2);
    append(mylist,3);
    append(mylist,4);
    print(mylist);
    pop(mylist);
    print(mylist);
    delete(mylist);
    return 0;
}