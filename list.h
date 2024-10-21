typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} list;

list* newlist();
void append(list* original, int item);
int pop(list* original);
int get(list* original, int index);
void print(list* original);
void delete(list* original);

