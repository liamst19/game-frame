/** ui_element.h
 * 
 */

#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include "drawing_element.h"
#include "drawing.h"

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

    DrawingElement::Position _position;
    Drawing _drawing;

};
#endif