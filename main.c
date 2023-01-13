#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
    printf("Linked list\n");

    for(int k=0;k<10;k++)
    {
        linkedlist_append(k);
        printf("in=%d\n",linkedlist_get_last()->value);
    }

    for(int k=0;((k<3)&&(!linkedlist_is_empty()));k++)
    {
        printf("out=%d\n",linkedlist_get_first()->value);
        linkedlist_remove_first();
    }

    for(int k=10;k<15;k++)
    {
        linkedlist_append(k);
        printf("in=%d\n",linkedlist_get_last()->value);
    }

    for(int k=0;!linkedlist_is_empty();k++)
    {
        printf("out=%d\n",linkedlist_get_first()->value);
        linkedlist_remove_first();
    }

    linkedlist_free();
    return 0;
}
