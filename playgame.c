#include <stdio.h>
#include <stdlib.h>

/* IMPORTING OBJECT FILE */
#include "object.h"
/* IMPORTING undo code file */
#include "undo.c"

/* ----macros for vacant */
#define VACANT 7
#define SNAKE 1
#define PLAYER 0
#define TARGET 6
/* ----macros for cordinates of player---- */
#define PX player->row
#define PY player->col
/* ----macros for cordinates of snake---- */
#define SX snake->row
#define SY snake->col
/* ----macros for cordinates of target---- */
#define TX target->row
#define TY target->col

/* color macros */

#define DEFAULT_COLOR "\033[1;0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define VIOLET "\033[1;35m"
#define CYAN "\033[1;36m"

// 30	Black
// 31	Red
// 32	Green
// 33	Yellow
// 34	Blue
// 35	Magenta
// 36	Cyan
// 37	White
/* ----Bold macros */
#define BOLD "\033[1m"

/* ----GENERAL INFORMATION PRINTING MACROS---- */
#define HEADINFO                                                                                                       \
    printf("\n\033[1mDEVLOPED AND MANAGED BY : \033[1;35mADITYA PATEL\033[1;0m\n");                                    \
    printf("\033[1mTo Download More Game Resources:\033[1;34mhttps://github.com/devloper-AdityaPatel\033[1;0m\n\n\n"); \
    printf("\033[1;36mSNAKE BITE\033[1;0m\n\n\n");
/* ----Movement macros for snake---- */
/* ----up move---- */

/* ----- if condition to check up side of snake is vacant? or is player just above snake? */
#define UP                                                 \
    if (map[SX - 1][SY] == VACANT || map[SX - 1][SY] == 0) \
    {                                                      \
        map[SX - 1][SY] = SNAKE;                           \
        map[SX][SY] = VACANT;                              \
        SX = SX - SNAKE;                                   \
    }

/* ----down move---- */
/* ----- if condition to check down side of snake is vacant? or is player just down snake? */
#define DOWN                                               \
    if (map[SX + 1][SY] == VACANT || map[SX + 1][SY] == 0) \
    {                                                      \
        map[SX + 1][SY] = SNAKE;                           \
        map[SX][SY] = VACANT;                              \
        SX = SX + 1;                                       \
    }
/* ----left move ---- */
/* ----- if condition to check left side of snake is vacant? or is player just left of snake? */
#define LEFT                                               \
    if (map[SX][SY - 1] == VACANT || map[SX][SY - 1] == 0) \
    {                                                      \
        map[SX][SY - 1] = SNAKE;                           \
        map[SX][SY] = VACANT;                              \
        SY = SY - 1;                                       \
    }
/* ----right move---- */
/* ----- if condition to check right side of snake is vacant? or is player just right of snake? */
#define RIGHT                                              \
    if (map[SX][SY + 1] == VACANT || map[SX][SY + 1] == 0) \
    {                                                      \
        map[SX][SY + 1] = SNAKE;                           \
        map[SX][SY] = VACANT;                              \
        SY = SY + 1;                                       \
    }
/* ----macros definition end here for snake movement---- */

/* ----PLAYER CURSOR---- */
char player_cursor = '>';

