/** drawing_element_lines.cpp
 * 
 * 
 */

#include <vector>

#include "math.h"
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
    int y{0};
    float slope{0};
    for(Line line: _lines){

        if(line.a.x <= line.b.x){
            point_a = line.a;
            point_b = line.b;
        } else{
            point_a = line.b;
            point_b = line.b;
        }

        // Get slope
        if (point_a.x == point_b.x && point_a.y == point_b.y){
            // Single point -- not a line
        } else if(point_a.x == point_b.x){
            // Vertical line
            for(int y = static_cast<int>(point_a.y); y < static_cast<int>(point_b.y); y++){
                points.push_back(Vector2d{static_cast<float>(point_a.x), static_cast<float>(y)});
            }
        } else{
            // Calculate slope
            slope = (point_b.y - point_a.y) / (point_b.x - point_a.x);

            // Get points calculated from slope
            for(int x = static_cast<int>(point_a.x); x < static_cast<int>(point_b.x); x++){
                y =  slope * x + point_a.y; // y = mx + b
                points.push_back(Vector2d{static_cast<float>(x), static_cast<float>(y)});
            }
        }

    }

    return points;
}
