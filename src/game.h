/** game.h
 * Game entry point.
 */

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "randomnumber.h"
#include "medialayer.h"
#include "ui.h"
#include "drawing.h"

class Game{

public:

  // Constructor
  Game(std::string game_title, 
       MediaLayer* media_layer,
       int window_width,
       int window_height):
    _game_title(game_title),
    _media_layer(media_layer),
    _window_width(window_width),
    _window_height(window_height),
    _ui(this)
  {
  };

  // Destructor
  ~Game(){};

  // Initializes Game
  bool initialize();

  // Runs game loop
  void run_loop();

  // Shuts down game
  void shutdown();

  // Render game objects and UI
  void render_objects(); 

  // Get Random integer
  int rand(int min, int max);

  // Window Width
  int window_width();

  // Window Height
  int window_height();

private:

  MediaLayer* _media_layer;

  GameUI _ui;

  // Testing ------------------------------
  const std::string _font_univers{"data/Univers-Extended.ttf"};
  const std::string _font_lucon{"data/lucon.ttf"};
  Drawing _drawing;

  void _test_init();
  void _test_update(double delta_time);
  void _test_output();
  // --------------------------------------

  std::string _game_title;

  RandomNumber _rand;

  bool _is_running; // for checking game loop

  int _window_width{720};
  int _window_height{480};

  // Retrieves and handles keyboard input from media layer
  void _process_input();

  // Update game objects
  void _update_game();

  // Renders updated game objects
  void _generate_output();

};
#endif