/* ----map display function defined here---- */
void displaymap(int **map, object metadata)
{ // printing basic info
    HEADINFO
    for (int i = 0; i < metadata.row; i++)
    {
        for (int j = 0; j < metadata.col; j++)
        {
            printf(BOLD);
            // switch to map objectcode with object
            switch (map[i][j])
            {

            case 0:
                printf(GREEN);
                printf("%c", player_cursor);
                printf(DEFAULT_COLOR);
                break;
            case 1:
                printf(RED);
                printf("%c", '~');
                printf(DEFAULT_COLOR);
                break;
            case 2:
                printf(BLUE);
                printf("%c", '|');
                printf(DEFAULT_COLOR);
                break;
            case 3:
                printf(BLUE);
                printf("%c", '-');
                printf(DEFAULT_COLOR);
                break;
            case 4:
                printf(BLUE);
                printf("%c", '*');
                printf(DEFAULT_COLOR);
                break;
            case 5:
                printf("%c", 'O');
                break;
            case 6:
                printf("%c", 'X');
                break;
            case 7:
                printf("%c", ' ');
                break;
            }
        }
        printf("\n");
    }
}
/* ----snake movement alogrithm defined here----- */
void snake_move_algo(int **map, object metadata, object *player, object *snake, object *target)
{
    /* if player is below and right of snake */
    if (PX > SX && PY > SY)
    {
        /* firstly, snake will try to move right if possible
         * then else, will try to move down if possible
         * then else, will try to move left if possible
         * then else, will try to move up if possible  */
        RIGHT
        else DOWN else LEFT else UP
    }
    /* if player is below and left of snake */
    else if (PX > SX && PY < SY)
    {
        /* firstly, snake will try to move left if possible
         * then else, will try to move down if possible
         * then else, will try to move right if possible
         * then else, will try to move up if possible  */
        LEFT else DOWN else RIGHT else UP
    }
    /* if player is above and left of snake */
    else if (PX < SX && PY > SY)
    {
        /* firstly, snake will try to move right if possible
         * then else, will try to move up if possible
         * then else, will try to move left if possible
         * then else, will try to move down if possible  */
        RIGHT
        else UP else LEFT else DOWN
    }
    /* if player is above and left of snake */
    else if (PX < SX && PY < SY)
    {
        /* firstly, snake will try to move left if possible
         * then else, will try to move up if possible
         * then else, will try to move right if possible
         * then else, will try to move down if possible  */
        LEFT else UP else RIGHT else DOWN
    }
    /* if player is in same row(horizontally) and righ of snake */
    else if (PX == SX && PY > SY)
    {
        /* firstly, snake will try to move right if possible
         * then else, will try to move up if possible
         * then else, will try to move down if possible
         * then else, will try to move left if possible  */
        RIGHT
        else UP else DOWN else LEFT
    }
    /* if player is in same row(horizontally) and left of snake */
    else if (PX == SX && PY < SY)
    {
        /* firstly, snake will try to move left if possible
         * then else, will try to move up if possible
         * then else, will try to move down if possible
         * then else, will try to move right if possible  */
        LEFT else UP else DOWN else RIGHT
    }
    /* if player is in same column(vertically) and below the snake */
    else if (PX > SX && PY == SY)
    {
        /* firstly, snake will try to move down if possible
         * then else, will try to move right if possible
         * then else, will try to move left if possible
         * then else, will try to move up if possible  */
        DOWN else RIGHT else LEFT else UP
    }
    /* if player is in same column(vertically) and above of snake */
    else if (PX < SX && PY == SY)
    {
        /* firstly, snake will try to move up if possible
         * then else, will try to move right if possible
         * then else, will try to move left if possible
         * then else, will try to move down if possible  */
        UP else RIGHT else LEFT else DOWN
    }
}
/* ----event loop function defined here ---- */
int eventloop(int **map, object metadata, object *player, object *snake, object *target)
{

    // player movement btn
    char move_btn;

    /* stack pointer for undo operation */
    Node* head= 0;
    //this count variable maintain the number of key presses except 'u' key press;
    int count = 0;

    // event loop defined
    while (1)
    {
        // displaymap function calling
        displaymap(map, metadata);

        scanf(" %c", &move_btn);
        // clear window
        system("cls");

        //if undo btn is not pressed then a push operation will be performed to store current state
        if(move_btn != 'u'){

            Data player_sanke_info;
            player_sanke_info.player=*player;
            player_sanke_info.snake =*snake;
            player_sanke_info.cursor = player_cursor;
            push(&head,player_sanke_info);
            ++count;
        }
        

        /* -------plyaer movement code ------- */
        switch (move_btn)
        {
        // up - movement of player
        case 'w':
            // checking , is player can move up??
            if (map[PX - 1][PY] == VACANT ||map[PX - 1][PY] == TARGET)
            {
                // player move to up
                map[PX - 1][PY] = 0;
                // making previous position vacant
                map[PX][PY] = VACANT;
                // changing player info
                PX = PX - 1;
            }
            player_cursor = '^';
            break;

        case 's':
            // checking , is player can move down??
            if (map[PX + 1][PY] == VACANT || map[PX + 1][PY] == TARGET)
            {
                // player move to down
                map[PX + 1][PY] = 0;
                // making previous position vacant
                map[PX][PY] = VACANT;
                // changing player info
                PX = PX + 1;
            }
            player_cursor = 'v';
            break;

        case 'a':
            // checking , is player can move left??
            if (map[PX][PY - 1] == VACANT || map[PX][PY - 1] == TARGET)
            {
                // player move to left
                map[PX][PY - 1] = 0;
                // making previous position vacant
                map[PX][PY] = VACANT;
                // changing player info
                PY = PY - 1;
            }
            player_cursor = '<';
            break;

        case 'd':
            // checking , is player can move right??
            if (map[PX][PY + 1] == VACANT || map[PX][PY + 1] == TARGET)
            {
                // player move to right
                map[PX][PY + 1] = 0;
                // making previous position vacant
                map[PX][PY] = VACANT;
                // changing player info
                PY = PY + 1;
            }
            player_cursor = '>';
            break;
        case'u':
            // undo variable is to store data that is poped by pop function for undo
            Data undo;

            //count = 0 implies that map is returned to starting position or state
            if(count !=0){
                // pop fucntion is called
                undo = pop(&head);
                /* current position of player and snake  set to vacant */
                map[PX][PY]=VACANT;
                map[SX][SY]=VACANT;

                //current positio of palyer and snake set to pop data values
                map[PX = undo.player.row][PY = undo.player.col] = PLAYER;
                map[SX = undo.snake.row][SY =undo.snake.col] = SNAKE;
                //cursor is set to previous cursor orientation
                player_cursor = undo.cursor;
                //count is decremented by means one undo operation performed;
                count--;

            }

            break;

        default:
            break;
        } // switch case of movement button end here

        // snake-movement-algorithm call
        // if undo is not called then snake will move according to algorithm of snake_move_algo
        if(move_btn !='u'){
            snake_move_algo(map, metadata, player, snake, target);
        }

        if (move_btn == '0') // condition to quiting the game
        {
            break;
            return -1;
        }
        else if (SX == PX && SY == PY)
        { // condition if snake bite the player
            return 0;
        }
        else if (PX == TX && PY == TY)
        { // condition if palyer reached the target
        
            return 1;
        }
    } // end of while loop
}

