#include <stdio.h>
#include "../inc/raylib.h"


// own includes
#include "renderer.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    Game game;
    init_game(&game);
    
    Renderer renderer;
    init_renderer(&renderer);

    InputRenderer input_renderer;
    init_input_renderer(&input_renderer);

    InitWindow(renderer.screen_width, renderer.screen_height, "Vier gewinnt");

    SetTargetFPS(60);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        for(int i = 0; i < BOARD_WIDTH; i++) {
            
            if(input_renderer.column_pressed[i]) {
                game.stone_counter += make_move(&game, i);
                input_renderer.column_pressed[i] = false;
            }
        }

        if(check_winner(&game)) {
            game.game_over = true;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(SKYBLUE);

            render_game(&renderer, &game);
            render_input(&input_renderer);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}