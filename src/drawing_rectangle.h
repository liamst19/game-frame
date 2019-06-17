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

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

class RectangleDrawing: public Drawing
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
        Drawing::Point a, Drawing::Point b, 
        Drawing::Color color,
        bool fill = false);

    // Destructor
    ~RectangleDrawing();

    // Renders rectangle to screen
    bool render() override;

    // Vertice
    Drawing::Point a();

    // Vertice
    Drawing::Point b();

private:

    Drawing::Point _point_a, _point_b;
    bool _fill_shape;

};
#endif