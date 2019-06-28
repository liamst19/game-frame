/** drawing_point.cpp
 *  Class for rendering a single pixel to screen.
 */

#include "drawing_point.h"
#include "drawing_element.h"

#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @x, @y: Coordinates of point.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 */
    PointDrawing::PointDrawing(MediaLayer::Drawing_Renderer* renderer,
                               int x, int y, 
                               int r, int g, int b, int alpha):
        DrawingElement(renderer, Color{r, g, b, alpha}),                           
        _point_coordinates(Position{x, y})
    {
    }

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @coordinates: Coordinates of point.
 *    @color: Color and alpha transparency values.
 */
    PointDrawing::PointDrawing(MediaLayer::Drawing_Renderer* renderer,
                               Position coordinates,
                               Color color):
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
    Position PointDrawing::coordinates()
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

    /** public function: width()
     * Width of the element
     */
    int  PointDrawing::width()
    {
        return 0;
    }

    /** public function: height()
     * Height of the element
     */
    int  PointDrawing::height()
    {
        return 0;
    }

    /** public function: center()
     * Position of the center of element
     */
    Position PointDrawing::center()
    {
        return _point_coordinates;
    }

} // namespace Drawing
