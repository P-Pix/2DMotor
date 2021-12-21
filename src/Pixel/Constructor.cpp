#include "../../include/Pixel.hpp"

Pixel::Pixel(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->setR(r);
    this->setG(g);
    this->setB(b);
    this->setA(a);
    this->updateColor();
    this->createRect(x, y, w, h);
    this->createTexture();
    this->linkColorAndTexture();
    this->linkRectAndTexture();
}

Pixel::~Pixel() {
    delete this->m_rect;
}

void Pixel::createRect(int x, int y, int w, int h) {
    this->m_rect = new SDL_Rect{x, y, w, h};
}

void Pixel::createTexture() {
    this->m_texture = SDL_CreateTexture(this->m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
                                        this->m_rect->w, this->m_rect->h);
}

void Pixel::linkColorAndTexture(void) {
    SDL_SetTextureBlendMode(this->m_texture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureColorMod(this->m_texture, this->m_color.r, this->m_color.g, this->m_color.b);
    SDL_SetTextureAlphaMod(this->m_texture, this->m_color.a);
}

void Pixel::linkRectAndTexture(void) {
    SDL_SetRenderTarget(this->m_renderer, this->m_texture);
    SDL_RenderCopy(this->m_renderer, this->m_texture, NULL, this->m_rect);
    SDL_SetRenderTarget(this->m_renderer, NULL);
}