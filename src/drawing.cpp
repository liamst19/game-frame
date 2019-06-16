/** drawing.cpp
 * 
 * 
 */
#include "drawing.h"

#include <vector>
#include "math.h"

#include "medialayer_drawing_renderer.h"

/** Constructor
 * 
 */
Drawing::Drawing(MediaLayer_Drawing_Renderer* renderer):
 _drawing_renderer(renderer)
{
}

/** Destructor
 * 
 */
Drawing::~Drawing()
{
    _drawing_renderer = nullptr;
}
