/** drawing_ellipse.cpp
 * 
 */

#include "drawing_ellipse.h"

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

EllipseDrawing::EllipseDrawing(
                MediaLayer_Drawing_Renderer* renderer, 
                int x, int y, 
                int radiusX, int radiusY, 
                int r, int g, int b, int alpha,
                bool fill):
  Drawing(renderer),
  _center(Drawing::Point{x, y}),
  _radius_x(radiusX), 
  _radius_y(radiusY),
  _color(Drawing::Color{r, g, b, alpha}),
  _fill_shape(fill)
{
}

EllipseDrawing::EllipseDrawing(
                MediaLayer_Drawing_Renderer* renderer, 
                Drawing::Point center, 
                int radiusX, int radiusY,
                Drawing::Color color,
                bool fill):
  Drawing(renderer),
  _center(center),
  _radius_x(radiusX), 
  _radius_y(radiusY),
  _color(color),
  _fill_shape(fill)
{
}

EllipseDrawing::~EllipseDrawing()
{
}

// Renders ellipse to screen
bool EllipseDrawing::render()
{
    return _drawing_renderer->render_ellipse(
                _center.x, _center.y,
                _radius_x, _radius_y,
                _color.r, _color.g, _color.b, _color.alpha,
                _fill_shape);
}

Drawing::Point EllipseDrawing::center()
{
    return _center;
}

int EllipseDrawing::radius_x()
{
    return _radius_x;
}

int EllipseDrawing::radius_y()
{
    return _radius_y;
}

Drawing::Color EllipseDrawing::color()
{
    return _color;
}
