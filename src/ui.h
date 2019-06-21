/** ui.h
 * 
 */

#ifndef UI_H
#define UI_H

#include <vector>
#include <memory>

#include "ui_element.h"

class Game;

class GameUI{
public:

    // Constructor
    GameUI(Game* game);

    // Destructor
    ~GameUI();

    // Initialize UI
    bool initialize();

    // Add UI element
    void add_ui_element(std::unique_ptr<UIElement> element);

    // Update UI elements
    void update(double delta_time);

    // Render UI elements
    void render();

private:

    Game* _game;

    // Collection of pointers to all UI elements
    std::vector<std::unique_ptr<UIElement>> _ui_elements;

};
#endif