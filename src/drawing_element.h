/** drawing_element.h
 * 
 * 
 */

#ifndef DRAWING_ELEMENT_H
#define DRAWING_ELEMENT_H

#include <vector>

#include "math_vector_2d.h"

class DrawingElement{

public:

    DrawingElement(){}

    virtual ~DrawingElement(){}

    virtual std::vector<Vector2d> draw();

    int color_red();

    int color_green();

    int color_blue();

    int color_alpha();

    void set_color(int red, int green, int blue, int alpha = 0);

protected:

    int _color_red{255}, 
        _color_green{255}, 
        _color_blue{255}, 
        _color_alpha{0};

};

#endif