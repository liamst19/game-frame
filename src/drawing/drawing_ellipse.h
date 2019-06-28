/** drawing_ellipse.h
 *  Class for rendering ellipse to screen
 * 
 *  Possible future plans:
 *   - Line thickness
 *   - Non-axis-aligned ellipses
 * 
 */

#ifndef DRAWING_ELLIPSE_H
#define DRAWING_ELLIPSE_H

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

    class EllipseDrawing: public DrawingElement
    {

    public:

        // Constructor
        EllipseDrawing(MediaLayer::Drawing_Renderer* renderer, 
                       int x, int y, 
                       int radiusX, int radiusY, 
                       int r, int g, int b, int alpha);

        // Constructor
        EllipseDrawing(MediaLayer::Drawing_Renderer* renderer, 
                       Position a, 
                       int radiusX, int radiusY,
                       Color color);

        // Destructor
        ~EllipseDrawing();

        // Renders line to screen
        bool render() override;

        // Center of ellipse
        Position center() override;

        // Horizontal radius
        int radius_x();

        // Vertical radius
        int radius_y();

        // Width
        int width() override;

        // Height
        int height()override ;

    protected:

        Position _center; // _focus_a, _focus_b;

        int _radius_x, _radius_y;

    };

} // namespace Drawing
#endif
