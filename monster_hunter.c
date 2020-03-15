#include "monster_hunter.h"
#include <stdio.h>
#include <stdlib.h>

char if_quit(void)
{
    char ch;
    fputs("Do you want to quit (y/n): ", stdout);
    scanf("%c", &ch);
    getchar();
    return ch;
}


void if_upgrade(int * money, struct hunter * hunter)
{
    char ch;
    fputs("Do you want to upgrade your weapon (y/n): ", stdout);
    scanf("%c", &ch);
    getchar();
    if(ch == 'y')
    {
        if(*money < 300)
        {
            puts("No money.");
            return;
        }
        else if(*money >= 300)
        {
            *money -= 300;
            hunter->attack += 30;
            puts("Finish upgrade.");
            return;
        }
    }
}


int choose_weapon(struct hunter * hunter)
{
    a: char ch;
    int weapon;
    fputs("Please choose your weapon (b: bow / k: knife): ", stdout);
    scanf("%c", &ch);
    getchar();
    if(ch == 'b')
    {
        hunter->attack = 300;
        weapon = 0;
        return weapon;
    }
    else if(ch == 'k')
    {
        hunter->attack = 200;
        weapon = 1;
        return weapon;
    }
    else
    {
        goto a;
    }
}


void show_item(struct item * item, char * item_name[])
{
    printf("Your item bag:\n");
    for(int i = 0; i < ITEM_QTY; i++)
    {
        printf("%s: %d  ", item_name[item[i].id], item[i].qty);
    }
    printf("\n");
}


void hunter_and_monster(struct hunter * hunter, struct monster * monster, int weapon)
{
    char ch;
    printf("(a) attack  (d) drink: ");
    
    while((ch = get_input(ch)) == 'a')
    {
        if(weapon == 0)
        {
            bow_act(hunter, monster);
        }
    }
}

char get_input(char ch)
{
    scanf("%c", &ch);
    getchar();
    return ch;
}


void bow_act(struct hunter * hunter, struct monster * monster)
{
    char ch = ' ';
    static shoot = 50;
    static int is_shoot = 0;

    printf("(a) one shoot  (b) six shoots: ");
    
    ch = get_input(ch);

    if(shoot == 0)
    {
        is_shoot = 1;
        printf("Put on low powerful shoots.\n");
    }
    else
    {
        printf("You have %d powerful shoots.\n", shoot);
    }

    if(ch == 'a')
    {
        if(shoot != 0 && is_shoot == 0)
        {
            --shoot;
            monster->hp -= hunter->attack * 1.15;
            monster->hp += monster->defence;
            hunter->hp -= monster->attack;
            hunter->hp += hunter->defence;
        }
        else if(is_shoot == 1)
        {
            monster->hp -= hunter->attack * 0.80;
            monster->hp += monster->defence;
            hunter->hp -= monster->attack;
            hunter->hp += hunter->defence;
        }
        else
        {
            printf("No shoot.\n");
        }
        show_hp(&hunter, &monster);
    }
    else if(ch == 'b')
    {
        if((shoot = shoot - 6) != 0 && is_shoot == 0)
        {
            monster->hp -= hunter->attack * 1.15 * 6;
            monster->hp += monster->defence;
            hunter->hp -= monster->attack;
            hunter->hp += hunter->defence;
        }
        else if(is_shoot == 1)
        {
            monster->hp -= hunter->attack * 0.80 * 6;
            monster->hp += monster->defence;
            hunter->hp -= monster->attack;
            hunter->hp += hunter->defence;
        }
        else
        {
            printf("No shoot");
        }
        shoot += 6;
        show_hp(hunter, monster);
    }
    
}

void show_hp(struct hunter * hunter, struct monster * monster)
{
    printf("hunter's hp: %d   monster's hp: %d\n", hunter->hp, monster->hp);
}
