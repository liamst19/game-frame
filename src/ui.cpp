/** ui.cpp
 * 
 */

#include "ui.h"

#include <memory>
#include <vector>

#include "game.h"
#include "ui_element.h"

/** Constructor
 */
GameUI::GameUI(Game* game):
    _game(game)
{}

/** Destructor
 */
GameUI::~GameUI()
{}

/** public function: initialize()
 * Initialize GameUI
 */
bool GameUI::initialize()
{
    return true;
}

/** public function: add_ui_element()
 * Adds GameUI element
 *   @elmeent: GameUI element object
 */
void GameUI::add_ui_element(std::unique_ptr<UIElement> element)
{
    _ui_elements.emplace_back(std::move(element));
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
