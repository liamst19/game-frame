/** medialayer_drawing.h
 *
 */
#ifndef MEDIALAYER_DRAWING_H
#define MEDIALAYER_DRAWING_H

class MediaLayer_Drawing
{

public:

    MediaLayer_Drawing(){}

    virtual ~MediaLayer_Drawing(){}

    // Render point
    bool render_point(int x, int y, int r, int g, int b, int alpha)=0;

    // Render line
    bool render_line(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, int thickness =1)=0;

    // Render rectangle outline
    bool render_rectangle(int aX, int aY, int w, int h, int r, int g, int b, int alpha, bool fill = false)=0;

    // Render circle
    bool render_circle(int centerX, int centerY, int radius, int r, int g, int b, int alpha, bool fill = false)=0;

    // Render ellipse
    bool render_ellipse(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, bool fill = false)=0;

};
#endif