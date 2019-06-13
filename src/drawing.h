/** drawing.h
 * Drawing object represents an image of a single object.
 * It should contain various simple drawing elements that make up the image.
 * 
 */

#ifndef DRAWING_H
#define DRAWING_H

#include <vector>

#include "math.h"
#include "drawing_element.h"

class Drawing{

public:

    Drawing(){};

    ~Drawing(){};

    std::vector<DrawingElement> elements();

    void add_element(DrawingElement element){ _elements.push_back(element); }

private:

    std::vector<DrawingElement> _elements;

};

#endif