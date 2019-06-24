/** drawing_factory.h
 * 
 *  Collection of methods that return Drawing objects for
 *  rendering to screen.
 *  
 */

#include "drawing_factory.h"

/** Constructor
 *  @renderer: Pointer to an renderer object, which handles screen output.
 */
DrawingFactory::DrawingFactory(MediaLayer::Drawing_Renderer* renderer):
_drawing_renderer(renderer)
{
}

/** Destructor
 */
DrawingFactory::~DrawingFactory()
{
}

/** public function: getPoint()
 *  Creates object for rendering single pixel.
 *    @x, @y: Coordinates of the point.
 *    @r, @g, @b, @alpha: Color and transparency values.
 */
PointDrawing DrawingFactory::getPoint(
                int x, int y, 
                int r, int g, int b, int alpha)
{
    return PointDrawing{_drawing_renderer, x, y, r, g, b, alpha};
}

/** public function: getLine()
 *  Creates object for rendering a line.
 *    @aX, @aY, @bX, @bY: Coordinates of the endpoints.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 */
LineDrawing DrawingFactory::getLine(
                int aX, int aY, 
                int bX, int bY, 
                int r, int g, int b, int alpha)
{
    return LineDrawing{_drawing_renderer, aX, aY, bX, bY, r, g, b, alpha};
}

/** public function: getRectangle()
 *  Creates object for rendering a rectangle.
 *    @aX, @aY, @bX, @bY: Coordinates of the two opposing vertices. 
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 *    @fill: Renders a solid shape if true, outline if false.   
 */
RectangleDrawing DrawingFactory::getRectangle(
                int aX, int aY, 
                int bX, int bY, 
                int r, int g, int b, int alpha,
                bool fill)
{
    return RectangleDrawing{_drawing_renderer, aX, aY, bX, bY, r, g, b, alpha, fill};
}

/** public function: getEllipse()
 *  Creates object for rendering an ellipse.
 *    @x, @y: Coordinates of the center.
 *    @radiusX, @radiusY: Horizontal and vertical radii, respectively.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 *    @fill: Renders a solid shape if true, outline if false.   
 */
EllipseDrawing DrawingFactory::getEllipse(
                int x, int y, 
                int radiusX, int radiusY, 
                int r, int g, int b, int alpha,
                bool fill)
{
    return EllipseDrawing{_drawing_renderer, x, y, radiusX, radiusY, r, g, b, alpha, fill};
}

/** public function: getCircle()
 *  Creates object for rendering a circle.
 *    @x, @y: Coordinates of the center.
 *    @radius: Radius of the circle.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 *    @fill: Renders a solid shape if true, outline if false.   
 */
EllipseDrawing DrawingFactory::getCircle(
                int x, int y, 
                int radius, 
                int r, int g, int b, int alpha,
                bool fill)
{
    return EllipseDrawing{_drawing_renderer, x, y, radius, radius, r, g, b, alpha, fill};
}

