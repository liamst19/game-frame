/** drawing_rectangle.h
 *  Class for rendering rectangle to screen.
 * 
 *  Possible future plans:
 *   - Line thickness
 *   - Rounded corners
 * 
 */

#ifndef DRAWING_RECTANGLE_H
#define DRAWING_RECTANGLE_H

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

    class RectangleDrawing: public DrawingElement
    {

    public:

        // Constructor
        RectangleDrawing(
                MediaLayer::Drawing_Renderer* renderer, 
                int aX, int aY, 
                int bX, int bY, 
                int r, int g, int b, int alpha);

        // Constructor
        RectangleDrawing(
                MediaLayer::Drawing_Renderer* renderer, 
                DrawingElement::Position a, DrawingElement::Position b, 
                DrawingElement::Color color);

        // Destructor
        ~RectangleDrawing();

        // Renders rectangle to screen
        bool render() override;

        // Vertice
        DrawingElement::Position a();

        // Vertice
        DrawingElement::Position b();

    protected:

        DrawingElement::Position _point_a, _point_b;

    };

} // namespace Drawing
#endif
