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

    InitWindow(renderer.screen_width, renderer.screen_height, "Vier gewinnt");

    SetTargetFPS(60);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(SKYBLUE);

            render_game(&renderer, &game);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}