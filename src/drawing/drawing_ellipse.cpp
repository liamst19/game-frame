/** drawing_ellipse.cpp
 * Object for rendering ellipse
 */

#include "drawing_ellipse.h"

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

/** Constructor
 *    @renderer: Pointer to object handling screen output.
 *    @x, y: coordinates of the center of an ellipse
 *    @radiusX, @radiusY: horizontal and vertical radii, respectively
 *    @r, @g, @b, @alpha: color/alpha transparency of the ellipse line/shape
 */
    EllipseDrawing::EllipseDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
            int x, int y, 
            int radiusX, int radiusY, 
            int r, int g, int b, int alpha):
        DrawingElement(renderer, DrawingElement::Color{r, g, b, alpha}),
        _center(DrawingElement::Position{x, y}),
        _radius_x(radiusX), 
        _radius_y(radiusY){
    }

/** Constructor
 *     @renderer: Pointer to object handling screen output.
 *     @center: coordinates of the center of an ellipse
 *     @radiusX, @radiusY: horizontal and vertical radii, respectively
 *     @a: color/alpha transparency of the ellipse line/shape
 */
    EllipseDrawing::EllipseDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
            DrawingElement::Position center, 
            int radiusX, int radiusY,
            DrawingElement::Color color):
        DrawingElement(renderer, color),
        _center(center),
        _radius_x(radiusX), 
        _radius_y(radiusY){
    }

/** Destructor
 */
    EllipseDrawing::~EllipseDrawing()
    {
    }

/** public function: render()
 *  Renders ellipse to screen.
 */
    bool EllipseDrawing::render()
    {
        return _drawing_renderer->render_ellipse(
                _center.x, _center.y,
                _radius_x, _radius_y,
                _color.r, _color.g, _color.b, _color.alpha);
    }

/** public function: center
 *  Returns the coordinates of the center of the ellipse.
 */
    DrawingElement::Position EllipseDrawing::center()
    {
        return _center;
    }

/** public function: radius_x
 *  Returns the horizontal radius of the ellipse.
 */
    int EllipseDrawing::radius_x()
    {
        return _radius_x;
    }

/** public function: radius_y
 *  Returns the vertical radius of the ellipse.
 */
    int EllipseDrawing::radius_y()
    {
        return _radius_y;
    }

} // namespace Drawing
