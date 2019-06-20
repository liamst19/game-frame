/** drawing_rectangle.h
 *  Class for rendering rectangle to screen.
 * 
 *  Possible future plans:
 *   - Line thickness
 *   - Rounded corners
 * 
 */

#ifndef DRAWING_RECTANGLE_H
#define DRAWING_RECTANGLE_H

#include "drawing_element.h"
#include "medialayer_drawing_renderer.h"

class RectangleDrawing: public DrawingElement
{

public:

    // Constructor
    RectangleDrawing(
        MediaLayer_Drawing_Renderer* renderer, 
        int aX, int aY, 
        int bX, int bY, 
        int r, int g, int b, int alpha,
        bool fill = false);

    // Constructor
    RectangleDrawing(
        MediaLayer_Drawing_Renderer* renderer, 
        DrawingElement::Point a, DrawingElement::Point b, 
        DrawingElement::Color color,
        bool fill = false);

    // Destructor
    ~RectangleDrawing();

    // Renders rectangle to screen
    bool render() override;

    // Vertice
    DrawingElement::Point a();

    // Vertice
    DrawingElement::Point b();

private:

    DrawingElement::Point _point_a, _point_b;
    bool _fill_shape;

};
#endif