#pragma once
#include "SDL2/SDL.h"
#include <stdio.h>

class Canvas{

    private:
        int width;
        int height;

        SDL_Window* window;
        SDL_Surface* surface;
        SDL_Renderer* renderer;

        int createWindow(int width, int height);

    public:
        Canvas(int width, int height);
        ~Canvas();

        void clearSurface();
        void show();
        void putPixel(int canvasX, int canvasY, SDL_Color color);
        void putPixel(int canvasX, int canvasY, int r, int g, int b, int a);
        int canvasToScreenX(int canvasX);
        int canvasToScreenY(int canvasY);
};