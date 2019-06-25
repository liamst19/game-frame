/** gameobject.cpp
 */

#include "gameobject.h"
#include <vector>
#include "../medialayer/medialayer.h"

namespace GameObject{

    /** Constructor
     */
    GameObject::GameObject(Game* game):
        _game(game)
    {
    }

    /** Destructor
     */
    GameObject::~GameObject()
    {
    }
    
    /** protected function: add_component()
     * Adds component to object vector
     *   @component: pointer to component
     */
    void GameObject::add_component(
            Component::Component* component)
    {
        _components.push_back(component);
    }

    /** protected function: update_components()
     * Updates object's components
     */
    void GameObject::update_components(double delta_time)
    {
        for(auto component: _components)
        {
            component->update(delta_time);
        }
    }

    /** protected function: process_inputs()
     * Passes user inputs to components
     *   @key_codes: user inputs
     */
    void GameObject::pass_input_to_components(
            std::vector<MediaLayer::Key_Code> key_codes)
    {
        for(auto component: _components)
        {
            component->process_input(key_codes);
        }
    }

    /** protected function: render_components()
     * Render components
     */
    void GameObject::render_components()
    {
        for(auto component: _components)
        {
            component->render();
        }
    }
    
} // namespace GameObject
