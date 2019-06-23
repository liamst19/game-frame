/** ui.cpp
 * 
 */

#include "ui.h"

#include <memory>
#include <vector>

#include "game.h"
#include "medialayer.h"
#include "gameobject.h"
#include "ui_element.h"

/** Constructor
 */
GameUI::GameUI(Game* game):
  GameObject(game)
{
  init();
}

/** Destructor
 */
GameUI::~GameUI()
{}

/** public function: initialize()
 * Initialize GameUI
 */
void GameUI::init()
{
}

/** public function: add_ui_element()
 * Adds GameUI element
 *   @elmeent: GameUI element object
 */
void GameUI::add_ui_element(std::unique_ptr<UIElement> element)
{
    _ui_elements.emplace_back(std::move(element));
}

/** public function: process_input
 * Process user input
 *   @input: collection of keyboard input codes
 */
void GameUI::process_input(std::vector<MediaLayer_Key_Code> input)
{
}

/** public function: update
 * Updates GameUI elmeents
 *   @delta_time: 
 */
void GameUI::update(double delta_time)
{
    for(auto& element: _ui_elements)
    {
        element->update(delta_time);
    }
}

/** public function:: render()
 * Render GameUI elements
 */
void GameUI::render()
{
    for(auto& element: _ui_elements)
    {
        element->render();
    }
}
