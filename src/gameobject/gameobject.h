/** gameobject.h
 *
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "../medialayer/medialayer.h"

class Game;

namespace GameObject{
    
    class GameObject
    {
    public:

        // Constructor
        GameObject(Game* game):
            _game(game){}

        // Destructor
        virtual ~GameObject(){}

        // Initialize Game Object
        virtual void init()=0;
  
        // Process Input
        //  ** MediaLayer::Key_Codes should be replaced with vector of Action Codes
        virtual void process_input(std::vector<MediaLayer::Key_Code> input)=0;
  
        // Update Game Object
        virtual void update(double delta_time)=0;

        // Render Game Object to screen
        virtual void render()=0;

    protected:

        Game* _game;
  
    private:

    };

} // namespace GameObject
#endif // GAMEOBJECT_H
