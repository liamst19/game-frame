/** gameobject_test.h
 *
 */

#ifndef GAMEOBJECT_TEST_H
#define GAMEOBJECT_TEST_H

#include <string>
#include "gameobject.h"
#include "drawing.h"

class TestGameObject: public GameObject
{
 public:

  // Constructor
  TestGameObject(Game* game);

  // Destructor
  ~TestGameObject();

  // Initialize Game Object
  void init() override;
  
  // Update Game Object
  void update(double delta_time) override;

  // Render Game Object to screen
  void render() override;
  
 private:
  Drawing _drawing;

  const std::string _font_univers{"data/Univers-Extended.ttf"};
  const std::string _font_lucon{"data/lucon.ttf"};

};
#endif // GAMEOBJECT_TEST_H
