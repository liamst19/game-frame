/** drawing_ellipse.h
 *  Class for rendering ellipse to screen
 * 
 *  Possible future plans:
 *   - Line thickness
 *   - Non-axis-aligned ellipses
 * 
 */

#ifndef DRAWING_ELLIPSE_H
#define DRAWING_ELLIPSE_H

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

class EllipseDrawing: public DrawingElement
{

public:

    // Constructor
    EllipseDrawing(MediaLayer::Drawing_Renderer* renderer, 
                   int x, int y, 
                   int radiusX, int radiusY, 
                   int r, int g, int b, int alpha);

    // Constructor
    EllipseDrawing(MediaLayer::Drawing_Renderer* renderer, 
                   DrawingElement::Position a, 
                   int radiusX, int radiusY,
                   DrawingElement::Color color);

    // Destructor
    ~EllipseDrawing();

    // Renders line to screen
    bool render() override;

    // Center of ellipse
    DrawingElement::Position center();

    // Horizontal radius
    int radius_x();

    // Vertical radius
    int radius_y();

protected:

    DrawingElement::Position _center; // _focus_a, _focus_b;

    int _radius_x, _radius_y;

};
#endif
