#include <stdio.h>
int monster_and_hunter(int weapon_attack);
void read_input(char * msg, char * choice);
void hunter_action_a(int * hunter_life, int * monster_life, int * weapon_attack, int * hunter_medicine);
void hunter_action_b(int * hunter_life, int * monster_life, int * weapon_attack, int * hunter_medicine);
void hunter_action_d(int * hunter_life, int * monster_life, int * hunter_medicine);
void hunter_action_c(int * hunter_medicine, int * hunter_life, int * monster_life);
static int shield = 10;
static int grass = 5;
int main(void)
{
    int bow_attack = 200, knife_attack = 150;
    char weapon_choice;
    read_input("Please choose the weapon, bow[b] / knife[k]:\n", &weapon_choice);
    if(weapon_choice == 'b')
    {
        monster_and_hunter(bow_attack);
    }
    else if(weapon_choice == 'k')
    {
        monster_and_hunter(knife_attack);
    }
    getchar();
    getchar();
    return 0;
}


int monster_and_hunter(int weapon_attack)
{
    int hunter_life = 6000, monster_life = 10000, hunter_medicine = 10;
    static int shield = 10;
    char hunter_action = ' ';
    while(hunter_life > 0)
    {
        read_input("Please choose your action, attack[a] / eat[e] / defend[d] / combine[c]: \n", &hunter_action);
        if(hunter_action == 'a')
        {
            hunter_action_a(&hunter_life, &monster_life, &weapon_attack, &hunter_medicine);
        }
        else if(hunter_action == 'e')
        {
            hunter_action_b(&hunter_life, &monster_life, &weapon_attack, &hunter_medicine);
        }
        else if(hunter_action == 'd')
        {
            hunter_action_d(&hunter_life, &monster_life, &hunter_medicine);
        }
        else if(hunter_action == 'c')
        {
            hunter_action_c(&hunter_medicine, &hunter_life, &monster_life);
        }
        if(monster_life <= 0)
        {
            printf("Quest completed.\n");
            return 0;
        }
    }
    printf("Quest failed.\n");
    return 0;
}


void read_input(char * msg, char * choice)
{
    char ch = ' ';
    printf(msg);
    scanf("%c", choice);
    while(ch != '\n') 
    {
        ch = getchar();
    }
}


void hunter_action_a(int * hunter_life, int * monster_life, int * weapon_attack, int * hunter_medicine)
{
    int monster_attack = 300;
    static int attack_count = 0;
    attack_count++;
    if(*hunter_life >= 6000)
    {
        *weapon_attack += 30;
    }
    else
    {
        *weapon_attack -= 60;
    }
    *hunter_life -= monster_attack;
    *monster_life -= *weapon_attack;
    if(attack_count % 5 == 0)
    {
        printf("\a");
        *monster_life -= *weapon_attack;
    }
    printf("M=%d, H=%d, m=%d, s=%d, g=%d\n", *monster_life, *hunter_life, *hunter_medicine, shield, grass);
}


void hunter_action_b(int * hunter_life, int * monster_life, int * weapon_attack, int * hunter_medicine)
{
    if(*hunter_medicine != 0)
    {
        *hunter_life += 500;
        *hunter_medicine -= 1;
        printf("M=%d, H=%d, m=%d, s=%d, g=%d\n", *monster_life, *hunter_life, *hunter_medicine, shield, grass);
    }
    else if(*hunter_medicine == 0)
    {
        printf("No medicine.\n");
    }
}


void hunter_action_d(int * hunter_life, int * monster_life, int * hunter_medicine)
{
    if(shield != 0)
    {
        *monster_life -= 100;
        shield--;
    }
    else if(shield == 0)
    {
        printf("No shield.\n");
    }
    printf("M=%d, H=%d, m=%d, s=%d, g=%d\n", *monster_life, *hunter_life, *hunter_medicine, shield, grass);
}


void hunter_action_c(int * hunter_medicine, int * hunter_life, int * monster_life)
{
    int combine_medicine = 0;
    if(grass != 0)
    {
        printf("How many medicines do you want to combine:\n");
        scanf("%d", &combine_medicine);
        printf("\a");
        grass -= combine_medicine;
        *hunter_medicine += combine_medicine;
    }
    else if(grass == 0)
    {
        printf("No grass.\n");
    }
    printf("M=%d, H=%d, m=%d, s=%d, g=%d\n", *monster_life, *hunter_life, *hunter_medicine, shield, grass);
}