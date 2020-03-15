#include "monster_hunter.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct hunter hunter;

struct item item[ITEM_QTY];

struct monster monster;

char * item_name[ITEM_SIZE] = {"Potion", "Max potion", "Demondrug", "Amorskin", "bitter bug"};

int main(void)
{
    int money = 0;
    int temp;
    short used_items[ITEM_SIZE];
    int item_id = 0;
    int weapon;
    hunter.defence = 100;
    hunter.hp = 8000;
    monster.defence = 100;
    monster.hp = 12000;
    monster.attack = 400;

    while(if_quit() == 'n')
    {
        srand((unsigned int) time(0));
        for(int i = 0; i < ITEM_QTY; i++) 
        {
            used_items[i] = 0;
        }

        for(int i = 0; i < ITEM_QTY; i++)
        {
            item_id = rand() % 4 + 1;

            while(used_items[item_id] != 0)
            {
                item_id = rand() % 4 + 1;
            }

            item[i].id = item_id;
            item[i].qty = rand() % 4 + 1;
            used_items[item_id] = 1;
        }

        weapon = choose_weapon(&hunter);

        if_upgrade(&money, &hunter);

        show_item(&item, item_name);

        hunter_and_monster(&hunter, &monster, weapon);
    }

    getchar();
    getchar();
    return 0;
}