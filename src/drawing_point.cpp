/** drawing_point.cpp
 * 
 */

#include "drawing_point.h"
#include "drawing.h"

PointDrawing::PointDrawing(int x, 
                           int y, 
                           int r,
                           int g,
                           int b, 
                           int alpha):
_point_coordinates(Drawing::Point{x, y}),
_point_color(Drawing::Color{r, g, b, alpha})
{
}

PointDrawing::PointDrawing(Drawing::Point point_coordinates,
                           Drawing::Color point_color):
_point_coordinates(point_coordinates),
_point_color(point_color)
{
}                           

PointDrawing::~PointDrawing()
{
}

bool PointDrawing::render()
{
    // Call method for rendering point
    // _medialayer_drawing->render_point(x, y, r, g, b, a);
    return true;
}

Drawing::Point PointDrawing::coordinates()
{
    return _point_coordinates;
}

int PointDrawing::x()
{
    return _point_coordinates.x;
}

int PointDrawing::y()
{
    return _point_coordinates.y;
}

Drawing::Color PointDrawing::color()
{
    return _point_color;
}