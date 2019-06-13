/** drawing_element_circle.h
 * 
 * 
 */

#ifndef DRAWING_ELEMENT_CIRCLE_H
#define DRAWING_ELEMENT_CIRCLE_H

#include <vector>

#include "math_vector_2d.h"
#include "drawing_element.h"

class Circle: public DrawingElement{

public:

    Circle(){}

    Circle(Vector2d center, float radius):
            _center{center},
            _radius{radius}{}

    ~Circle(){}

    // Set the radius of circle
    void set_radius(float radius);

    // Get the radius of circle
    float radius();

    // Set the center coordinates of circle
    void set_center(Vector2d center);

    // Get the center coordinates of circle
    Vector2d center();

    // Draw circle as collection of Vector2d coordinates
    std::vector<Vector2d> draw() override;

private:

    float _radius;

    Vector2d _center;

};

#endif