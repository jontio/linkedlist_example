#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdbool.h>

//eg of another type but for pointers it would be more
//tricky as you would have to malloc and free the the
//mem in linkedlist_value_struct
//typedef struct linkedlist_value_struct
//{
//    char packet[10];
//} linkedlist_value_struct_t;
//#define ELE_TYPE linkedlist_value_struct_t

#ifndef ELE_TYPE
#define ELE_TYPE int
#endif

#ifdef UNIT_TESTS
#undef ELE_TYPE
#define ELE_TYPE int
#endif

typedef struct ele
{
    ELE_TYPE value;
    struct ele *next;
    struct ele *previous;
} ele_t;

void linkedlist_append(ELE_TYPE value);
void linkedlist_prepend(ELE_TYPE value);
void linkedlist_remove_first();
void linkedlist_remove_last();
void linkedlist_free();
ele_t *linkedlist_get_first();
ele_t *linkedlist_get_last();
bool linkedlist_is_empty();

#endif
