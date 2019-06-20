/** drawing_line.h
 *  Object for rendering line to screen.
 * 
 *  Currently this renders only a straight line of 1px thickness.
 * 
 *  Possibile future plans:
 *   - thickness
 *   - option for drawing curved line
 * 
 */

#ifndef DRAWING_LINE_H
#define DRAWING_LINE_H

#include "drawing_element.h"
#include "medialayer_drawing_renderer.h"

class LineDrawing: public DrawingElement
{

public:

    // Constructor
    LineDrawing(MediaLayer_Drawing_Renderer* renderer, 
        int aX, int aY, 
        int bX, int bY, 
        int r, int g, int b, int alpha);

    // Constructor
    LineDrawing(MediaLayer_Drawing_Renderer* renderer, 
        DrawingElement::Point a, 
        DrawingElement::Point b, 
        DrawingElement::Color color);

    // Destructor
    ~LineDrawing();

    // Renders line to screen
    bool render() override;

    // End point of line ab
    DrawingElement::Point a();

    // End point of line ab
    DrawingElement::Point b();

private:

    DrawingElement::Point _point_a, _point_b;

};
#endif