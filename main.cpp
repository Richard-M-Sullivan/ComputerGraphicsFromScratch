#include "SDL2/SDL.h"
#include <stdio.h>
#include "./canvas.h"

int process_events();
void delay(int frame_rate, int start_time_ms, int end_time_ms);

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

    Canvas canvas = Canvas(SCREEN_WIDTH, SCREEN_HEIGHT);

    //draw a pixel
    canvas.putPixel(0,0,0x0FF,0x0FF,0x0FF,0x0FF);
    canvas.show();

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