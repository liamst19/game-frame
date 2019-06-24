/** drawing_rectangle_filled.h
 *  Class for rendering filled rectangle to screen.
 * 
 *  Possible future plans:
 *   - Line thickness
 *   - Rounded corners
 * 
 */

#ifndef DRAWING_RECTANGLE_FILLED_H
#define DRAWING_RECTANGLE_FILLED_H

#include "drawing_rectangle.h"
#include "../medialayer/medialayer_drawing_renderer.h"

class FilledRectangleDrawing: public RectangleDrawing
{

public:

    // Constructor
    FilledRectangleDrawing(
        MediaLayer::Drawing_Renderer* renderer, 
        int aX, int aY, 
        int bX, int bY, 
        int r, int g, int b, int alpha);

    // Constructor
    FilledRectangleDrawing(
        MediaLayer::Drawing_Renderer* renderer, 
        DrawingElement::Position a, DrawingElement::Position b, 
        DrawingElement::Color color);

    // Destructor
    ~FilledRectangleDrawing();

    // Renders rectangle to screen
    bool render() override;

private:


};
#endif
