/** drawing_ellipse_filled.cpp
 * Object for rendering ellipse
 */

#include "drawing_ellipse_filled.h"
#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

/** Constructor
 *    @renderer: Pointer to object handling screen output.
 *    @x, y: coordinates of the center of an ellipse
 *    @radiusX, @radiusY: horizontal and vertical radii, respectively
 *    @r, @g, @b, @alpha: color/alpha transparency of the ellipse line/shape
 */
    FilledEllipseDrawing::FilledEllipseDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
            int x, int y, 
            int radiusX, int radiusY, 
            int r, int g, int b, int alpha):
        EllipseDrawing(renderer, x, y, radiusX, radiusY, r, g, b, alpha)
    {
    }

/** Constructor
 *     @renderer: Pointer to object handling screen output.
 *     @center: coordinates of the center of an ellipse
 *     @radiusX, @radiusY: horizontal and vertical radii, respectively
 *     @a: color/alpha transparency of the ellipse line/shape
 */
    FilledEllipseDrawing::FilledEllipseDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
            Position center, 
            int radiusX, int radiusY,
            Color color):
        EllipseDrawing(renderer, center, radiusX, radiusY, color)
    {
    }

/** Destructor
 */
    FilledEllipseDrawing::~FilledEllipseDrawing()
    {
    }

/** public function: render()
 *  Renders ellipse to screen.
 */
    bool FilledEllipseDrawing::render(int x, int y, double rotation)
    {
        return _drawing_renderer->render_filled_ellipse(
                _center.x, _center.y,
                _radius_x, _radius_y,
                _color.r, _color.g, _color.b, _color.alpha);
    }

} // namespace Drawing
