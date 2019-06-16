/** drawing_point.cpp
 * 
 */

#include "drawing_point.h"
#include "drawing.h"

#include "medialayer_drawing_renderer.h"

PointDrawing::PointDrawing(MediaLayer_Drawing_Renderer* renderer,
                           int x, 
                           int y, 
                           int r,
                           int g,
                           int b, 
                           int alpha):
  Drawing(renderer),                           
  _point_coordinates(Drawing::Point{x, y}),
  _point_color(Drawing::Color{r, g, b, alpha})
{
}

PointDrawing::PointDrawing(MediaLayer_Drawing_Renderer* renderer,
                           Drawing::Point point_coordinates,
                           Drawing::Color point_color):
  Drawing(renderer),                           
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
    return _drawing_renderer->render_point(_point_coordinates.x,
                                           _point_coordinates.y, 
                                           _point_color.r, 
                                           _point_color.g, 
                                           _point_color.b, 
                                           _point_color.alpha);
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