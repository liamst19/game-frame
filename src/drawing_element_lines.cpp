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

/** function: draw() 
 * 
 */
std::vector<Vector2d> Lines::draw(){
    std::vector<Vector2d> points;

    // Draw each line
    Vector2d point_a, point_b;
    float y{0};
    float slope{0};
    for(Line line: _lines){

        if(line.a.x <= line.b.x){
            point_a = line.a;
            point_b = line.b;
        } else{
            point_a = line.b;
            point_b = line.a;
        }

        if (point_a.x == point_b.x && point_a.y == point_b.y){
            // Single point -- not a line
        } else if(point_a.x == point_b.x){
            // Vertical line
            for(int y = point_a.yInt(); y < point_b.yInt(); y++){
                points.push_back(Vector2d{point_a.x, y});
            }
        } else{

            // Calculate slope
            slope = Math::GetSlope(point_a.x, point_a.y, point_b.x, point_b.y); 

            // Get points calculated from slope
            for(int x = spoint_a.xInt(); x < point_b.xInt(); x++){
                points.push_back(Vector2d{x, Math::GetLinearY(slope, x, point_a.y)});
            }
        }

    }

    return points;
}
