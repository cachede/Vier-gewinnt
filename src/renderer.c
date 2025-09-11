#include "renderer.h"
#include "../inc/raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "../inc/raygui.h"


void init_renderer(Renderer* renderer) {

    renderer->screen_width = RENDERER_SCREEN_WIDTH;
    renderer->screen_height = RENDERER_SCREEN_HEIGHT;

    renderer->board_position_x = RENDERER_BOARD_POSITION_X;
    renderer->board_position_y = RENDERER_BOARD_POSITION_Y;
    renderer->board_width = RENDERER_BOARD_WIDTH;
    renderer->board_height = RENDERER_BOARD_HEIGHT;

}

void init_input_renderer(InputRenderer* input_renderer) {

    input_renderer->column_position_x = INPUT_RENDERER_POSITION_X;
    input_renderer->column_position_y = INPUT_RENDERER_POSITION_Y;

    for(int i = 0; i < BOARD_WIDTH; i++) {
        input_renderer->column_pressed[i] = false;
    }

}

void render_game(Renderer* renderer, Game* game) {

    DrawRectangle(renderer->board_position_x, renderer->board_position_y,
    renderer->board_width, renderer->board_height, RENDERER_BOARD_COLOR);

    
    if(game->stone_counter < 42 && !game->game_over) {
        DrawRectangleLinesEx((Rectangle) {RENDERER_CURRENT_PLAYER_OUTLINE_X - RENDERER_CURRENT_PLAYER_OUTLINE_TOP_LEFT_PADDING, 
            RENDERER_CURRENT_PLAYER_OUTLINE_Y - RENDERER_CURRENT_PLAYER_OUTLINE_TOP_LEFT_PADDING, 
            100 + RENDERER_CURRENT_PLAYER_OUTLINE_BOTTOM_RIGHT_PADDING, 
            100 + RENDERER_CURRENT_PLAYER_OUTLINE_BOTTOM_RIGHT_PADDING}, RENDERER_CURRENT_PLAYER_OUTLINE_THICKNESS, YELLOW);

        int current_player = game->stone_counter;
        if(current_player % 2 == 0) {
            DrawCircle(RENDERER_CURRENT_PLAYER_POSITION_X, RENDERER_CURRENT_PLAYER_POSITION_Y, RENDERER_BALL_RADIUS, RENDERER_YELLOW_STONE_COLOR);
        } else {
            DrawCircle(RENDERER_CURRENT_PLAYER_POSITION_X, RENDERER_CURRENT_PLAYER_POSITION_Y, RENDERER_BALL_RADIUS, RENDERER_RED_STONE_COLOR);    
        }
    }

    int x_position = RENDERER_BOARD_POSITION_X + RENDERER_BALL_RADIUS;
    int y_position = RENDERER_BOARD_POSITION_Y + RENDERER_BOARD_HEIGHT - RENDERER_BALL_RADIUS;

    for(int y = 0; y < BOARD_HEIGHT; y++) {
        
        for(int x = 0; x < BOARD_WIDTH; x++) {
        
            Color color;
            char current_field_figure = game->board[y][x];
            if(current_field_figure != ' ') {

                color = current_field_figure == 'X' ? RENDERER_YELLOW_STONE_COLOR : RENDERER_RED_STONE_COLOR;
            } else {

                color = WHITE;
            }

            DrawCircle(x_position, y_position, RENDERER_BALL_RADIUS, color);
            x_position += RENDERER_BALL_RADIUS * 2;
        }
        x_position = RENDERER_BOARD_POSITION_X + RENDERER_BALL_RADIUS;
        y_position -= RENDERER_BALL_RADIUS * 2;
    }

}

void render_input(InputRenderer* input_renderer) {

    GuiSetStyle(DEFAULT, TEXT_SIZE, 29);

    for(int i = 0; i < BOARD_WIDTH; i++) {
        
        char str[5];
        sprintf(str, "%d", i + 1);
        if (GuiButton((Rectangle){input_renderer->column_position_x , input_renderer->column_position_y, INPUT_RENDERER_WIDTH, INPUT_RENDERER_HEIGHT }, 
        GuiIconText(ICON_ARROW_DOWN_FILL, str))) { 
        
            printf("BUTTON %d pressed\n", i + 1);
            input_renderer->column_pressed[i] = true; 
        }

        input_renderer->column_position_x += INPUT_RENDERER_WIDTH;
    }

    input_renderer->column_position_x = INPUT_RENDERER_POSITION_X;

}
