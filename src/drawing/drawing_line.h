/** drawing_line.h
 *  Object for rendering line to screen.
 * 
 *  Currently this renders only a straight line of 1px thickness.
 * 
 *  Possibile future plans:
 *   - thickness
 *   - option for drawing curved line
 * 
 */

#ifndef DRAWING_LINE_H
#define DRAWING_LINE_H

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

    class LineDrawing: public DrawingElement
    {

    public:

        // Constructor
        LineDrawing(MediaLayer::Drawing_Renderer* renderer, 
                    int aX, int aY, 
                    int bX, int bY, 
                    int r, int g, int b, int alpha);

        // Constructor
        LineDrawing(MediaLayer::Drawing_Renderer* renderer, 
                    Position a, 
                    Position b, 
                    Color color);

        // Destructor
        ~LineDrawing();

        // Renders line to screen
        bool render() override;

        // End point of line ab
        Position a();

        // End point of line ab
        Position b();

        // Width
        int width() override;

        // Height
        int height() override;

        // Position of the center of element
        Position center() override;

    private:

        Position _point_a, _point_b;

    };

} // namespace Drawing
#endif
