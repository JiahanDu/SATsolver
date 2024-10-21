<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
/* The following code implements a dictionary that takes integer keys and integer values.*/
typedef struct{
    int* hashvals;
    int size;
    int capacity;
}dict

dict* newdict;
void add(self, int key, int value);
int get(self,int key);
void pop(self,int key);
=======
#include <stdio.h>
#include <stdlib.h>
/* The following code implements a dictionary that takes integer keys and integer values.*/
typedef struct{
    int* hashvals;
    int size;
    int capacity;
}dict

dict* newdict;
void add(self, int key, int value);
int get(self,int key);
void pop(self,int key);
>>>>>>> 3353442645e768a77b713cf4bbeb325f158b23b4
