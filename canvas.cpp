#include "canvas.h"

Canvas::Canvas(int width, int height){
    // setting canvas parameters
    this->width = width;
    this->height = height;

    this->window = NULL;
    this->surface = NULL; 
    this->renderer = NULL; 

    //initialize sdl
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ){
        printf( "sdl could not be initialized\n" );
        return;
    }

    //set window
    if( createWindow(this->width, this->height) ){
        printf("sdl window could not be created\n");
        return;
    }

    //set surface
    this->surface = SDL_GetWindowSurface(this->window);

    //set renderer
    this->renderer = SDL_CreateSoftwareRenderer(this->surface);

    // display the canvas
    clearSurface();
    show();
}

Canvas::~Canvas(){
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

//creates a window of the input size
int Canvas::createWindow(const int screen_width, const int screen_height){

    //try and create a window
    this->window = SDL_CreateWindow(
        "Hello World",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        screen_width, screen_height,
        SDL_WINDOW_SHOWN
    );

    //if fails
    if( this->window == NULL ){
        printf("window noot created\n");
        return -1;
    }

    //if passes
    return 0;
}

//black out the canvas
void Canvas::clearSurface(){
    SDL_FillRect(this->surface, NULL, SDL_MapRGB(this->surface->format,0x00,0x00,0x00));
}

//update the window to show the canvas
void Canvas::show(){
    SDL_UpdateWindowSurface(this->window);
}

//place a pixel onto the canvas
void Canvas::putPixel(int canvasX, int canvasY, SDL_Color color){
    //set the color
    SDL_SetRenderDrawColor(this->renderer,color.r,color.g,color.b,color.a);
    //update surface
    SDL_RenderDrawPoint(this->renderer, canvasToScreenX(canvasX), canvasToScreenY(canvasY));
}

//place a pixel onto the canvas
void Canvas::putPixel(int canvasX, int canvasY, int r, int g, int b, int a){
    //set the color
    SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
    //update surface
    SDL_RenderDrawPoint(this->renderer, canvasToScreenX(canvasX), canvasToScreenY(canvasY));
}

//convert from the canvas space to the screen space
int Canvas::canvasToScreenX(int canvasX){
    return (this->width / 2) + canvasX;
}

//convert from the canvas space to the screen space
int Canvas::canvasToScreenY(int canvasY){
    return (this->height / 2) - canvasY;
}

