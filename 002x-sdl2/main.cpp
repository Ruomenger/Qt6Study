extern "C" {
#include <SDL2/SDL.h>
}

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Event event;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 3;
    }

    if(SDL_CreateWindowAndRenderer(320, 240, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 3;
    }

    while(1) {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) {
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}

// int main(int argc, char* argv[]) {
//     using std::cerr;
//     using std::endl;
//
//     if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//         cerr << "SDL_Init Error: " << SDL_GetError() << endl;
//         return EXIT_FAILURE;
//     }
//
//     SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 620, 387, SDL_WINDOW_SHOWN);
//     if(win == nullptr) {
//         cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
//         return EXIT_FAILURE;
//     }
//
//     SDL_Renderer *ren
//         = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//     if(ren == nullptr) {
//         cerr << "SDL_CreateRenderer Error" << SDL_GetError() << endl;
//         if(win != nullptr) {
//             SDL_DestroyWindow(win);
//         }
//         SDL_Quit();
//         return EXIT_FAILURE;
//     }
//
//     SDL_Surface *bmp = SDL_LoadBMP("img/grumpy-cat.bmp");
//     if(bmp == nullptr) {
//         cerr << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
//         if(ren != nullptr) {
//             SDL_DestroyRenderer(ren);
//         }
//         if(win != nullptr) {
//             SDL_DestroyWindow(win);
//         }
//         SDL_Quit();
//         return EXIT_FAILURE;
//     }
//
//     SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
//     if(tex == nullptr) {
//         cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << endl;
//         if(bmp != nullptr) {
//             SDL_FreeSurface(bmp);
//         }
//         if(ren != nullptr) {
//             SDL_DestroyRenderer(ren);
//         }
//         if(win != nullptr) {
//             SDL_DestroyWindow(win);
//         }
//         SDL_Quit();
//         return EXIT_FAILURE;
//     }
//     SDL_FreeSurface(bmp);
//
//     for(int i = 0; i < 20; i++) {
//         SDL_RenderClear(ren);
//         SDL_RenderCopy(ren, tex, nullptr, nullptr);
//         SDL_RenderPresent(ren);
//         SDL_Delay(100);
//     }
//
//     SDL_DestroyTexture(tex);
//     SDL_DestroyRenderer(ren);
//     SDL_DestroyWindow(win);
//     SDL_Quit();
//
//     return EXIT_SUCCESS;
// }
