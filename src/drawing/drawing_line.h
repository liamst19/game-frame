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
                    DrawingElement::Position a, 
                    DrawingElement::Position b, 
                    DrawingElement::Color color);

        // Destructor
        ~LineDrawing();

        // Renders line to screen
        bool render() override;

        // End point of line ab
        DrawingElement::Position a();

        // End point of line ab
        DrawingElement::Position b();

    private:

        DrawingElement::Position _point_a, _point_b;

    };

} // namespace Drawing
#endif
