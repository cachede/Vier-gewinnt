#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "vier.h"

void init_game(Game* game) {

    for(int y = 0; y < BOARD_HEIGHT; y++) {
        
        for(int x = 0; x < BOARD_WIDTH; x++) {

            game->board[y][x] = ' ';
        }
    }

    for(int i = 0; i < BOARD_WIDTH; i++) {
        
        game->height_array[i] = 0;
    }

    game->stone_counter = 0;
    game->game_over = false;
}

int make_move(Game* game, int column) {

    assert(column < BOARD_WIDTH);
    assert(game != NULL);

    int y_index = game->height_array[column];

    if(y_index >= BOARD_HEIGHT) {
        return 0;
    }
        
    char current_player_piece = game->stone_counter % 2 == 0 ? PLAYER_YELLOW : PLAYER_RED;
    printf("PLAYER %c made a move. \n", current_player_piece);
    game->board[y_index][column] = current_player_piece;
    game->height_array[column] += 1;

    return 1;
    
}

void print_gameboard_terminal(Game* game) {
    
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    for(int i = BOARD_HEIGHT - 1; i >= 0; i--)
    {
        printf("|");
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            printf(" %c |", game->board[i][j]);
        }
        printf("\n---------------------------------\n");
    }
}

bool check_winner(Game* game, int column) {

    //TODO implement the check for a winner
    return check_vertical(game, column); 
}

bool check_vertical(Game* game, int column) {

    if(game->height_array[column] < 4) {
        return false;
    } else {

        char current_player = game->stone_counter % 2 ? PLAYER_YELLOW : PLAYER_RED; //cheeky trick, no?
        int current_height_index = game->height_array[column] - 1;
        
        for(int y = current_height_index; y > current_height_index - FOUR_TO_WIN; y--) {

            if(game->board[y][column] != current_player){
                return false;
            }

        }
        return true;
    }
}

