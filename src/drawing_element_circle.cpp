/** drawing_element_circle.cpp
 * 
 * 
 */

#include <vector>

#include "drawing_element_circle.h"
#include "math_vector_2d.h"

/** function: set_radius()
 * 
 */
void Circle::set_radius(float radius)
{ 
    _radius = radius; 
}

/** function: radius()
 * 
 */
float Circle::radius()
{ 
    return _radius; 
}

/** function: set_center()
 * 
 */
void Circle::set_center(Vector2d center)
{ 
    _center = center; 
}

/** function: get_points()
 * 
 */
Vector2d Circle::center()
{ 
    return _center; 
}

/** function: get_points()
 * 
 */
std::vector<Vector2d> Circle::draw()
{
    std::vector<Vector2d> circle;

    const int diameter = (static_cast<int>(_radius * 2));
    int x = static_cast<int>(_radius - 1);
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        circle.push_back(Vector2d(_center.x + x, _center.y - y));
        circle.push_back(Vector2d(_center.x + x, _center.y + y));
        circle.push_back(Vector2d(_center.x - x, _center.y - y));
        circle.push_back(Vector2d(_center.x - x, _center.y + y));
        circle.push_back(Vector2d(_center.x + y, _center.y - x));
        circle.push_back(Vector2d(_center.x + y, _center.y + x));
        circle.push_back(Vector2d(_center.x - y, _center.y - x));
        circle.push_back(Vector2d(_center.x - y, _center.y + x));

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }

    return circle;
}