#include <SDL3/SDL.h>
#include <Chip8/renderer.hpp>
#include <stdio.h>

#define CANVAS_SCALE 8

int main(int argc, char** argv){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    Chip8_Renderer chip8_renderer = Chip8_Renderer(CANVAS_SCALE);

    const char *letters[] = {
        // C
        " #### ", 
        "#     ", 
        "#     ", 
        "#     ", 
        " #### ",
        
        // H
        "#   # ", 
        "#   # ", 
        "##### ", 
        "#   # ", 
        "#   # ",
        
        // I
        " ###  ", 
        "  #   ", 
        "  #   ", 
        "  #   ", 
        " ###  ",
        
        // P
        "####  ", 
        "#   # ", 
        "####  ", 
        "#     ", 
        "#     ",
        
        // -
        "      ", 
        "      ", 
        " ###  ", 
        "      ", 
        "      ",
        
        // 8
        " ###  ", 
        "#   # ", 
        " ###  ", 
        "#   # ", 
        " ###  "
    };
    
    int start_x = 2, start_y = 2;  // Starting position
    int spacing = 6;  // Space between characters
    
    const char *characters = "CHIP-8";
    for (int i = 0; characters[i] != '\0'; i++) {
        for (int row = 0; row < 5; row++) {
            for (int col = 0; letters[i * 5][col] != '\0'; col++) {
                if (letters[i * 5 + row][col] == '#') {
                    chip8_renderer.set_pixel(start_x + col + i * spacing, start_y + row);
                }
            }
        }
    }
    chip8_renderer.render();

    return 0;
}