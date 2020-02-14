#include "ch12e02a.h"

#include <stdio.h>

static int _mode = 0;

static float _fuel = 0;

static int _distance = 0;

void set_mode(int mode)
{
    if(mode > 1)
    {
        printf("Invalid mode specified. Mode %d(%s) used.\n", _mode, _mode == 1?"US":"metric");
    }
    else
    {
        _mode = mode;
    }
}

void get_info(void)
{
    if(_mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%d", &_distance);
        printf("Enter fuel consumed in litters: ");
        scanf("%f", &_fuel);
    }
    else if(_mode == 1)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%d", &_distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", &_fuel);
    }
}

void show_info(void)
{
    if(_mode == 0)
    {
        printf("Fuel consumption is %.2f liters per 100 km.\n", _fuel / _distance * 100);
    }
    else if(_mode == 1)
    {
        printf("Fuel consumption is %.2f miles per gallon.\n", _distance / _fuel);
    }
}