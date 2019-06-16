/** drawing.h
 * Drawing object represents an image of a single object.
 * It should contain various simple drawing elements that make up the image.
 * 
 */

#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include "medialayer_drawing_renderer.h"

class Drawing{

public:

    struct Color
    {
        int r;
        int g;
        int b;
        int alpha;
    };

    struct Point
    {
        int x;
        int y;
        Color color;
    };

    Drawing(MediaLayer_Drawing_Renderer* drawing_renderer);

    ~Drawing();

    // --------------------------------------------------
    // Virtual Methods

    // Render drawing to screen 
    virtual bool render() =0;
 
// --------------------------------------------------

 protected:

    // To be implemented
    MediaLayer_Drawing_Renderer* _drawing_renderer;

};

#endif