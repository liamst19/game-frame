/** drawing_rectangle.h
 * 
 */

#ifndef DRAWING_RECTANGLE_H
#define DRAWING_RECTANGLE_H

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

class RectangleDrawing: public Drawing
{

public:

    RectangleDrawing(
        MediaLayer_Drawing_Renderer* renderer, 
        int aX, int aY, 
        int bX, int bY, 
        int r, int g, int b, int alpha,
        bool fill = false);

    RectangleDrawing(
        MediaLayer_Drawing_Renderer* renderer, 
        Drawing::Point a, Drawing::Point b, 
        Drawing::Color color,
        bool fill = false);

    ~RectangleDrawing();

    // Renders rectangle to screen
    bool render() override;

    Drawing::Point a();

    Drawing::Point b();

    Drawing::Color color();

private:

    Drawing::Point _point_a, _point_b;
    Drawing::Color _color;
    bool _fill_shape;

};
#endif