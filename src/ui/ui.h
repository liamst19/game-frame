/** ui.h
 * 
 */

#ifndef UI_H
#define UI_H

#include <vector>
#include <memory>

#include "../gameobject/gameobject.h"
#include "../medialayer/medialayer.h"
#include "ui_element.h"

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

    // Process User Input
  void process_input(std::vector<MediaLayer::Key_Code> key_codes);

    // Update UI elements
    void update(double delta_time) override;

    // Render UI elements
    void render() override;

private:

    // Collection of pointers to all UI elements
    std::vector<std::unique_ptr<UIElement>> _ui_elements;

};
#endif
