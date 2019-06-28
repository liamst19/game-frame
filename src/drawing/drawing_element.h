/** drawing_element.h
 * Drawing object represents an image of a single object.
 * It should contain various simple drawing elements that make up the image.
 */

#ifndef DRAWING_ELEMENT_H
#define DRAWING_ELEMENT_H

#include <vector>
#include "drawing.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

    class DrawingElement{

    public:

        // Constructor
        DrawingElement(MediaLayer::Drawing_Renderer* drawing_renderer,
                       Color color);

        // Destructor
        ~DrawingElement();

        // --------------------------------------------------
        // Virtual Methods

        // Render drawing to screen 
        virtual bool render(int x = 0, int y = 0, double rotation = 0)=0;

        // Get the width of the element
        virtual int width()=0;

        // Get the height of the element
        virtual int height()=0;

        // Get the position of the center of the element
        virtual Position center()=0;

        // Position of the upper left corner
        virtual Position min()=0;

        // Position of the lower right corner
        virtual Position max()=0;
 
        // --------------------------------------------------

        // Render color of the drawing
        Color color();

    protected:

        // Pointer to object which handles screen output.
        MediaLayer::Drawing_Renderer* _drawing_renderer;

        Color _color;

    };

} // namespace Drawing
#endif
