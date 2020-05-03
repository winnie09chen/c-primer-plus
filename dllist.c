#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dllist.h"

struct film
{
    char name[64];
    int rate;
    struct list_head node;
};


#define FILM_SIZE  6 

static char * film_names[FILM_SIZE] = {
    "Top Gun",
    "Ironman",
    "Superman",
    "Batman",
    "Antman",
    "Spiderman"
};

static int film_rates[FILM_SIZE] = 
{
    8,
    9,
    6,
    8,
    5,
    7
};

void test_list()
{
    LIST_HEAD(films);
    struct list_head * ptr;
    struct film * f_ptr;
    struct film * new_;
    for (int i = 0; i < FILM_SIZE; i++)
    {
        new_ = (struct film *)malloc(sizeof(struct film));
        strcpy(new_->name, film_names[i]);
        new_->rate = film_rates[i];
        INIT_LIST_HEAD(&(new_->node));
        list_add(&(new_->node), &films);
    }
    list_for_each(ptr, &films)
    {
        f_ptr = list_entry(ptr, struct film, node);
        printf("%s\t%d\n", f_ptr->name, f_ptr->rate);
    }
}

void test_list_entry()
{
    struct film *f_ptr;
    struct list_head * l_ptr;
    struct film f_entry;
    strcpy(f_entry.name, film_names[0]);
    f_entry.rate = 10;

    l_ptr = &(f_entry.node);
    f_ptr = list_entry(l_ptr, struct film, node);
    printf("&f_entry: %p\n", &f_entry);
    printf("f_ptr: %p\n", f_ptr);
}

int main(void)
{
    test_list();

    getchar();
    return 0;
}