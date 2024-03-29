/** drawing_rectangle.cpp
 *  Class for rendering polygon to screen
 */

#include "drawing_polygon.h"

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 *    @fill: renders a solid shape if true, line if false
 */
    PolygonDrawing::PolygonDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
            int r, int g, int b, int alpha,
            bool fill):
        DrawingElement(renderer, DrawingElement::Color{r, g, b, alpha}),
        _fill_shape(fill)
    {
    }

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 *    @fill: renders a solid shape if true, line if false
 */
    PolygonDrawing::PolygonDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
            DrawingElement::Color color,
            bool fill):
        DrawingElement(renderer, color),
        _fill_shape(fill)
    {
    }

/** Destructor
 */
    PolygonDrawing::~PolygonDrawing()
    {
    }

/** Public function: render()
 *  Renders polygon to screen
 */
    bool PolygonDrawing::render()
    {
        return false;
//    return _drawing_renderer->render_polygon(
//                                _color.r, _color.g, _color.b, _color.alpha,
//                                _fill_shape);
    }

} // namespace Drawing
