#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dllist.h"

#define list_in_list(head) \
    ((head)->next != (head) && (head)->prev != (head))

#define abs(number) \
    ((number) >= 0 ? (number) : -(number))


struct Grid
{
    int x;
    int y;
    int f;
    int g;
    int h;
    struct Grid * parent;
    struct list_head open;
    struct list_head close;
    struct list_head neighbor;
    struct list_head path;
};

#define MAZE_ROWS 10
#define MAZE_COLUMNS 10

int MAZE[MAZE_ROWS][MAZE_COLUMNS] = {
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    { 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    { 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    { 0, 0, 0, 1, 1, 0, 1, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

struct Grid * MAZE_GRIDS[MAZE_ROWS][MAZE_COLUMNS];

void initMazeGrids()
{
    for (int r = 0; r < MAZE_ROWS; r++)
    {
        for (int c = 0; c < MAZE_COLUMNS; c++)
        {
            struct Grid * grid = (struct Grid *) malloc(sizeof(struct Grid));
            MAZE_GRIDS[r][c] = grid;
            grid->x = r;
            grid->y = c;
            grid->f = 0;
            grid->g = 0;
            grid->h = 0;
            grid->parent = NULL;
            INIT_LIST_HEAD(&grid->open);
            INIT_LIST_HEAD(&grid->close);
            INIT_LIST_HEAD(&grid->neighbor);
            INIT_LIST_HEAD(&grid->path);
        }
    }
}

struct Grid* findMinGrid(struct list_head * openList)
{
    struct Grid * tempGrid = list_first_entry(openList, struct Grid, open);
    struct list_head * temp_head;
    struct Grid * grid;
    list_for_each(temp_head, openList)
    {
        grid = list_entry(openList, struct Grid, open);
        if(grid->f < tempGrid->f)
        {
            tempGrid = grid;
        }
    }

    return tempGrid;
}


bool isValidGrid(int x, int y)
{
    if (x < 0 || x >= MAZE_ROWS || y < 0 || y >= MAZE_COLUMNS)
    {
        return false;
    }
    if (MAZE[x][y] == 1)
    {
        return false;
    }
    if (list_in_list(&MAZE_GRIDS[x][y]->open))
    {
        return false;
    }
    if (list_in_list(&MAZE_GRIDS[x][y]->close))
    {
        return false;
    }
    return true;
}


void findNeighbors(struct Grid * grid, struct list_head *neighborList)
{
    int x = 0, y = 0;
    INIT_LIST_HEAD(neighborList);
    x = grid->x;
    y = grid->y - 1; 
    if (isValidGrid(x, y))
    {
        INIT_LIST_HEAD(&(MAZE_GRIDS[x][y])->neighbor);
        list_add_tail(&(MAZE_GRIDS[x][y])->neighbor, neighborList); 
    }
    x = grid->x;
    y = grid->y + 1;
    if (isValidGrid(x, y))
    {
        INIT_LIST_HEAD(&(MAZE_GRIDS[x][y])->neighbor);
        list_add_tail(&(MAZE_GRIDS[x][y])->neighbor, neighborList);    
    }
    x = grid->x - 1;
    y = grid->y;
    if (isValidGrid(x, y))
    {
        INIT_LIST_HEAD(&(MAZE_GRIDS[x][y])->neighbor);
        list_add_tail(&(MAZE_GRIDS[x][y])->neighbor, neighborList);    
    }
    x = grid->x + 1;
    y = grid->y;
    if (isValidGrid(x, y))
    {
        INIT_LIST_HEAD(&(MAZE_GRIDS[x][y])->neighbor);
        list_add_tail(&(MAZE_GRIDS[x][y])->neighbor, neighborList);    
    }
}

void initGrid(struct Grid * current, struct Grid * parent, struct Grid * end)
{
    current->parent = parent;
    if(parent != NULL)
    {
        current->g = parent->g + 1;
    }
    else
    {
        current->g = 1;
    }
    current->h = abs(current->x - end->x) + abs(current->y - end->y);
    current->f = current->g + current->h;
}

struct Grid* aStarSearch(struct Grid * start, struct Grid * end)
{
    LIST_HEAD(openList);
    LIST_HEAD(closeList);
    LIST_HEAD(neighborsList);
    struct Grid * currentGrid;
    struct list_head * temp_head;
    struct Grid * temp_grid;
    list_add_tail(&start->open, &openList);
    while(!list_empty(&openList))
    {
        currentGrid = findMinGrid(&openList);
        //printf("[%d, %d, (%d)]\n", currentGrid->x, currentGrid->y, currentGrid->f);
        list_del_init(&currentGrid->open);
        list_add_tail(&currentGrid->close, &closeList);
        findNeighbors(currentGrid, &neighborsList);
        list_for_each(temp_head, &neighborsList)
        {
            temp_grid = list_entry(temp_head, struct Grid, neighbor);
            if(!list_in_list(&temp_grid->open))
            {
                initGrid(temp_grid, currentGrid, end);
                list_add_tail(&temp_grid->open, &openList);
            }
        }

        list_for_each(temp_head, &openList)
        {
            temp_grid = list_entry(temp_head, struct Grid, open);
            if((temp_grid->x == end->x) && (temp_grid->y == end->y))
            {
                return temp_grid;
            }
        }
    }

    return NULL;
}

int main(void)
{
    struct Grid * startGrid;
    struct Grid * endGrid;
    struct Grid * resultGrid;
    LIST_HEAD(path);
    initMazeGrids();
    startGrid = MAZE_GRIDS[4][2];
    endGrid = MAZE_GRIDS[4][9];
    resultGrid = aStarSearch(startGrid, endGrid);
   
    while(resultGrid != NULL)
    {
        list_add_tail(&resultGrid->path, &path);
        resultGrid = resultGrid->parent;
    }

    for(int i = 0; i < MAZE_ROWS; i++)
    {
        for(int j = 0; j < MAZE_COLUMNS; j++)
        {
            if(list_in_list(&MAZE_GRIDS[i][j]->path))
            {
                printf("*, ");
            }
            else
            {
                printf("%d, ", MAZE[i][j]);
            }
            
        }
        printf("\n");
    }
    getchar();
    getchar();
    return 0;
}