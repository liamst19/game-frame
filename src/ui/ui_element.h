/** ui_element.h
 * 
 */

#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include "../drawing/drawing_element.h"
#include "../drawing/drawing.h"

namespace GameObject{
    namespace UI{

        class UIElement{
        public:

            // Constructor
            UIElement();

            // Destructor
            virtual ~UIElement(){};

            // Update UI element
            virtual void update(double delta_time)=0;

            // Render UI element to screen
            void render();

        protected:

            Drawing::DrawingElement::Position _position;
            Drawing::Drawing _drawing;

        };
    } // namespace UI
} // namespace GameObject
#endif
