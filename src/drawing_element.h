/** drawing_element.h
 * Drawing object represents an image of a single object.
 * It should contain various simple drawing elements that make up the image.
 */

#ifndef DRAWING_ELEMENT_H
#define DRAWING_ELEMENT_H

#include <vector>
#include "medialayer_drawing_renderer.h"

class DrawingElement{

public:

    // Represents Color and Alpha Transparency values.
    // Numbers should be within 0 to 255.
    struct Color
    {
        int r, g, b; // Red, green, blue
        int alpha;   // Alpha transparency
    };

    // Represents x and y-coordinates and color of a point.
    struct Position
    {
        int x, y;
    };

    // Constructor
    DrawingElement(MediaLayer::Drawing_Renderer* drawing_renderer,
        Color color);

    // Destructor
    ~DrawingElement();

    // --------------------------------------------------
    // Virtual Methods

    // Render drawing to screen 
    virtual bool render()=0;
 
    // --------------------------------------------------

    // Render color of the drawing
    DrawingElement::Color color();

 protected:

    // Pointer to object which handles screen output.
    MediaLayer::Drawing_Renderer* _drawing_renderer;

    DrawingElement::Color _color;

};

#endif
