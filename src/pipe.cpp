#include "pipe.hpp"
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#define PIPE_WIDTH  25
#define PIPE_HEIGHT 1000
#define PIPE_GAP_HEIGHT 200

void Pipe::show( void ) {
    myWidth = PIPE_WIDTH;
    myHeight = PIPE_HEIGHT;
    DrawRectangle( myX, myY, myWidth, myHeight, DARKGREEN );
}

void Pipe::move( int p_screen_width ) {
    if ( myX + PIPE_WIDTH < 0 ) reset( p_screen_width );

    myX -= myVelX;
}

void Pipe::reset( int p_screen_width ) {
    myX = p_screen_width;
    myPassed = false;
    if ( myFirstPipe ) {
        pickRandomY();
    } else {
        setNewY( myOtherPipe->y() );
    }
}

void Pipe::pickRandomY() {
    srand( time( 0 ) );
    myY = rand() % 400 - PIPE_HEIGHT;
}

void Pipe::setNewY( int p_y ) {
    myY = p_y + PIPE_HEIGHT + PIPE_GAP_HEIGHT;
}

Rectangle Pipe::rect() const {
    return { (float)myX, (float)myY, (float)myWidth, (float)myHeight };
}
