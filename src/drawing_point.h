/** drawing_point.h
 * 
 */

#ifndef DRAWING_POINT_H
#define DRAWING_POINT_H

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

class PointDrawing: public Drawing
{

public:

    PointDrawing(MediaLayer_Drawing_Renderer* renderer, int x, int y, int r, int g, int b, int alpha);

    PointDrawing(MediaLayer_Drawing_Renderer* renderer, Drawing::Point coordinates, Drawing::Color color);

    ~PointDrawing();

    // Renders point to screen
    bool render() override;

    // Coordinates of the point
    Drawing::Point coordinates();

    // X-coordinate of the point
    int x();

    // Y-coordinate of the point
    int y();

    // Render color of the point
    Drawing::Color color();

private:

    Drawing::Point _point_coordinates;

    Drawing::Color _point_color;

};
#endif