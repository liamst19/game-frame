/** drawing.cpp
 * 
 * 
 */
#include "drawing.h"

#include <vector>
#include "math.h"

/** Destructor
 * 
 */
Drawing::~Drawing()
{
    // Free all pointer resource in _elements
    // for(auto element: _element_ptrs)
    // {
        // delete element;
    // }
    // _elements.clear();
}

std::vector<Drawing::Point> Drawing::drawing()
{
    return _drawing;
}

void Drawing::draw_point(int x, int y, Color color)
{
    _drawing.push_back(Drawing::Point{x, y, color});
}

void Drawing::draw_line(int aX, int aY, int bX, int bY, Color color)
{

    if (aX == bX && aY != bY)
    {
        int y1 = aY, y2 = bY;
        int x = aX;
        if(y1 > y2)
        {
            y1 = bY;
            y2 = aY;
            x = bX;
        }
        // Vertical line
        for(int y = y1; y < y2; y++)
        {
            draw_point(x, y, color);
        }
    } else if (aX != bX)
    {
        int x1 = aX, x2 = bX;
        int y = aY;
       // Calculate slope
        float slope = Math::Slope(aX, aY, bX, bY); 

        if(x1 > x2)
        {
            x1 = bX;
            x2 = aX;
            y = bY;
            slope *= -1;
        }
 
        // Get points calculated from slope
        for(int x = x1; x < x2; x++)
        {
            draw_point(x, static_cast<int>(Math::LinearY(slope, x, y)), color);
        }
    }
}

void Drawing::draw_circle(int center_x, int center_y, int radius, Color color)
{
    const int diameter = radius * 2;
    int x = radius - 1;
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        draw_point(center_x + x, center_y - y, color);
        draw_point(center_x + x, center_y + y, color);
        draw_point(center_x - x, center_y - y, color);
        draw_point(center_x - x, center_y + y, color);
        draw_point(center_x + y, center_y - x, color);
        draw_point(center_x + y, center_y + x, color);
        draw_point(center_x - y, center_y - x, color);
        draw_point(center_x - y, center_y + x, color);

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
}