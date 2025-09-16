#ifndef _VIER_H_
#define _VIER_H_

#define BOARD_WIDTH  7
#define BOARD_HEIGHT 6
#define BOARD_HOLES  42
#define FOUR_TO_WIN  4
#define PLAYER_YELLOW 'X'
#define PLAYER_RED 'O'

#include <stdbool.h>


typedef struct {
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    int height_size_array[BOARD_WIDTH];
    int stone_counter;
    bool game_over;
} Game;


void init_game(Game *game);
int make_move(Game *game, int column);
void print_gameboard_terminal(Game* game);
bool check_winner(Game* game, int column);
//TODO eine get_current_player funktion fehlt noch einfachhalthalber...


#endif // _VIER_H_