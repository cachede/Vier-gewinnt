#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "vier.h"

// screen stuff
#define RENDERER_SCREEN_WIDTH  1200
#define RENDERER_SCREEN_HEIGHT 800

// game board stuff
#define RENDERER_BOARD_POSITION_X 100
#define RENDERER_BOARD_POSITION_Y 50
#define RENDERER_BOARD_WIDTH      700
#define RENDERER_BOARD_HEIGHT     650
#define RENDERER_BOARD_COLOR      (Color){ 102, 191, 255, 255 }

#define RENDERER_STONE_SIZE         25
#define RENDERER_YELLOW_STONE_COLOR (Color){ 255, 203, 0, 255 }
#define RENDERER_RED_STONE_COLOR    (Color){ 230, 41, 55, 255 }

// imput (button...) stuff TODO

typedef struct {
    int screen_width;
    int screen_height;

    int board_position_x;
    int board_position_y;
    int board_width;
    int board_height;


} Renderer;

typedef struct {
    //TODO
    int a;
} InputRenderer;

void init_renderer(Renderer* renderer);
void render_game(Renderer* renderer, Game* game);



#endif // _RENDERER_H_