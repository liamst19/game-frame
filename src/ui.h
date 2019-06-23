/** ui.h
 * 
 */

#ifndef UI_H
#define UI_H

#include <vector>
#include <memory>

#include "gameobject.h"

#include "ui_element.h"

class Game;

class GameUI: public GameObject{
public:

    // Constructor
    GameUI(Game* game);

    // Destructor
    ~GameUI();

    // Initialize UI
    void init() override;

    // Add UI element
    void add_ui_element(std::unique_ptr<UIElement> element);

    // Update UI elements
    void update(double delta_time) override;

    // Render UI elements
    void render() override;

private:

    // Collection of pointers to all UI elements
    std::vector<std::unique_ptr<UIElement>> _ui_elements;

};
#endif
