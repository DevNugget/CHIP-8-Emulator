#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL3/SDL.h>

#define BASE_SCREEN_WIDTH 64
#define BASE_SCREEN_HEIGHT 32

class Chip8_Renderer {
    private:
    
    SDL_Window *window;
    
    int scale;

    int display[BASE_SCREEN_WIDTH * BASE_SCREEN_HEIGHT] = {0};
    
    public:
    SDL_Renderer *renderer;

    Chip8_Renderer(int scale);

    bool set_pixel(int x, int y);
    void clear();
    void render();
    void step(uint32_t delay);
};

#endif
