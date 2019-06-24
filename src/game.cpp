/** game.cpp
 * Game Engine
 */

#include <vector>
#include <memory>

#include "game.h"
#include "randomnumber.h"
#include "medialayer/medialayer.h"

#include "ui/ui.h"
#include "ui/ui_element_clock.h"
#include "gameobject/gameobject.h"
#include "gameobject/gameobject_test.h"

// -------------------------------------------------------------
// Tests -------------------------------------------------------
void Game::_test_init()
{
  // Test: Add GameObject---------------------------------------
  add_game_object(std::make_unique<TestGameObject>(this));
  // -----------------------------------------------------------
  // Test: Add Clock UI Element --------------------------------
  _ui.add_ui_element(std::make_unique<ClockUI>(media_layer(), 2, 2, 12));
  // -----------------------------------------------------------
}

void Game::_test_update(double delta_time)
{
}

void Game::_test_output()
{
}

/* --------------------------------------------------
/* Public

/** Constructor
*
*/
Game::Game(std::string game_title, 
           int window_width,
           int window_height):
  _media_layer(&_media_layer_sdl),
  _game_title(game_title),
  _ui(this),
  _window_width(window_width),
  _window_height(window_height)
{
}

/** Destructor
 */
Game::~Game()
{
  shutdown();
}

/** public function: initialize()
 *  Initializes the game, readying game input/output
 */
bool Game::initialize()
{
  // Check if Media Layer exists
  if(_media_layer == nullptr)
    {
      // throw exception: media layer is not initialized
      return false;
    } else if(_window_width <= 0 || _window_height <= 0)
    {
      // throw exception: invalid window size
      return false;
    }

  bool initialized = true;

  // Initialize Media Layer
  initialized = media_layer()->initialize(this,
                                          _game_title,
                                          _window_width,
                                          _window_height);

  // Initialize Game Objects

  // Initialize UI Objects
  add_game_object(std::unique_ptr<GameUI>(&_ui));

  // Test ------------------------------------------------------
  _test_init();
  // -----------------------------------------------------------

  return initialized;
}

/** public function: run_loop()
 *  Begins game loop.
 */
void Game::run_loop()
{
  _is_running = true;

  while(_is_running)
    {
      _process_input();
      _update_game();
      _generate_output();
    }

}

/** public function: shutdown()
 *  Frees resources for closing.
 */
void Game::shutdown()
{
  if(_media_layer != nullptr)
    {
      media_layer()->shutdown();
      _media_layer = nullptr;
    }
}

/** public function: add_game_object()
 * Adds game object to game
 *   @game_object: Game Object
 */
void Game::add_game_object(std::unique_ptr<GameObject> game_object)
{
  _game_objects.emplace_back(std::move(game_object));
}

/** public function: render_objects()
 * Renders game and UI objects.  This should be called during
 * MediaLayer's rendering sequence, where screen is cleared and then
 * new image is blitted to screen.
 * 
 */
void Game::render_objects()
{
  // Test --------------------------------------------------
  _test_output();
  // -------------------------------------------------------

  // Render Game Objects
  for(auto& obj: _game_objects)
    {
      obj->render();
    }
}

/** public function: media_layer()
 * Get pointer to media layer
 */
MediaLayer::MediaLayer* Game::media_layer()
{
  return _media_layer;
}

/** public function: window_width
 * Might refer to Media Layer if window is adjustable
 */
int Game::window_width()
{
  return _window_width;
}

/** public function: window_height
 * Might refer to Media Layer if window is adjustable 
 */
int Game::window_height()
{
  return _window_height;
}

/** public function: rand()
 *  Returns a random integer between min and max 
 *  values specified.
 */
int Game::rand(int min, int max)
{
  return _rand.rand(min, max);
}

/* --------------------------------------------------
   /* Private

   /** private function: _process_input()
   *  Listens for keyboard inputs and do something with them.
   */
void Game::_process_input()
{
  // Get Device Inputs
  std::vector<MediaLayer::Key_Code> key_codes = media_layer()->get_input();

  // Iterate through inputs and do something
  for(auto key: key_codes)
    {
      // Check for exit
      if(key == MediaLayer::Key_Code::quit || key == MediaLayer::Key_Code::esc)
        {
          // Exit game
          _is_running = false;
          return;
        } else if(key != MediaLayer::Key_Code::null)
        {
          // If key is a valid key, do something (e.g., map key to game action)

        }
    }

  // Pass events to game objects.
  for(auto& obj: _game_objects)
    {
      obj->process_input(key_codes);
    }

}

/** private function: _update_game()
 */
void Game::_update_game()
{
  // Get delta time
  double delta_time = media_layer()->get_delta_time();

  // Update Game Objects
  // Render Game Objects
  for(auto& obj: _game_objects)
    {
      obj->update(delta_time);
    }

  // Test --------------------------------------------------
  _test_update(delta_time);
  // -------------------------------------------------------
}

/** private function: _generate_output()
 */
void Game::_generate_output()
{
  media_layer()->generate_output();
}
