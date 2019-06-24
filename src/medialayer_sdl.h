/** medialayer_sdl.h
 *
 .* Inherits MediaLayer for handling keyboard inputs 
 * and outputs to screen.
 * 
 */
#ifndef MEDIALAYER_SDL
#define MEDIALAYER_SDL

#include <vector>
#include <string>
#include <memory>
#include <SDL2/SDL.h> // hopefully this is contained

#include "medialayer.h"
#include "medialayer_drawing_renderer.h"
#include "medialayer_sdl_drawing_renderer.h"

#include "game.h"

namespace MediaLayer{
namespace SDL{

  class MediaLayer_SDL: public MediaLayer{

public:

  MediaLayer_SDL(int window_width = 0,
                 int window_height = 0,
                 int window_x = 0,
                 int window_y = 0);

  ~MediaLayer_SDL();
    
  // Initializes Media Layer
  bool initialize(Game* game) override;
    
  // Initializes media layer with window dimensions, position window at the center of screen
  bool initialize(Game* game,
                  std::string title,
                  int window_width, int window_height) override;

  // Initializes media layer with window dimensions and position
  bool initialize(Game* game,
                  std::string title,
                  int window_width, int window_height,
                  int window_x, int window_y) override;

  // Shuts down media layer
  void shutdown() override;

  // Creates new window
  bool create_window() override;

  // Retrieves input (keyboard) from media layer
  std::vector<Key_Code> get_input() override;

  // Renders contents onto screen
  void generate_output() override;

  // Calculates delta time
  double get_delta_time() override;

  // Pointer to drawing renderer object
  Drawing_Renderer* get_drawing_renderer() override;
  
private:

  SDL_Window* _window;        // Window created by SDL 
  SDL_Renderer* _renderer;    // SDL Renderer
  int _sdl_flag{0};           // SDL Flags: I don't know what this is - openGL?

  SDL_Drawing_Renderer _drawing_renderer;

  // ----------------------------------------
  // Input

  // fill keyboard input
  void _fill_key_codes(std::vector<Key_Code>& key_codes);

  // add key_code to vector
  void _add_key_code(std::vector<Key_Code>& key_codes, Key_Code key_code);

  // ----------------------------------------
  // Output

  // Creates SDL 2D rendering context
  bool _create_renderer();

};

} // SDL
} // namespace Media
#endif
