#include "renderer.h"
#include "../inc/raylib.h"

void init_renderer(Renderer* renderer) {

    renderer->screen_width = RENDERER_SCREEN_WIDTH;
    renderer->screen_height = RENDERER_SCREEN_HEIGHT;

    renderer->board_position_x = RENDERER_BOARD_POSITION_X;
    renderer->board_position_y = RENDERER_BOARD_POSITION_Y;
    renderer->board_width = RENDERER_BOARD_WIDTH;
    renderer->board_height = RENDERER_BOARD_HEIGHT;

}

void render_game(Renderer* renderer, Game* game) {

    DrawRectangle(renderer->board_position_x, renderer->board_position_y,
    renderer->board_width, renderer->board_height, RENDERER_BOARD_COLOR);

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
