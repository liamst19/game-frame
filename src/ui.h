/** ui.h
 * 
 */

#ifndef UI_H
#define UI_H

#include <vector>
#include <memory>

class UI{
public:

    UI();

    ~UI();

    void add_ui_element(uielement element);

    void render();

private:

    // Collection of pointers to all UI elements
    std::vector<std::unique_ptr<UIElement>> _ui_elements;

};
#endif