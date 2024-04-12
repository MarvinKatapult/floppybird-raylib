#pragma once

typedef struct Rectangle Rectangle;

class Pipe{

    public:

        Pipe( bool is_first_pipe, Pipe * other_pipe = 0L ) 
            : myX( -1000 ), myY( -1000 ), myVelX( 3 ), myFirstPipe( is_first_pipe ), myOtherPipe( other_pipe ), myPassed( false ) { }

        void show( void );
        void move( int screen_width );

        int x( void ) const { return myX; }
        int y( void ) const { return myY; }

        Rectangle rect( void ) const;
        bool passed( void ) const { return myPassed; } 

        void setX( int x ) { myX = x; }
        void setPipe( Pipe * pipe ) { myOtherPipe = pipe; }
        void setPassed( bool passed ) { myPassed = passed; }

    private:

        void reset( int screen_width );
        void setNewY( int y );
        void pickRandomY( void );

        int myX, myY;
        int myWidth, myHeight;
        int myVelX;

        bool myFirstPipe;
        Pipe * myOtherPipe;
        bool myPassed;
};
