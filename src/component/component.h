/** component.h
 */

#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include "../medialayer/medialayer.h"

namespace GameObject{

    class GameObject;

    namespace Component{

        
        class Component{

        public:

            Component(GameObject* game_object):
               _game_object(game_object)
            {
            }

            virtual ~Component()
            {
            }

            // Process Update
            virtual void update(double delta_time)=0;

            // Process User Input
            virtual void process_input(std::vector<MediaLayer::Key_Code> key_codes)=0;

            // Render to screen
            virtual void render()=0;

        protected:

            GameObject* _game_object;
            
        };

    } // namespace Component
} // namespace GameObject
#endif