/* ----playgame function---- */
void playgame(char *filename)
{

    FILE *fptr; // file pointer init

    fptr = fopen(filename, "r"); // opening metadata file in read only mode
    if (fptr == NULL)
    {
        printf("file is not found\n");
        return;
    }
    else
    {

        object metadata; // metadata : this contain (row_size, col_size , obj_count)

        // reading metadata from file
        // file pointer will move to next block
        fread(&metadata, sizeof(object), 1, fptr);

        // pointer to map matrix
        int **map_area;

        // creating map matrix
        map_area = (int **)malloc(metadata.row * sizeof(int *));

        for (int i = 0; i < metadata.col; i++)
        {
            map_area[i] = (int *)malloc(metadata.col * sizeof(int));
        }

        // object variable to store readed object from file temporily
        object obj;

        // object variable to store player position
        object player;
        // object variable to store snake position
        object snake;
        // object variable to store target position
        object target;

        // reading first object from file
        fread(&obj, sizeof(object), 1, fptr); 
        
        for (int i = 0; i < metadata.row; i++)
        {
            for (int j = 0; j < metadata.col; j++)
            {

                if (obj.row == i && obj.col == j)
                {
                    // pushing value into map matrix
                    map_area[i][j] = obj.objCode;

                    // condition to check if object contain player or sanke or target
                    if (obj.objCode == 0)
                    {
                        player = obj;
                    }
                    else if (obj.objCode == 1)
                    {
                        snake = obj;
                    }
                    else if (obj.objCode == 6)
                    {
                        target = obj;
                    }

                    // reading next object from file
                    fread(&obj, sizeof(object), 1, fptr);
                }
                else
                {
                    map_area[i][j] = 7;
                }
            }
        }

        // calling event loop
        int output;
        output = eventloop(map_area, metadata, &player, &snake, &target);
        if (output == -1)
        {
            HEADINFO
            printf("EXITED THE GAME\nTHANKS TO PLAY!!!");
            return;
        }
        else if (output == 0)
        {
            HEADINFO
            printf("YOU LOST THE GAME!\nTHANKS TO PLAY!!!");
            return;
        }
        else if (output == 1)
        {
            HEADINFO
            printf("YOU WON THE GAME!\nTHANKS TO PLAY!!!");
            return;
        }

        // closing file
        fclose(fptr);
    }
}

int main(int argc, char *agrv[])
{
    playgame(agrv[1]);

    return 0;
}