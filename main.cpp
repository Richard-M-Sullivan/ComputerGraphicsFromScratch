#include "SDL2/SDL.h"
#include <stdio.h>

int process_events();
void delay(int frame_rate, int start_time_ms, int end_time_ms);
int createWindow(SDL_Window* &_window, int screen_width, int screen_height);
void clearSurfaceBlack(SDL_Surface* &_surface);

int main(int argc, char* argv[]){

    //window constraints
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int FRAME_RATE = 60;
    const int DESIRED_DELTA = 1000 / FRAME_RATE;


    //hooks to window, window's surface, and a renderer to draw to the surface
    SDL_Window* _window = NULL;
    SDL_Surface* _surface = NULL;
    SDL_Renderer* _renderer = NULL;

    //initialize SDL, quit if not initialized
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ){
        printf( "sdl could not be initialized\n" );
        return 0;
    }

    //create window
    if( createWindow(_window, SCREEN_WIDTH, SCREEN_HEIGHT) ){
        printf("sdl window could not be created\n");
        return 0;
    }

    //get surface
    _surface = SDL_GetWindowSurface(_window);
    //create renderer
    _renderer = SDL_CreateSoftwareRenderer(_surface);

    //clear the window
    clearSurfaceBlack(_surface);

    //draw a pixel
    SDL_SetRenderDrawColor(_renderer,0xFF,0xFF,0xFF,0xFF);
    SDL_RenderDrawPoint(_renderer, 100,100);

    //update the window to se changes
    SDL_UpdateWindowSurface(_window);

    //loop flag
    bool quit = false;

    //variables to calculate delay
    int start_time = 0;
    int end_time = 0;

    //application loop
    while( !quit ){

        start_time = SDL_GetTicks();

        quit = process_events();

        end_time = SDL_GetTicks();
        
        delay(DESIRED_DELTA, start_time, end_time);

    }

    //destroy the window
    SDL_DestroyWindow(_window);

    //quit SDL2
    SDL_Quit();

    return 0;
}

// processes the events, and returns if the user wants to quit
int process_events(){
    //hook to hold onto events
    SDL_Event e;
    //process each event
    while( SDL_PollEvent(&e) ){
        // if a quit event, return quit
        if( e.type == SDL_QUIT ){
            return -1;
        }
    }

    // if no quit events, then return true
    return 0;
}

// delays so that the time elapsed is equal to the desired delta
void delay(int desired_delta, int start_time_ms, int end_time_ms){
    //how long has it been
    int delta = end_time_ms - start_time_ms;

    // if it hasn't been long enough
    if( delta < desired_delta ){
        // delay to desired framerate 
        SDL_Delay(desired_delta - delta );
    }
}

void clearSurfaceBlack(SDL_Surface* &_surface){
    SDL_FillRect(_surface, NULL, SDL_MapRGB(_surface->format,0x00,0x00,0x00));
}

int createWindow(SDL_Window* &_window, const int screen_width, const int screen_height){

    //try and create a window
    _window = SDL_CreateWindow(
        "Hello World",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        screen_width, screen_height,
        SDL_WINDOW_SHOWN
    );

    //if fails return false
    if( _window == NULL ){
        printf("window noot created\n");
        return -1;
    }

    //if passes return true
    return 0;
}
