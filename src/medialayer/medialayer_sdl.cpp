/** medialayer_sdl.cpp
 *
 */

#include "medialayer_sdl.h"

#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include "SDL_ttf.h"
#include "SDL_image.h"

#include "../game.h"
#include "medialayer_drawing_renderer.h"
#include "medialayer_sdl_drawing_renderer.h"

namespace MediaLayer{
    namespace SDL{

// --------------------------------------------------
// Public

/** Constructor
 *   @window_width, @window_height: Dimensions of window
 *   @window_x, @window_y: Position where the window will open
 */
        MediaLayer_SDL::MediaLayer_SDL(int window_width,
                                       int window_height,
                                       int window_x,
                                       int window_y):
            MediaLayer(window_width,
                       window_height,
                       window_x,
                       window_y),
            _window(nullptr),
            _renderer(nullptr)  
        {
        }

/** Destructor
 */
        MediaLayer_SDL::~MediaLayer_SDL()
        {
        }

/* public function: initialize()
 */
        bool MediaLayer_SDL::initialize(Game* game)
        {
            _game = game;

            // Create Window
            if(!create_window())
            {
                SDL_Log("Failed to create SDL_Window: %s", SDL_GetError());
                return false;
            } 
    
            // Create Rendering context
            if (!_create_renderer())
            {
                SDL_Log("Failed to create SDL_Renderer: %s", SDL_GetError());
                return false;
            }

            // Initialize SDL_ttf
            if(TTF_Init() == -1)
            {
                SDL_Log("SDL_ttf failed to initialize: %s", SDL_GetError());
                return false;
            }

            // Initialize SDL_image
            if(IMG_Init(IMG_INIT_JPG) == -1)
            {
                SDL_Log("SDL_image failed to initialize: %s", SDL_GetError());
                return false;
            }

            // Initialize Drawing Renderer
            if(!_drawing_renderer.initialize(_renderer, _window))
            {
                return false;
            }

            return true;
        }

/* public function: initialize()
 */
        bool MediaLayer_SDL::initialize(Game* game,
                                        std::string title,
                                        int window_width, int window_height,
                                        int window_x, int window_y)
        {
            // Set Window title
            _title = title;

            // Set window dimensions
            _window_width = window_width;
            _window_height = window_height;

            // Set window position
            _win_coordinate_x = window_x;
            _win_coordinate_y = window_y;

            return initialize(game);
        }

/* function: initialize()
 * Initialize with given window dimensions, position window at the center of screen
 */
        bool MediaLayer_SDL::initialize(Game* game,
                                        std::string title,
                                        int window_width, int window_height)
        {
            return initialize(game, title,
                              window_width, window_height,
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        }

/* public function: shutdown()
 */
        void MediaLayer_SDL::shutdown()
        {
            SDL_DestroyRenderer(_renderer);
            _renderer = nullptr;
            SDL_DestroyWindow(_window);
            _window = nullptr;
            SDL_Quit();
        }

/* function: create_window()
 */
        bool MediaLayer_SDL::create_window()
        {
            _window = SDL_CreateWindow(_title.c_str(),
                                       _win_coordinate_x,
                                       _win_coordinate_y,
                                       _window_width,
                                       _window_height,
                                       _sdl_flag);
            if(!_window)
            {
                SDL_Log("Failed to create window: %s", SDL_GetError());
                // Throw exception
                return false;
            };

            return true;
        }

/* public function: generate_output()
 */
        void MediaLayer_SDL::generate_output()
        {
            // Reset Window Color: to black
            SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

            // Clear previous screen
            SDL_RenderClear(_renderer);

            // Render Game Objects ------------------------------
            _game->render_objects();
            // --------------------------------------------------
    
            SDL_RenderPresent(_renderer);
        }

/** public function: get_drawing_renderer()
 *  Gets drawing renderer
 */
        Drawing_Renderer* MediaLayer_SDL::get_drawing_renderer()
        {
            return &_drawing_renderer;
        }

/* public function: delta_time()
 * Returns delta time in seconds, used for calculating updated data such as position
 * 
 */
        double MediaLayer_SDL::get_delta_time()
        {
            double delta = (SDL_GetTicks() - _ticks_count) / 1000.0;

            // cap delta time
            if(delta > _delta_max)
            {
                delta = _delta_max;
            }

            // Reset tick counter
            _ticks_count = SDL_GetTicks();

            return delta;
        }

/* public function: get_input()
 * get keyboard input 
 */
        std::vector<Key_Code> MediaLayer_SDL::get_input()
        {
            std::vector<Key_Code> key_codes;

            // Close Window
            SDL_Event event;
            while(SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                case SDL_QUIT:
                    key_codes.push_back(Key_Code::quit);
                    return key_codes;
                    break;
                };
            };

            // Get Keyboard Inputs
            _fill_key_codes(key_codes);

            // Return null
            return key_codes;
        }

// --------------------------------------------------
// Private

/** private function: _add_key_code()
 *  add key_code to vector 
 */
        void MediaLayer_SDL::_add_key_code(std::vector<Key_Code>& key_codes, Key_Code key_code)
        {
            // Check if key is already in the vector
            for(auto key: key_codes)
            {
                if(key == key_code)
                {
                    return;
                }
            }
            key_codes.push_back(key_code);
        }

/** private function: _fill_key_codes()
 * fill a vector with keyboard inputs
 */
        void MediaLayer_SDL::_fill_key_codes(std::vector<Key_Code>& key_codes)
        {
            // Get state of keyboard
            const Uint8* state = SDL_GetKeyboardState(nullptr);
            if(state[SDL_SCANCODE_ESCAPE])
            {
                _add_key_code(key_codes, Key_Code::esc);
            };
            if(state[SDL_SCANCODE_W])
            {
                _add_key_code(key_codes, Key_Code::w);
            }
            if(state[SDL_SCANCODE_A])
            {
                _add_key_code(key_codes, Key_Code::a);
            }
            if(state[SDL_SCANCODE_S])
            {
                _add_key_code(key_codes, Key_Code::s);
            }
            if(state[SDL_SCANCODE_D])
            {
                _add_key_code(key_codes, Key_Code::d);
            }
            if(state[SDL_SCANCODE_SEMICOLON])
            {
                _add_key_code(key_codes, Key_Code::semicolon);
            }
        }

// -------------------------------------------------------------------

/* private function: _create_renderer()
 * 
 */
        bool MediaLayer_SDL::_create_renderer()
        {
            // create renderer
            _renderer = SDL_CreateRenderer(
                    _window,
                    -1,
                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
                );

            if(!_renderer)
            {
                SDL_Log("Failed to create renderer: %s", SDL_GetError());
                // Throw exception
                return false;
            }

            return true;
        }

    } // SDL

} // namespace Media
