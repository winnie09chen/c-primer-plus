#include <stdio.h>
int monster_and_hunter(int weapon_attack);
void read_input(char * msg, char * choice);
void hunter_action_a(int * hunter_life, int * monster_life, int * weapon_attack, int * hunter_medicine);
void hunter_action_e(int * hunter_life, int * monster_life, int * weapon_attack, int * hunter_medicine);
void hunter_action_d(int * hunter_life, int * monster_life, int * hunter_medicine);
static int shield = 10;
static int grass = 5;
static int rock = 5;
static int money = 0;
char quit_choice;
int main(void)
{
    static int hammer_attack = 200, knife_attack = 150;
    char weapon_choice, upgrade_choice;
    printf("Do you want to quit? [y/n]: \n");
    scanf("%c", &quit_choice);
    getchar();
    while(quit_choice == 'n')
    {
        read_input("Please choose the weapon, hammer[h] / knife[k]:\n", &weapon_choice);
        if(weapon_choice == 'h')
        {
            printf("Do you want to upgrade your weapon? (need 300 money) You have %d money. [y/n]:\n", money);
            scanf("%c", &upgrade_choice);
            getchar();
            if(upgrade_choice == 'y' && money == 400)
            {
                hammer_attack += 50;
                money = 0;
            }    
            else if(upgrade_choice == 'y' && money < 400)
                printf("No money\n");
            monster_and_hunter(hammer_attack);
        }
        else if(weapon_choice == 'k')
        {
            printf("Do you want to upgrade your weapon? (need 300 money) [y/n]:\n");
            scanf("%c", &upgrade_choice);
            getchar();
            if(upgrade_choice == 'y' && money == 300)
            {
                knife_attack += 50;
                money = 0;
            }  
            else if(upgrade_choice == 'y' && money < 300)
                printf("No money\n");
            monster_and_hunter(knife_attack);
        }
    }
    getchar();
    getchar();
    return 0;
}


int monster_and_hunter(int weapon_attack)
{
    static int hunter_life = 6000, monster_life = 14000, hunter_medicine = 10, monster_strength = 1, level = 1;
    static int shield = 10;
    char hunter_action = ' ';
    while(hunter_life > 0)
    {
        read_input("Please choose your action, attack[a] / eat[e] / defend[d]: \n", &hunter_action);
        if(hunter_action == 'a')
        {
            hunter_action_a(&hunter_life, &monster_life, &weapon_attack, &hunter_medicine);
        }
        else if(hunter_action == 'e')
        {
            hunter_action_e(&hunter_life, &monster_life, &weapon_attack, &hunter_medicine);
        }
        else if(hunter_action == 'd')
        {
            hunter_action_d(&hunter_life, &monster_life, &hunter_medicine);
        }
        if(monster_life <= 0)
        {
            printf("Quest completed.\n");
            printf("Do you want to quit? [y/n]:\n");
            scanf("%c", &quit_choice);
            getchar();
            if(quit_choice == 'y')
            {
                return 0;
            }
            money += 200;
            printf("money = %d\n", money);
            monster_strength++;
            if(monster_strength % 2 == 0)
            {
                level++;
                printf("monster level = %d\n", level);
                monster_life += 300;
            }
        }
    }
    printf("Quest failed.\n");
    printf("Do you want to quit? [y/n]:\n");
    scanf("%c", &quit_choice);
    getchar();
    if(quit_choice == 'y')
    {
        return 0;
    }
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
    static int sharpness_count = 0;
    char sharp_choice;
    sharpness_count++;
    if(sharpness_count == 4)
    {
        *weapon_attack -= 10;
        printf("\a");
        printf("Sharpness reduced.\n");
        sharpness_count = 0;
        printf("Do you want to sharp your weapon?[y/n]\n");
        scanf("%c", &sharp_choice);
        getchar();
        if(sharp_choice == 'y' && rock > 0)
        {
            *weapon_attack += 10;
            rock--;
        }
        else if(rock <= 0)
        {
            printf("No rock.\n");
        }
    }
    if(weapon_attack <= 0)
    {
        weapon_attack = 0;
    }
    *hunter_life -= monster_attack;
    *monster_life -= *weapon_attack;
    if(attack_count % 5 == 0)
    {
        printf("\a");
        *monster_life -= *weapon_attack;
    }
    printf("M=%d, H=%d, m=%d, s=%d, g=%d, r=%d\n", *monster_life, *hunter_life, *hunter_medicine, shield, grass, rock);
}


void hunter_action_e(int * hunter_life, int * monster_life, int * weapon_attack, int * hunter_medicine)
{
    char combine_choice;
    static int combine_medicine = 0;
    if(*hunter_medicine != 0)
    {
        *hunter_life += 500;
        *hunter_medicine -= 1;
        printf("Do you want to combine the medicine?[y/n]\n");
        scanf("%c", &combine_choice);
        getchar();
        if(combine_choice == 'y' && grass > 0)
        {
            printf("How many medicines do you want to combine:\n");
            scanf("%d", &combine_medicine);
            getchar();
            printf("\a");
            if (combine_medicine >  grass)
                combine_medicine = grass;
            grass -= combine_medicine;
            *hunter_medicine += combine_medicine;
        }
        else if(combine_choice == 'y' && grass <= 0)
        {
            printf("No grass.\n");
        }
        printf("M=%d, H=%d, m=%d, s=%d, g=%d, r=%d\n", *monster_life, *hunter_life, *hunter_medicine, shield, grass, rock);
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
    printf("M=%d, H=%d, m=%d, s=%d, g=%d, r=%d\n", *monster_life, *hunter_life, *hunter_medicine, shield, grass, rock);
}