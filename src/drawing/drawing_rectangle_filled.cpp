/** drawing_rectangle.cpp
 *  Class for rendering rectangle to screen.
 */

#include "drawing_rectangle_filled.h"
#include "drawing_rectangle.h"
#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @aX, @aY, @bX, @bY: Coordinates of the opposing vertices.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 */
FilledRectangleDrawing::FilledRectangleDrawing(
        MediaLayer::Drawing_Renderer* renderer, 
        int aX, int aY, 
        int bX, int bY, 
        int r, int g, int b, int alpha):
    RectangleDrawing(renderer, aX, aY, bX, bY, r, g, b, alpha){
}

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @a, @b: Coordinates of the endpoints.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 */
FilledRectangleDrawing::FilledRectangleDrawing(
        MediaLayer::Drawing_Renderer* renderer, 
        DrawingElement::Position a, 
        DrawingElement::Position b, 
        DrawingElement::Color color):
    RectangleDrawing(renderer, a, b, color)
{
}

/** Destructor
 */
FilledRectangleDrawing::~FilledRectangleDrawing()
{
}

/** Public function: render()
 *  Renders rectangle to screen
 */
bool FilledRectangleDrawing::render()
{
    // Render rectangle
    return _drawing_renderer->render_filled_rectangle(
            _point_a.x, _point_a.y,
            _point_b.x, _point_b.y,
            _color.r, _color.g, _color.b, _color.alpha);
}

