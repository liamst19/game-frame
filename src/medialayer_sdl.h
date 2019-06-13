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
#include <SDL2/SDL.h> // hopefully this is contained
#include "medialayer.h"

class MediaLayer_SDL: public MediaLayer{

public:
  
    MediaLayer_SDL():
        _window(nullptr),
        _renderer(nullptr)
    {};

    MediaLayer_SDL(int window_width, int window_height, int window_x, int window_y)
    {
        _window_width = window_width;
        _window_height = window_height;
        _win_coordinate_x = window_x;
        _win_coordinate_y = window_y;
        MediaLayer_SDL();
    };

    MediaLayer_SDL(int window_width, int window_height){
        MediaLayer_SDL(window_width, window_height, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    };

    ~MediaLayer_SDL(){
        // check if shut down was called?
        // shutdown();
    };

    // Initializes Media Layer
    bool initialize();
    
    // Initializes media layer with window dimensions, position window at the center of screen
    bool initialize(std::string title, int window_width, int window_height);

    // Initializes media layer with window dimensions and position
    bool initialize(std::string title, int window_width, int window_height, int window_x, int window_y);

    // Shuts down media layer
    void shutdown();

    // Creates new window
    bool create_window();

    // Retrieves input (keyboard) from media layer
    std::vector<Medialayer_Key_Code> get_input();

    // Renders contents onto screen
    void generate_output();

    // Calculates delta time
    double get_delta_time();

private:

    SDL_Window* _window;        // Window created by SDL 
    SDL_Renderer* _renderer;    // SDL Renderer
    int _sdl_flag{0};           // SDL Flags: I don't know what this is

    // Creates SDL 2D rendering context
    bool create_renderer();

    // Render game objects to window surface 
    void render_objects();

    // Render shape to window surface
    void draw_shape(std::vector<Vector2d> shape); 

    // Converts Vector2d to SDL_Point object
    SDL_Point convert_point(Vector2d point);

    // fill keyboard input
    void fill_key_codes(std::vector<Medialayer_Key_Code>& key_codes);

    // add key_code to vector
    void add_key_code(std::vector<Medialayer_Key_Code>& key_codes, Medialayer_Key_Code key_code);
};

#endif