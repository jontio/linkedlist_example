#include "linkedlist.h"

#include <stdlib.h>

ele_t *first=NULL;
ele_t *last=NULL;

void linkedlist_append(ELE_TYPE value)
{
    ele_t *ele=malloc(sizeof(ele_t));
    ele->value=value;
    ele->next=NULL;
    ele->previous=last;
    if(last==NULL)
    {
        first=ele;
    }
    else
    {
        last->next=ele;
    }
    last=ele;
}

void linkedlist_prepend(ELE_TYPE value)
{
    ele_t *ele=malloc(sizeof(ele_t));
    ele->value=value;
    ele->next=first;
    ele->previous=NULL;
    if(first==NULL)
    {
        last=ele;
    }
    else
    {
        first->previous=ele;
    }
    first=ele;
}

void linkedlist_remove_first()
{
    if(first==NULL)
    {
        return;
    }
    ele_t *ele=first->next;
    free(first);
    first=ele;
    if(first==NULL)
    {
        last=NULL;
    }
    else
    {
       first->previous=NULL;
    }
}

void linkedlist_remove_last()
{
    if(last==NULL)
    {
        return;
    }
    ele_t *ele=last->previous;
    free(last);
    last=ele;
    if(last==NULL)
    {
        first=NULL;
    }
    else
    {
       last->next=NULL;
    }

}

void linkedlist_free()
{
    while(first!=NULL)
    {
        linkedlist_remove_first();
    }
}

ele_t *linkedlist_get_first()
{
    return first;
}

ele_t *linkedlist_get_last()
{
    return last;
}

bool linkedlist_is_empty()
{
    return (first==NULL)?true:false;
}


