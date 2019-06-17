/** drawing_ellipse.h
 * 
 */

#ifndef DRAWING_ELLIPSE_H
#define DRAWING_ELLIPSE_H

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

class EllipseDrawing: public Drawing
{

public:

    EllipseDrawing(MediaLayer_Drawing_Renderer* renderer, 
                   int x, int y, 
                   int radiusX, int radiusY, 
                   int r, int g, int b, int alpha,
                   bool fill = false);

    EllipseDrawing(MediaLayer_Drawing_Renderer* renderer, 
                   Drawing::Point a, 
                   int radiusX, int radiusY,
                   Drawing::Color color,
                   bool fill = false);

    ~EllipseDrawing();

    // Renders line to screen
    bool render() override;

    Drawing::Point center();

    int radius_x();

    int radius_y();

    Drawing::Color color();

private:

    Drawing::Point _center;
    int _radius_x, _radius_y;
    Drawing::Color _color;
    bool _fill_shape;

};
#endif