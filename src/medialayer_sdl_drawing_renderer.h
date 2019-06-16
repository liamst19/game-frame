/** medialayer_sdl_drawing_renderer.h
 *
 * 
 */
#ifndef MEDIALAYER_SDL_DRAWING_RENDERER_H
#define MEDIALAYER_SDL_DRAWING_RENDERER_H

#include <SDL2/SDL.h>
#include "medialayer_drawing_renderer.h"

class MediaLayer_SDL_Drawing_Renderer: public MediaLayer_Drawing_Renderer
{

public:

    MediaLayer_SDL_Drawing_Renderer();

    ~MediaLayer_SDL_Drawing_Renderer();

    bool initialize(SDL_Renderer* renderer, SDL_Window* window);

    // Render point
    bool render_point(int x, int y, int r, int g, int b, int alpha);

    // Render line
    bool render_line(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, int thickness = 1);

    // Render rectangle outline
    bool render_rectangle(int aX, int aY, int w, int h, int r, int g, int b, int alpha, bool fill = false);

    // Render circle
    bool render_circle(int centerX, int centerY, int radius, int r, int g, int b, int alpha, bool fill = false);

    // Render ellipse
    bool render_ellipse(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, bool fill = false);

private:

    SDL_Renderer* _renderer;
    SDL_Window* _window;

    // Free Resources
    void free();

};
#endif