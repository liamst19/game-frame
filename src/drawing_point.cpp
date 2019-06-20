/** drawing_point.cpp
 *  Class for rendering a single pixel to screen.
 */

#include "drawing_point.h"
#include "drawing_element.h"

#include "medialayer_drawing_renderer.h"

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @x, @y: Coordinates of point.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 */
PointDrawing::PointDrawing(MediaLayer_Drawing_Renderer* renderer,
    int x, int y, 
    int r, int g, int b, int alpha):
  DrawingElement(renderer, DrawingElement::Color{r, g, b, alpha}),                           
  _point_coordinates(DrawingElement::Position{x, y})
{
}

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @coordinates: Coordinates of point.
 *    @color: Color and alpha transparency values.
 */
PointDrawing::PointDrawing(MediaLayer_Drawing_Renderer* renderer,
    DrawingElement::Position coordinates,
    DrawingElement::Color color):
  DrawingElement(renderer, color),                           
  _point_coordinates(coordinates)
{
}                           

/** Destructor
 */
PointDrawing::~PointDrawing()
{
}

/** public function: render()
 *  Outputs pixel to screen.
 */
bool PointDrawing::render()
{
    // Call method for rendering point
    return _drawing_renderer->render_point(
                _point_coordinates.x, _point_coordinates.y, 
                _color.r, _color.g, _color.b, _color.alpha);
}

/** public function: coordinates()
 *  Coordinates of the pixel
 */
DrawingElement::Position PointDrawing::coordinates()
{
    return _point_coordinates;
}

/** public function: x()
 *  X-coordinate of the pixel
 */
int PointDrawing::x()
{
    return _point_coordinates.x;
}

/** public function: y()
 *  Y-coordinate of the pixel
 */
int PointDrawing::y()
{
    return _point_coordinates.y;
}