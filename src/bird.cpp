#include "bird.hpp"
#include <raylib.h>

#define BIRD_GRAVITY        1
#define BIRD_JUMP_STRENGTH  -30
#define BIRD_SPEED_CAP      10

void Bird::show() const {
    DrawCircle( myX, myY, myRadius, PINK ); 
}

void Bird::move( int p_screen_height ) {
    myAccY += BIRD_GRAVITY;
    if ( myVelY < BIRD_SPEED_CAP ) myVelY += myAccY;
    if ( myY < p_screen_height ) myY += myVelY;

    if ( IsKeyPressed( KEY_SPACE ) ) jump();
}

void Bird::jump() {
    myVelY = BIRD_JUMP_STRENGTH; 
    myAccY = 0;
}
