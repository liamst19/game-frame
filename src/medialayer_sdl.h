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
#include "medialayer_sdl_texture_text.h"

#include "drawing_element.h"
#include "drawing_text.h"
#include "ui_element_clock.h"

class MediaLayer_SDL: public MediaLayer{

public:

    MediaLayer_SDL(int window_width = 0, int window_height = 0, int window_x = 0, int window_y = 0):
        MediaLayer(window_width, window_height, window_x, window_y),
        _window(nullptr),
        _renderer(nullptr)
    {}

    ~MediaLayer_SDL(){
        // check if shut down was called?
        // shutdown();
    }

    // Initializes Media Layer
    bool initialize() override;
    
    // Initializes media layer with window dimensions, position window at the center of screen
    bool initialize(std::string title, int window_width, int window_height) override;

    // Initializes media layer with window dimensions and position
    bool initialize(std::string title, int window_width, int window_height, int window_x, int window_y) override;

    // Shuts down media layer
    void shutdown() override;

    // Creates new window
    bool create_window() override;

    // Retrieves input (keyboard) from media layer
    std::vector<Medialayer_Key_Code> get_input() override;

    // Renders contents onto screen
    void generate_output() override;

    // Calculates delta time
    double get_delta_time() override;

    // Pointer to drawing renderer object
    MediaLayer_Drawing_Renderer* get_drawing_renderer() override;

private:

    SDL_Window* _window;        // Window created by SDL 
    SDL_Renderer* _renderer;    // SDL Renderer
    int _sdl_flag{0};           // SDL Flags: I don't know what this is - openGL?

    MediaLayer_SDL_Drawing_Renderer _drawing_renderer;

    // For Testing ----------------------------
    const std::string _font_univers{"data/Univers-Extended.ttf"};
    const std::string _font_lucon{"data/lucon.ttf"};
    MediaLayer_SDL_Texture_Text _text_texture1, _text_texture2;
    int _text_index{-5};
    std::unique_ptr<ClockUI> _clock;

    bool _test_init();
    void _test_render();
    // ----------------------------------------

    // ----------------------------------------
    // Input

    // fill keyboard input
    void _fill_key_codes(std::vector<Medialayer_Key_Code>& key_codes);

    // add key_code to vector
    void _add_key_code(std::vector<Medialayer_Key_Code>& key_codes, Medialayer_Key_Code key_code);

    // ----------------------------------------
    // Output

    // Creates SDL 2D rendering context
    bool _create_renderer();

    // Render game objects to window surface 
    void _render_objects();

};

#endif