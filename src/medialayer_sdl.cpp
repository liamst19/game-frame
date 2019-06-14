/** medialayer_sdl.cpp
 *
 */

#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include "medialayer_sdl.h"
#include "medialayer_sdl_texture_drawing.h"

#include "drawing.h"
#include "drawing_element.h"
#include "drawing_element_lines.h"

// --------------------------------------------------
// Public

/* function: initialize()
 * 
 */
bool MediaLayer_SDL::initialize()
{

    // Create Window
    if(!create_window())
    {
        return false;
    } 
    
    // Create Rendering context
    if (!create_renderer())
    {
        return false;
    }

    return true;
}

/* function: initialize()
 * 
 */
bool MediaLayer_SDL::initialize(std::string title, int window_width, int window_height, int window_x, int window_y)
{
    // Set Window title
    _title = title;

    // Set window dimensions
    _window_width = window_width;
    _window_height = window_height;

    // Set window position
    _win_coordinate_x = window_x;
    _win_coordinate_y = window_y;

    return initialize();
}

/* function: initialize()
 *
 * Initialize with given window dimensions, position window at the center of screen
 */
bool MediaLayer_SDL::initialize(std::string title, int window_width, int window_height)
{
    return initialize(title, window_width, window_height, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

/* function: shutdown()
 * 
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
 * 
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

/* function: generate_output()
 * 
 */
void MediaLayer_SDL::generate_output()
{
    // Reset Window Color: to black
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    // Clear previous screen
    SDL_RenderClear(_renderer);

    // Render Game Objects ------------------------------
    render_objects();
    // --------------------------------------------------
    
    SDL_RenderPresent(_renderer);
}

/* function: delta_time()
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

/* function: get_input()
 * get keyboard input 
 */
std::vector<Medialayer_Key_Code> MediaLayer_SDL::get_input()
{
    std::vector<Medialayer_Key_Code> key_codes;

    // Close Window
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
        case SDL_QUIT:
            key_codes.push_back(Medialayer_Key_Code::quit);
            return key_codes;
            break;
        };
    };

    // Get Keyboard Inputs
    fill_key_codes(key_codes);

    // Return null
    return key_codes;
}

// --------------------------------------------------
// Private

/* function: create_renderer()
 * 
 */
bool MediaLayer_SDL::create_renderer()
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

/** function: add_key_code()
 *  add key_code to vector 
 */
void MediaLayer_SDL::add_key_code(std::vector<Medialayer_Key_Code>& key_codes, Medialayer_Key_Code key_code)
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

/** function: fill_key_codes()
 * fill a vector with keyboard inputs
 */
void MediaLayer_SDL::fill_key_codes(std::vector<Medialayer_Key_Code>& key_codes)
{
    // Get state of keyboard
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    if(state[SDL_SCANCODE_ESCAPE])
    {
        add_key_code(key_codes, Medialayer_Key_Code::esc);
    };
    if(state[SDL_SCANCODE_W])
    {
        add_key_code(key_codes, Medialayer_Key_Code::w);
    }
    if(state[SDL_SCANCODE_A])
    {
        add_key_code(key_codes, Medialayer_Key_Code::a);
    }
    if(state[SDL_SCANCODE_S])
    {
        add_key_code(key_codes, Medialayer_Key_Code::s);
    }
    if(state[SDL_SCANCODE_D])
    {
        add_key_code(key_codes, Medialayer_Key_Code::d);
    }
    if(state[SDL_SCANCODE_SEMICOLON])
    {
        add_key_code(key_codes, Medialayer_Key_Code::semicolon);
    }
}

/* function: render_objects()
 *  Render all game objects to window surface
 */
void MediaLayer_SDL::render_objects()
{
    // Convert game object shape data and populate _shapes

    // iterate through std::vector<std::vector<Vector2d>>
    // from each std::vector<Vector2d>, draw lines from coordinates,
    // closing the shape by drawing the line from end to beginning.
    for(auto shape: _shapes)
    {
        draw_shape(shape);
    }

    for(auto drawing: _drawings)
    {
        draw(drawing);
    }
}


void MediaLayer_SDL::draw(Drawing drawing)
{
    MediaLayer_SDL_Texture_Drawing texture{_renderer, _window};
    texture.set_drawing(drawing);
    if(texture.load())
    {
        texture.render(100, 100);
    } else
    {
        // Something went wrong
        SDL_Log("Texture was not loaded");
    };
}

/** function: draw_shape()
 * Render shape to window surface
 */
void MediaLayer_SDL::draw_shape(std::vector<Vector2d> shape)
{
    if(shape.size() < 3)
    {
        // not a shape
        SDL_Log("Not a shape");
        return;
    }

    // Set color: opaque white
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    int size = shape.size() + 1;
    SDL_Point points[size];
    for(int i = 0; i < shape.size(); ++i)
    {
        points[i] = convert_point(shape[i]);
    }

    // Close shape by connecting to the beginning
    points[size - 1] = convert_point(shape[0]);

    SDL_RenderDrawLines(_renderer, points, size);
}

/** function: convert_point()
 *  Converts Vector2d to SDL_Point object 
 */
SDL_Point MediaLayer_SDL::convert_point(Vector2d point)
{
    return SDL_Point{static_cast<int>(point.x), static_cast<int>(point.y)};
}
