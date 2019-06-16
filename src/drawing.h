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

    Drawing();

    ~Drawing();

    // --------------------------------------------------
    // Virtual Methods

    // Render drawing to screen 
    virtual bool render() =0;


// --------------------------------------------------
// TO BE REMOVED
    std::vector<Point> drawing();
    void draw_circle(int x, int y, int radius, Color color = Color{255, 255, 255, 0});
    void draw_line(int aX, int aY, int bX, int bY, Color color = Color{255, 255, 255, 0});
    void draw_point(int x, int y, Color color = Color{255, 255, 255, 0});
// --------------------------------------------------
 
// --------------------------------------------------

 private:

    // To be implemented
    // MediaLayer_Drawing* _medialayer_drawing;

// --------------------------------------------------
// TO BE REMOVED
   std::vector<Point> _drawing;
// --------------------------------------------------

};

#endif