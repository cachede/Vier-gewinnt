#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "vier.h"

// screen stuff
#define RENDERER_SCREEN_WIDTH  1024
#define RENDERER_SCREEN_HEIGHT 768

// game board stuff
#define RENDERER_BOARD_POSITION_X 150
#define RENDERER_BOARD_POSITION_Y 70
#define RENDERER_BOARD_WIDTH      700
#define RENDERER_BOARD_HEIGHT     650
#define RENDERER_BOARD_COLOR      (Color){ 0, 82, 172, 255 }

#define RENDERER_BALL_RADIUS          50
#define RENDERER_YELLOW_STONE_COLOR (Color){ 255, 203, 0, 255 }
#define RENDERER_RED_STONE_COLOR    (Color){ 230, 41, 55, 255 }

// show current player
#define RENDERER_CURRENT_PLAYER_POSITION_X (RENDERER_BOARD_POSITION_X / 2)
#define RENDERER_CURRENT_PLAYER_POSITION_Y (RENDERER_BOARD_POSITION_Y)
#define RENDERER_CURRENT_PLAYER_OUTLINE_X  (RENDERER_BOARD_POSITION_X / 2 - RENDERER_BALL_RADIUS)
#define RENDERER_CURRENT_PLAYER_OUTLINE_Y  (RENDERER_BOARD_POSITION_Y - RENDERER_BALL_RADIUS)
#define RENDERER_CURRENT_PLAYER_OUTLINE_TOP_LEFT_PADDING 4
#define RENDERER_CURRENT_PLAYER_OUTLINE_BOTTOM_RIGHT_PADDING 4 + 4
#define RENDERER_CURRENT_PLAYER_OUTLINE_THICKNESS 2


#define RENDERER_CURRENT_STONE_POSITION_X (RENDERER_BALL_RADIUS)
#define RENDERER_CURRENT_STONE_POSITION_Y (RENDERER_BALL_RADIUS)

// imput (button...) stuff TODO
#define INPUT_RENDERER_WIDTH 100
#define INPUT_RENDERER_HEIGHT 50
#define INPUT_RENDERER_POSITION_X (RENDERER_BOARD_POSITION_X)
#define INPUT_RENDERER_POSITION_Y (RENDERER_BOARD_POSITION_Y - INPUT_RENDERER_HEIGHT)

typedef struct {
    int screen_width;
    int screen_height;

    int board_position_x;
    int board_position_y;
    int board_width;
    int board_height;


} Renderer;

typedef struct {
    int column_position_x;
    int column_position_y;

    bool column_pressed[BOARD_WIDTH];
    

} InputRenderer;

void init_renderer(Renderer* renderer);
void init_input_renderer(InputRenderer* input_renderer);
void render_game(Renderer* renderer, Game* game);
void render_input(InputRenderer* input_renderer);


#endif // _RENDERER_H_