#include <Chip8/renderer.hpp>
#include <stdio.h>
#include <cmath>

Chip8_Renderer::Chip8_Renderer(int scale) {
    this->scale = scale;

    this->window = SDL_CreateWindow("Chip 8 Emulator", BASE_SCREEN_WIDTH * this->scale, BASE_SCREEN_HEIGHT * this->scale, SDL_WINDOW_RESIZABLE);
    if(!this->window){
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        exit(1);
    }

    this->renderer = SDL_CreateRenderer(this->window , NULL);
    if(!this->renderer){
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        exit(1);
    }
}

bool Chip8_Renderer::set_pixel(int _x, int _y) {
    int x = _x;
    int y = _y;

    // According to the technical reference, if a pixel is positioned outside of the bounds of the display, 
    // it should wrap around to the opposite side
    if (x > BASE_SCREEN_WIDTH) {
        x -= BASE_SCREEN_WIDTH;
    } else if (x < 0) {
        x += BASE_SCREEN_WIDTH;
    }
    
    if (y > BASE_SCREEN_HEIGHT) {
        y -= BASE_SCREEN_HEIGHT;
    } else if (y < 0) {
        y += BASE_SCREEN_HEIGHT;
    }

    int pixel_location = x + (y * BASE_SCREEN_WIDTH);

    // According to the technical reference, sprites are XORed onto the display:
    this->display[pixel_location] ^= 1;

    return !this->display[pixel_location];
}

void Chip8_Renderer::clear() {
    for (int pixel = 0; pixel < BASE_SCREEN_WIDTH * BASE_SCREEN_HEIGHT; pixel++) {
        this->display[pixel] = 0;
    }
}

void Chip8_Renderer::render() {
    bool running = true;
    while(running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_EVENT_QUIT:
                    running = false;
                    break;

                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
        SDL_RenderClear(this->renderer);

        for (int i = 0; i < BASE_SCREEN_WIDTH * BASE_SCREEN_HEIGHT; i++) {
            int x = (i % BASE_SCREEN_WIDTH) * this->scale;

            int y = std::floor(i / BASE_SCREEN_WIDTH) * this->scale;

            if (this->display[i] == 1) {
                SDL_FRect pixel;
                pixel.x = x;
                pixel.y = y;
                pixel.w = this->scale;
                pixel.h = this->scale;

                SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
                SDL_RenderFillRect(this->renderer, &pixel);
            }
        }

        SDL_RenderPresent(this->renderer);

        this->step(16);
    }
}

void Chip8_Renderer::step(uint32_t delay) {
    SDL_Delay(delay);
}