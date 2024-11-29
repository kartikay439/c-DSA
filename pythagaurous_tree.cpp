#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Function to draw the Pythagoras Tree recursively
void drawTree(SDL_Renderer* renderer, int x, int y, int size, float angle, int depth) {
    if (depth == 0) return;

    // Calculate the end position of the square based on the current angle
    int x2 = x + size * cos(angle);
    int y2 = y - size * sin(angle);

    // Set the color of the branch (darker as we go deeper)
    int colorValue = 255 - (depth * 15);  // Darker color for deeper branches
    SDL_SetRenderDrawColor(renderer, colorValue, colorValue, 255, 255); // Blueish

    // Debugging: Check if the line is being drawn
    std::cout << "Drawing line from (" << x << ", " << y << ") to (" << x2 << ", " << y2 << ")\n";

    // Draw a line representing the base of the square (branch of the tree)
    SDL_RenderDrawLine(renderer, x, y, x2, y2);

    // Calculate the new size of the square for the next depth level
    int newSize = size * std::sqrt(2) / 2;

    // Draw the two branches recursively (rotate by -45 and +45 degrees)
    drawTree(renderer, x2, y2, newSize, angle - M_PI / 4, depth - 1); // Left branch
    drawTree(renderer, x2, y2, newSize, angle + M_PI / 4, depth - 1); // Right branch
}

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create the window
    SDL_Window* window = SDL_CreateWindow("Pythagoras Tree",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Create the renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Set the initial parameters for the tree
    int startX = WINDOW_WIDTH / 2;  // Center horizontally
    int startY = WINDOW_HEIGHT - 30;  // Start from near the bottom of the window
    int size = 60;  // Initial size of the root square
    float angle = -M_PI / 2;  // Initial angle pointing upward
    int depth = 12;  // Depth of the recursion (more branches)

    // Main loop
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the window with a black color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
        SDL_RenderClear(renderer);

        // Draw the Pythagoras Tree
        drawTree(renderer, startX, startY, size, angle, depth);

        // Present the rendered content to the screen
        SDL_RenderPresent(renderer);
    }

    // Clean up and quit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
