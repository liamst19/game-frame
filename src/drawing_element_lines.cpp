/** drawing_element_lines.cpp
 * 
 * 
 */

#include <vector>

#include "math.h"
#include "math_vector_2d.h"

#include "drawing_element_lines.h"

/** function: add_line()
 * 
 */
void Lines::add_line(Vector2d a, Vector2d b){ 
    _lines.push_back(Line{a, b}); 
}

/** function: add_line()
 * 
 */
void Lines::add_line(Line line){ 
    _lines.push_back(line);
}

/** function: lines()
 * 
 */
std::vector<Lines::Line> Lines::lines()
{ 
    return _lines; 
}

/** function: draw() 
 * 
 */
std::vector<Vector2d> Lines::draw()
{
    std::vector<Vector2d> points;

    Vector2d point_a, point_b;
    float slope{0};

    // Draw each line
    for(Line line: _lines)
    {
        // Swap for iteration 
        if(line.a.x > line.b.x)
        {
            point_a = line.b;
            point_b = line.a;
        } else
        {
            point_a = line.a;
            point_b = line.b;
        }

        if (point_a.x == point_b.x && point_a.y != point_b.y)
        {
            // Vertical line
            for(int y = point_a.yInt(); y < point_b.yInt(); y++)
            {
                points.push_back(Vector2d{static_cast<float>(point_a.x), static_cast<float>(y)});
            }
        } else if (point_a.x != point_b.x)
        {
            // Calculate slope
            slope = Math::Slope(point_a.x, point_a.y, point_b.x, point_b.y); 

            // Get points calculated from slope
            for(int x = point_a.xInt(); x < point_b.xInt(); x++)
            {
                points.push_back(Vector2d{static_cast<float>(x), Math::LinearY(slope, x, point_a.y)});
            }
        }

    }

    return points;
}
