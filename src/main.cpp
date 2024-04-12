#include <raylib.h>
#include "bird.hpp"
#include "pipe.hpp"
#include <string>

int main() {
    
    const int screen_width = 475;
    const int screen_height = 725;

    InitWindow( screen_width, screen_height, "Floppybird" );
    SetTargetFPS( 30 );

    Pipe pipe1( true );
    Pipe pipe2( false, &pipe1 );
    Bird bord( 75, screen_height / 2 );
    pipe1.setPipe( &pipe2 );

    bool game_running = true;
    int score = 0;
    // Main game loop
    while ( !WindowShouldClose() )    // Detect window close button or ESC key
    {
        
        BeginDrawing();

            ClearBackground( SKYBLUE );
            bord.show();
            pipe1.show();
            pipe2.show();

            DrawText( std::to_string( score ).c_str(), screen_width / 2 - 15, 50, 30, WHITE );

            if ( game_running ) {
                pipe1.move( screen_width );
                pipe2.move( screen_width );
                bord.move( screen_height );

                // Collision
                bool collide_1 = CheckCollisionCircleRec( { (float)bord.x(), (float)bord.y() }, bord.radius(), pipe1.rect() );
                bool collide_2 = CheckCollisionCircleRec( { (float)bord.x(), (float)bord.y() }, bord.radius(), pipe2.rect() );
                bool collide_3 = bord.y() + bord.radius() > screen_height;
                if ( collide_1 || collide_2 || collide_3 ) {
                    game_running = false;
                }

                if ( bord.x() > pipe1.x() && !pipe1.passed()) {
                    pipe1.setPassed( true );
                    pipe2.setPassed( true );
                    score++;
                }
            } else {
                DrawText( "You suck!", 200, screen_height - 50, 22, WHITE );
            }

            if ( IsKeyPressed( KEY_R ) ) {
                bord.setY(screen_height / 2 );
                pipe1.setX( -1000 );
                pipe2.setX( -1000 );

                game_running = true;
                score = 0;
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
