/** gameobject.h
 *
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class Game;

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
  
  // Update Game Object
  virtual void update(double delta_time)=0;

  // Render Game Object to screen
  virtual void render()=0;

 protected:

  Game* _game;
  
 private:

};
#endif // GAMEOBJECT_H
