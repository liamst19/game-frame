/** gameobject.h
 *
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "../medialayer/medialayer.h"
#include "../component/component.h"

class Game;

namespace GameObject{
    
    class GameObject
    {
    public:

        // Constructor
        GameObject(Game* game);

        // Destructor
        virtual ~GameObject();

        // Initialize Game Object
        virtual void init()=0;
  
        // Process Input
        virtual void process_input(
                std::vector<MediaLayer::Key_Code> input)=0;
  
        // Update Game Object
        virtual void update(double delta_time)=0;

        // Render Game Object to screen
        virtual void render()=0;

    protected:

        Game* _game;

        void add_component(Component::Component* component);

        void update_components(double delta_time);

        void pass_input_to_components(
                std::vector<MediaLayer::Key_Code> key_codes);

        void render_components();
  
    private:

        std::vector<Component::Component*> _components;
    };

} // namespace GameObject
#endif // GAMEOBJECT_H
