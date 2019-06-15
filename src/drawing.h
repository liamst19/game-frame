/** drawing.h
 * Drawing object represents an image of a single object.
 * It should contain various simple drawing elements that make up the image.
 * 
 */

#ifndef DRAWING_H
#define DRAWING_H

#include <vector>

class Drawing{

public:

    struct Color
    {
        int r;
        int g;
        int b;
        int alpha;
    };

    struct Point
    {
        int x;
        int y;
        Color color;
    };

    Drawing(){}

    ~Drawing();

    std::vector<Point> drawing();

    void draw_circle(int x, int y, int radius, Color color = Color{255, 255, 255, 0});
    
    void draw_line(int aX, int aY, int bX, int bY, Color color = Color{255, 255, 255, 0});

    void draw_point(int x, int y, Color color = Color{255, 255, 255, 0});

private:

    std::vector<Point> _drawing;

};

#endif