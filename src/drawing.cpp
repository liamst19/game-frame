/** drawing.cpp
 *  Abstract class for rendering points, shapes, 
 *  and lines to screen.
 */
#include "drawing.h"

#include <vector>
#include "math.h"

#include "medialayer_drawing_renderer.h"

/** Constructor
 *    @renderer: Pointer to object handling screen output.
 */
Drawing::Drawing(MediaLayer_Drawing_Renderer* renderer,
    Drawing::Color color):
 _drawing_renderer(renderer),
 _color(color)
{
}

/** Destructor
 */
Drawing::~Drawing()
{
    _drawing_renderer = nullptr;
}

/** public function: color()
 *  Color and alpha transparency values of the drawing. 
 */
Drawing::Color Drawing::color()
{
    return _color;
}