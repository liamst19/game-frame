/** drawing_element.cpp
 *  Abstract class for rendering points, shapes, 
 *  and lines to screen.
 */
#include "drawing_element.h"

#include <vector>
#include "math.h"

#include "medialayer_drawing_renderer.h"

/** Constructor
 *    @renderer: Pointer to object handling screen output.
 */
DrawingElement::DrawingElement(MediaLayer::Drawing_Renderer* renderer,
    DrawingElement::Color color):
 _drawing_renderer(renderer),
 _color(color)
{
}

/** Destructor
 */
DrawingElement::~DrawingElement()
{
    _drawing_renderer = nullptr;
}

/** public function: color()
 *  Color and alpha transparency values of the drawing. 
 */
DrawingElement::Color DrawingElement::color()
{
    return _color;
}
