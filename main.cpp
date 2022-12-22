#include "SDL2/SDL.h"
#include <stdio.h>

int main(int argc, char* argv[]){

    //screen size
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //window to render to
    SDL_Window* _window = NULL;

    //surface to draw to
    SDL_Surface* _surface = NULL;

    //initialize SDL, quit if not initialized
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "sdl could not be initialized\n" );
        return 0;
    }

    //create window
    _window = SDL_CreateWindow(
        "Hello World",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    //quit if not initialized
    if( _window == NULL ){
        return 0;
    }
    
    //grab the window surface
    _surface = SDL_GetWindowSurface( _window );

    //draw to the surface
    SDL_FillRect( _surface, NULL, SDL_MapRGB( _surface->format,0x00,0x00,0x00 ) );

    //update the surface
    SDL_UpdateWindowSurface( _window );

    //keep the window open
    SDL_Event e;
    bool quit = false;

    while( quit == false ){
        while( SDL_PollEvent( &e ) ){
            if( e.type == SDL_QUIT ){
                quit = true;
            }
        }
    }

    return 0;
}