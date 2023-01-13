#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

void print_chain()
{
    printf("____\n");
    printf("first=%p\n",(void*)linkedlist_get_first());
    for(ele_t *ele=linkedlist_get_first();ele!=NULL;ele=ele->next)
    {
        printf("current=%p next=%p previous=%p value=%d\n",(void*)ele,(void*)(ele->next),(void*)(ele->previous),ele->value);
    }
    printf("last=%p\n",(void*)linkedlist_get_last());
    printf("----\n");
}

void check_chain_length(int length)
{
    int actual_length=0;

    if(length==0)
    {
        if((linkedlist_get_last()!=NULL)||(linkedlist_get_first()!=NULL))
        {
            printf("expected length %d\n",length);
            print_chain();
            assert(1==0);
        }
    }

    for(ele_t *ele=linkedlist_get_first();ele!=NULL;ele=ele->next)
    {
        actual_length++;
    }

    if(actual_length!=length)
    {
        printf("expected length %d\n",length);
        print_chain();
        assert(1==0);
    }
}

void check_sequence(int start_value,bool increasing)
{
    int value=start_value;
    for(ele_t *ele=linkedlist_get_first();ele!=NULL;ele=ele->next)
    {
        if(ele->value!=value)
        {
            print_chain();
            assert(1==0);
        }
        if(increasing)
        {
            value++;
        }
        else
        {
            value--;
        }
    }
}

void check_remove_all_eles(int length, bool first)
{
    for(;length>0||!linkedlist_is_empty();)
    {
        check_chain_length(length);
        if(first)
        {
            linkedlist_remove_first();
        }
        else
        {
            linkedlist_remove_last();
        }
        length--;
        check_chain_length(length);
    }
    assert(linkedlist_get_first()==NULL);
    assert(linkedlist_get_last()==NULL);
    assert(linkedlist_is_empty());
    assert(length==0);
}

void check_add(int length, bool first)
{
    check_chain_length(0);
    for(int k=0;k<length;)
    {
        if(first)
        {
            linkedlist_prepend(k);
        }
        else
        {
            linkedlist_append(k);
        }
        k++;
        check_chain_length(k);
    }
}

void linkedlist_test()
{
    check_add(4,true);
    check_sequence(3,false);
    check_remove_all_eles(4,true);

    check_add(4,true);
    check_remove_all_eles(4,false);

    check_add(4,false);
    check_sequence(0,true);
    check_remove_all_eles(4,true);

    check_add(4,false);
    check_remove_all_eles(4,false);

    check_add(4,true);
    linkedlist_free();
    assert(linkedlist_get_first()==NULL);
    assert(linkedlist_get_last()==NULL);
    assert(linkedlist_is_empty());
}
