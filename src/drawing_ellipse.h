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
#include "medialayer_drawing_renderer.h"

class EllipseDrawing: public DrawingElement
{

public:

    // Constructor
    EllipseDrawing(MediaLayer_Drawing_Renderer* renderer, 
                   int x, int y, 
                   int radiusX, int radiusY, 
                   int r, int g, int b, int alpha,
                   bool fill = false);

    // Constructor
    EllipseDrawing(MediaLayer_Drawing_Renderer* renderer, 
                   DrawingElement::Position a, 
                   int radiusX, int radiusY,
                   DrawingElement::Color color,
                   bool fill = false);

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

private:

    DrawingElement::Position _center; // _focus_a, _focus_b;

    int _radius_x, _radius_y;

    // Renders solid shape if true, outline if false 
    bool _fill_shape;

};
#endif