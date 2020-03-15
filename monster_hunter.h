#ifndef __MONSTER_HUNTER_H
#define __MONSTER_HUNTER_H

#define ITEM_QTY 3
#define ITEM_SIZE 5

struct item
{
    int qty;
    int id;
};

struct hunter
{
    int attack;
    int defence;
    int hp;
};

struct monster
{
    int attack;
    int defence;
    int hp;
};

char if_quit(void);

void if_upgrade(int * money, struct hunter * hunter);

int choose_weapon(struct hunter * hunter);

void show_item(struct item * item, char * item_name[]);

void hunter_and_monster(struct hunter * hunter, struct monster * monster, int weapon);

char get_input(char ch);

void bow_act(struct hunter * hunter, struct monster * monster);

void show_hp(struct hunter * hunter, struct monster * monster);

#endif
