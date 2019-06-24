/** ui.cpp
 * 
 */

#include "ui.h"

#include <memory>
#include <vector>

#include "../game.h"
#include "../medialayer/medialayer.h"
#include "../gameobject/gameobject.h"
#include "ui_element.h"

namespace GameObject{
    namespace UI{

/** Constructor
 */
        UI::UI(Game* game):
            GameObject(game)
        {
            init();
        }

/** Destructor
 */
        UI::~UI()
        {}

/** public function: initialize()
 * Initialize UI
 */
        void UI::init()
        {
        }

/** public function: add_ui_element()
 * Adds UI element
 *   @elmeent: UI element object
 */
        void UI::add_ui_element(std::unique_ptr<UIElement> element)
        {
            _ui_elements.emplace_back(std::move(element));
        }

/** public function: process_input
 * Process user input
 *   @input: collection of keyboard input codes
 */
        void UI::process_input(std::vector<MediaLayer::Key_Code> input)
        {
        }

/** public function: update
 * Updates UI elmeents
 *   @delta_time: 
 */
        void UI::update(double delta_time)
        {
            for(auto& element: _ui_elements)
            {
                element->update(delta_time);
            }
        }

/** public function:: render()
 * Render UI elements
 */
        void UI::render()
        {
            for(auto& element: _ui_elements)
            {
                element->render();
            }
        }
    } // namespace UI
} // namespace GameObject
