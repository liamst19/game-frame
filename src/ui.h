/** ui.h
 * 
 */

#ifndef UI_H
#define UI_H

#include <vector>
#include <memory>

#include "ui_element.h"

class UI{
public:

    UI();

    ~UI();

    void add_ui_element(std::unique_ptr<UIElement> element);

    void render();

private:

    // Collection of pointers to all UI elements
    std::vector<std::unique_ptr<UIElement>> _ui_elements;

};
#endif