/** drawing_element_points.h
 * 
 * 
 */

#ifndef DRAWING_ELEMENT_POINTS_H
#define DRAWING_ELEMENT_POINTS_H

#include <vector>

#include "math_vector_2d.h"
#include "drawing_element.h"

class Points: public DrawingElement{

public:

    Points(){}

    ~Points(){}

    void add_point(Vector2d point);

    std::vector<Vector2d> draw() override { return _points; }

private:

    std::vector<Vector2d> _points;

};

#endif