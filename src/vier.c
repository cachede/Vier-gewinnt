#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "vier.h"

static bool check_vertical(Game* game, int column);
static bool check_horizontal(Game* game, int column);
static bool check_diagonal(Game* game, int column);
static int  check_range(Game* game, int start_x, int start_y, int end_x, int end_y, char target_player);

void init_game(Game* game) {

    for(int y = 0; y < BOARD_HEIGHT; y++) {
        
        for(int x = 0; x < BOARD_WIDTH; x++) {

            game->board[y][x] = ' ';
        }
    }

    for(int i = 0; i < BOARD_WIDTH; i++) {
        
        game->height_size_array[i] = 0;
    }

    game->stone_counter = 0;
    game->game_over = false;
}

int make_move(Game* game, int column) {

    assert(column < BOARD_WIDTH);
    assert(game != NULL);

    int y_index = game->height_size_array[column];

    if(y_index >= BOARD_HEIGHT) {
        return 0;
    }
        
    char current_player_piece = game->stone_counter % 2 == 0 ? PLAYER_YELLOW : PLAYER_RED;
    game->board[y_index][column] = current_player_piece;
    game->height_size_array[column] += 1;

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

    return check_vertical(game, column) || check_horizontal(game, column) || check_diagonal(game, column); 
}

static bool check_vertical(Game* game, int column) {

    if(game->height_size_array[column] < FOUR_TO_WIN) {
        return false;
    } else {

        char current_player = game->stone_counter % 2 ? PLAYER_YELLOW : PLAYER_RED; //cheeky trick, no?
        int current_height_index = game->height_size_array[column] - 1;

        int win_counter = 1;

        win_counter += check_range(game, column, current_height_index - 1, column, current_height_index - 4, current_player);
        return win_counter >= FOUR_TO_WIN;
    }
}

static bool check_horizontal(Game* game, int column) {

    char current_player = game->stone_counter % 2 ? PLAYER_YELLOW : PLAYER_RED;
    int y_index = game->height_size_array[column] - 1;

    int win_counter = 1;
    int search_index_x = column - 1;

    // rechts check
    win_counter += check_range(game, column + 1, y_index, column + 4, y_index, current_player);
    // links check
    win_counter += check_range(game, column - 1, y_index, column - 4, y_index, current_player);

    return win_counter >= FOUR_TO_WIN;
}

static bool check_diagonal(Game* game, int column) {

    char current_player = game->stone_counter % 2 ? PLAYER_YELLOW : PLAYER_RED;
    int win_counter = 1;

    int current_player_y = game->height_size_array[column] - 1;
    int search_index_x = column - 1;
    int search_index_y = current_player_y - 1;
    int end_index_x = column - 4;
    int end_index_y = current_player_y - 4;

    // bottom left check
    win_counter += check_range(game, 
        search_index_x, search_index_y, 
        end_index_x, end_index_y, 
        current_player);


    search_index_y = game->height_size_array[column];
    search_index_x = column + 1;
    end_index_x = column + 4;
    end_index_y = current_player_y + 4;

    // top right check
    win_counter += check_range(game, 
        search_index_x, search_index_y, 
        end_index_x, end_index_y, 
        current_player);

    if(win_counter >= FOUR_TO_WIN) {
        return true;
    }

    win_counter = 1;

    // bottom right side check
    search_index_y = game->height_size_array[column] - 1;
    search_index_x = column + 1;
    search_index_y -= 1;
    end_index_x = column + 4;
    end_index_y = current_player_y - 4;

    win_counter += check_range(game, 
        search_index_x, search_index_y, 
        end_index_x, end_index_y, 
        current_player);

    search_index_y = game->height_size_array[column];
    search_index_x = column - 1;
    end_index_x = column - 4;
    end_index_y = current_player_y + 4;

    // top left side check
    win_counter += check_range(game, 
        search_index_x, search_index_y, 
        end_index_x, end_index_y, 
        current_player);

    return win_counter >= FOUR_TO_WIN;
}

// start_x = inclusive | end_x = EXclusive => analog y 
static int check_range(Game* game, int start_x, int start_y, int end_x, int end_y, char target_player) {

    int win_counter = 0;

    int x = start_x;
    int y = start_y;

    int dy = end_y - start_y;
    int dx = end_x - start_x;

    int inc_x = dx > 0 ? 1 : -1;
    int inc_y = dy > 0 ? 1 : -1;

    int i = 0;

    printf("DY = %d     DX = %d\n", dy, dx);
    // steil nach oben oder unten
    if(abs(dy) <= abs(dx)) {

        while(x != end_x && x < BOARD_WIDTH && y < BOARD_HEIGHT && x >= 0 && y >= 0) {
            printf("x = %d      y = %d\n", x, y);
            char current_stone = game->board[y][x];
            
            if(current_stone == target_player) {
                win_counter++;
            } else {
                return win_counter;  
            } 
            
            if(dy != 0) {
                y += inc_y;
            }
            x += inc_x;
        }
        
    } else {
        // vertical check, x unverändert
        while(y != end_y && y < BOARD_HEIGHT && y >= 0) {
            
            char current_stone = game->board[y][x];

            if(current_stone == target_player) {
                win_counter++;
            } else {
                return win_counter;
            }

            y += inc_y;

        }
    }

    return win_counter;
}

