#ifndef _VIER_H_
#define _VIER_H_

#define BOARD_WIDTH  7
#define BOARD_HEIGHT 6
#define BOARD_HOLES  42

#include <stdbool.h>


typedef struct {
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    int height_array[BOARD_WIDTH];
    int stone_counter;
    bool game_over;
} Game;


void init_game(Game *game);
int make_move(Game *game, int column);
void print_gameboard_terminal(Game* game);
bool check_winner(Game* game);

#endif // _VIER_H_