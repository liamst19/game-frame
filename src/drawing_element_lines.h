/** drawing_element_lines.h
 * 
 * 
 */

#ifndef DRAWING_ELEMENT_LINES_H
#define DRAWING_ELEMENT_LINES_H

#include <vector>

#include "math.h"
#include "drawing_element.h"

class Lines: public DrawingElement{

public:

    struct Line{
        Vector2d a;
        Vector2d b;
    };

    Lines(){}

    ~Lines(){}

    // Add Line from point a to b
    void add_line(Vector2d a, Vector2d b);

    // Add Line
    void add_line(Line line);

    // Get Lines
    std::vector<Line> lines(){ return _lines; }

    std::vector<Vector2d> draw() override;

private:

    std::vector<Line> _lines;

};

#endif