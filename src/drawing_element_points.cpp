/** drawing_element_points.cpp
 * 
 * 
 */

#include <vector>
#include "math_vector_2d.h"

#include "drawing_element_points.h"


/** function: add_point
 * 
 */
void Points::add_point(Vector2d point)
{
     _points.push_back(point); 
}

/** function: draw()
 * 
 */
std::vector<Vector2d> Points::draw()
{ 
    return _points; 
}