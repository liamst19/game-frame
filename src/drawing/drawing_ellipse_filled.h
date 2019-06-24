/** drawing_ellipse_filled.h
 *  Class for rendering filled ellipse to screen
 * 
 *  Possible future plans:
 *   - Line thickness
 *   - Non-axis-aligned ellipses
 * 
 */

#ifndef DRAWING_ELLIPSE_FILLED_H
#define DRAWING_ELLIPSE_FILLED_H

#include "drawing_ellipse.h"
#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

    class FilledEllipseDrawing: public EllipseDrawing
    {

    public:

        // Constructor
        FilledEllipseDrawing(MediaLayer::Drawing_Renderer* renderer, 
                             int x, int y, 
                             int radiusX, int radiusY, 
                             int r, int g, int b, int alpha);

        // Constructor
        FilledEllipseDrawing(MediaLayer::Drawing_Renderer* renderer, 
                             DrawingElement::Position a, 
                             int radiusX, int radiusY,
                             DrawingElement::Color color);

        // Destructor
        ~FilledEllipseDrawing();

        // Renders line to screen
        bool render() override;

    };

} // namespace Drawing
#endif
