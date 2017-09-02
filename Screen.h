#ifndef PARTICLEEXPLOSION_SCREEN_H
#define PARTICLEEXPLOSION_SCREEN_H

#include <SDL.h>
#include <iostream>
using namespace std;

class Screen {
private:
    const int screenWidth;
    const int screenHeight;
    int result;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    SDL_Texture *pTexture;
    Uint32 *pBufferCurrent;
public:
    Screen(int screenWidth, int screenHeight);
    ~Screen();
    int setup();
    int close();
    bool handleEvents(SDL_Event *pEvent);
    void handleRendering();
    int getHeight();
    int getWidth();
    int getResult();
    void setBuffer(Uint32 *pBuffer);
    Uint32 *getBuffer();
    void setPixelColor(int xValue, int yValue, Uint32 value);
    void setPixelColor(int xValue, int yValue, Uint8 red, Uint8 blue, Uint8 green);
    void reset();
};


#endif //PARTICLEEXPLOSION_SCREEN_H
