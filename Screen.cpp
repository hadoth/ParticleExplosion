#include "Screen.h"

Screen::Screen(int screenWidth, int screenHeight):
        screenWidth(screenWidth),
        screenHeight(screenHeight) {
    this->result = 0;
}

Screen::~Screen() {}

int Screen::setup() {
    cout << "Initializing SDL environment..." << endl;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << " SDL environment initialization error!" << endl;
        cout << SDL_GetError() << endl;
        result = 1;
        this->close();
        return result;
    }

    cout << "SDL environment successfully initialized." << endl;
    cout << "Initializing SDL window..." << endl;

    this->pWindow = SDL_CreateWindow(
            "ParticleExplosion",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            screenWidth,
            screenHeight,
            SDL_WINDOW_SHOWN
    );

    if (pWindow == NULL) {
        cout << " SDL window initialization error!" << endl;
        cout << SDL_GetError() << endl;
        result = 2;
        this->close();
        return result;
    }

    cout << "SDL window successfully initialized." << endl;
    cout << "Initializing SDL renderer..." << endl;

    this->pRenderer = SDL_CreateRenderer(
            pWindow,
            -1,
            SDL_RENDERER_PRESENTVSYNC
    );

    if (pRenderer == NULL) {
        cout << " SDL renderer initialization error!" << endl;
        cout << SDL_GetError() << endl;
        result = 3;
        this->close();
        return result;
    }

    cout << "SDL renderer successfully initialized." << endl;
    cout << "Initializing SDL texture..." << endl;

    this->pTexture = SDL_CreateTexture(
            pRenderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_STATIC,
            this->screenWidth,
            this->screenHeight
    );

    if (pTexture == NULL) {
        cout << " SDL texture initialization error!" << endl;
        cout << SDL_GetError() << endl;
        result = 4;
        this->close();
        return result;
    }

    cout << "SDL texture successfully initialized." << endl;
    cout << "Initializing data buffer..." << endl;

    this->pBufferCurrent = new Uint32[this->getWidth() * this->getHeight()];
    memset(this->pBufferCurrent, 0x00, this->getWidth() * this->getHeight() * sizeof(Uint32));

    cout << "Data buffer successfully initialized." << endl;

    return result;
}

int Screen::close() {
    if (this->result < 4) {
        SDL_DestroyTexture(pTexture);
    }
    if (this->result < 3) {
        SDL_DestroyRenderer(pRenderer);
    }
    if (this->result < 2) {
        SDL_DestroyWindow(pWindow);
    }
    if (this ->result < 1) {
        delete[] this->pBufferCurrent;
        SDL_Quit();
        cout << "Program initialized and run without errors" << endl;
    }
    cout << "Program will end" << endl;

    return this->result;
}

bool Screen::handleEvents(SDL_Event *pEvent) {
    while (SDL_PollEvent(pEvent)) {
        if (pEvent->type == SDL_QUIT) {
            return false;
        }
    }
    return true;
};

void Screen::handleRendering() {
    SDL_UpdateTexture(
            this->pTexture,
            NULL,
            this->pBufferCurrent,
            this->getWidth() * sizeof(Uint32)
    );
    SDL_RenderClear(
            this->pRenderer
    );
    SDL_RenderCopy(
            this->pRenderer,
            this->pTexture,
            NULL,
            NULL
    );
    SDL_RenderPresent(
            this->pRenderer
    );
}

int Screen::getHeight() {
    return this->screenHeight;
};

int Screen::getWidth() {
    return this->screenWidth;
};

int Screen::getResult() {
    return this->result;
}

Uint32 *Screen::getBuffer() {
    Uint32* result = new Uint32[this->screenWidth * this->screenHeight];
    memcpy(result, this->pBufferCurrent, this->screenWidth * this-> screenHeight * sizeof(Uint32));
    return result;
}

void Screen::setBuffer(Uint32 *pBuffer) {
    memcpy(this->pBufferCurrent, pBuffer, this->screenWidth * this-> screenHeight * sizeof(Uint32));
}

void Screen::setPixelColor(int xValue, int yValue, Uint8 red, Uint8 blue, Uint8 green) {
    if (xValue < 0 || xValue >= this->screenWidth || yValue < 0 || yValue >= this->screenHeight){
        return;
    }
    int pixelIndex = yValue * screenWidth + xValue;
    Uint32 pixelValue = red << 8;
    pixelValue += green;
    pixelValue <<= 8;
    pixelValue += blue;
    pixelValue <<= 8;
    pixelValue += 0xFF;
    this->pBufferCurrent[pixelIndex] = pixelValue;
}

void Screen::setPixelColor(int xValue, int yValue, Uint32 value) {
    if (xValue < 0 || xValue >= this->screenWidth || yValue < 0 || yValue >= this->screenHeight){
        return;
    }
    int pixelIndex = yValue * screenWidth + xValue;
    this->pBufferCurrent[pixelIndex] = value;
}

void Screen::reset() {
    memset(this->pBufferCurrent, 0x00, this->getWidth() * this->getHeight() * sizeof(Uint32));
}

