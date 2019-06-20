/** ui_element.h
 * 
 */

#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include "drawing_element.h"

class UIElement{
public:

    UIElement();

    virtual ~UIElement(){};

    virtual void update()=0;

    virtual void render()=0;

private:

    DrawingElement::Position _position;

};
#endif