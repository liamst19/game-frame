/** medialayer_drawing_renderer.h
 *
 */
#ifndef MEDIALAYER_DRAWING_RENDERER_H
#define MEDIALAYER_DRAWING_RENDERER_H

class MediaLayer_Drawing_Renderer
{

public:

    MediaLayer_Drawing_Renderer(){}

    virtual ~MediaLayer_Drawing_Renderer(){}

    // Render point
    virtual bool render_point(
            int x, int y, 
            int r, int g, int b, int alpha)=0;

    // Render line
    virtual bool render_line(
            int aX, int aY, 
            int bX, int bY, 
            int r, int g, int b, int alpha, 
            int thickness =1)=0;

    // Render rectangle outline
    virtual bool render_rectangle(
            int aX, int aY, 
            int bX, int bY, 
            int r, int g, int b, int alpha, 
            bool fill = false)=0;

    // Render circle
    virtual bool render_circle(
            int centerX, int centerY, 
            int radius, 
            int r, int g, int b, int alpha,
            bool fill = false)=0;

    // Render ellipse
    virtual bool render_ellipse(
            int aX, int aY, 
            int radiusX, int radiusY, 
            int r, int g, int b, int alpha, 
            bool fill = false)=0;

};
#endif