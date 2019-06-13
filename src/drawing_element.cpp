/** drawing_element.cpp
 * 
 * 
 */

#include "drawing_element.h"

std::vector<Vector2d> DrawingElement::draw()
{ 
    return std::vector<Vector2d>{};
}

int DrawingElement::color_red()
{ 
    return _color_red; 
}

int DrawingElement::color_green()
{ 
    return _color_green; 
}

int DrawingElement::color_blue()
{ 
    return _color_blue; 
}

int DrawingElement::color_alpha()
{ 
    return _color_alpha; 
}

void DrawingElement::set_color(int red, int green, int blue, int alpha)
{
    _color_red = red;
    _color_green = green;
    _color_blue = blue;
    _color_alpha = alpha;
}

