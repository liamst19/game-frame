/** drawing.h
 * 
 */

#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include <memory>
// #include "drawing_element.h"


namespace Drawing{

    class DrawingElement;

    // Represents Color and Alpha Transparency values.
    // Numbers should be within 0 to 255.
    struct Color
    {
        int r, g, b; // Red, green, blue
        int alpha;   // Alpha transparency
    };

    // Represents x and y-coordinates and color of a point.
    struct Position
    {
        int x, y;
    };
    
    class Drawing{
    public:

        // Constructor
        Drawing();

        // Destructor
        ~Drawing();

        // Add drawing element
        void add_drawing_element(std::unique_ptr<DrawingElement> element);

        // Render Drawing
        void render();

        // Overall width of the drawing
        int width();

        // Overall height of the drawing
        int height();

        // Position of the center of drawing
        Position center();

    private:

        std::vector<std::unique_ptr<DrawingElement>> _drawing_elements;

    };
    
} // namespace Drawing
#endif
