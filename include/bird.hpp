#pragma once

#define BIRD_RADIUS         17

class Bird {
    
    public:

        Bird( int x, int y ) : myX( x ), myY( y ), myVelY( 0 ), myAccY( 0 ), myRadius( BIRD_RADIUS ) { }
        ~Bird( void ) { }

        void show( void ) const;
        void move( int screen_height );

        int x( void ) { return myX; }
        int y( void ) { return myY; }
        int radius( void ) { return myRadius; }

        void setY( int y ) { myY = y; }

    private:

        void jump( void );

        int myX, myY;
        int myVelY;
        int myAccY;
        int myRadius;
};
