/** drawing.h
 * Drawing object represents an image of a single object.
 * It should contain various simple drawing elements that make up the image.
 */

#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include "medialayer_drawing_renderer.h"

class Drawing{

public:

    // Represents Color and Alpha Transparency values.
    // Numbers should be within 0 to 255.
    struct Color
    {
        int r, g, b; // Red, green, blue
        int alpha;   // Alpha transparency
    };

    // Represents x and y-coordinates and color of a point.
    struct Point
    {
        int x, y;
    };

    // Constructor
    Drawing(MediaLayer_Drawing_Renderer* drawing_renderer,
        Color color);

    // Destructor
    ~Drawing();

    // --------------------------------------------------
    // Virtual Methods

    // Render drawing to screen 
    virtual bool render()=0;
 
    // --------------------------------------------------

    // Render color of the drawing
    Drawing::Color color();

 protected:

    // Pointer to object which handles screen output.
    MediaLayer_Drawing_Renderer* _drawing_renderer;

    Drawing::Color _color;

};

#endif