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
}
