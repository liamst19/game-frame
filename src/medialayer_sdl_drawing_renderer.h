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
    bool render_point(
            int x, int y, 
            int r, int g, int b, int alpha);

    // Render line
    bool render_line(
            int aX, int aY, 
            int bX, int bY, 
            int r, int g, int b, int alpha, 
            int thickness = 1);

    // Render rectangle
    bool render_rectangle(
            int x1, int y1, 
            int x2, int y2, 
            int r, int g, int b, int alpha, 
            bool fill = false);

    // Render circle
    bool render_circle(
            int centerX, int centerY, 
            int radius, 
            int r, int g, int b, int alpha, 
            bool fill = false);

    // Render ellipse
    bool render_ellipse(
            int aX, int aY, 
            int radiusX, int radiusY, 
            int r, int g, int b, int alpha, 
            bool fill = false);

private:

    SDL_Renderer* _renderer;
    SDL_Window* _window;

    // Free Resources
    void free();

    // Sets color and blendmode
    int _set_color(int r, int g, int b, int alpha);

    // For rendering ellipse
    int _ellipse_adjust_overscan(int rxi, int ryi);
    int _ellipse_draw_quadrants(int x, int y, int rX, int rY, bool fill = false);
    int _ellipse_draw_segment_1(
            int& error,
            int& deltaX, int& deltaY, 
            int& scrX, int& scrY,
            int& curX, int& curY, int& oldX, int& oldY,
            int x, int y,
            int rx2, int ry2, int rx22, int ry22,
            int ellipseOverscan,
            bool fill
    );
    int _ellipse_draw_segment_2(
            int& error,
            int& deltaX, int& deltaY, 
            int& scrX, int& scrY,
            int& curX, int& curY, int& oldX, int& oldY,
            int x, int y,
            int rx2, int ry2, int rx22, int ry22,
            int ellipseOverscan,
            bool fill
    );


};
#endif