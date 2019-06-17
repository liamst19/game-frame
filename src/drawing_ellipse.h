/** drawing_ellipse.h
 *  Class for rendering ellipse to screen
 */

#ifndef DRAWING_ELLIPSE_H
#define DRAWING_ELLIPSE_H

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

class EllipseDrawing: public Drawing
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
                   Drawing::Point a, 
                   int radiusX, int radiusY,
                   Drawing::Color color,
                   bool fill = false);

    // Destructor
    ~EllipseDrawing();

    // Renders line to screen
    bool render() override;

    // Center of ellipse
    Drawing::Point center();

    // Horizontal radius
    int radius_x();

    // Vertical radius
    int radius_y();

private:

    Drawing::Point _center;

    int _radius_x, _radius_y;

    // Renders solid shape if true, outline if false 
    bool _fill_shape;

};
#endif