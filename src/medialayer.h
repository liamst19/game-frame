/** medialayer.h
 *
 * Interface for receiving input from devices, 
 * and sending output to screen. Probably completely
 * unnecessary and perhaps a waste of time.
 * 
 */
#ifndef MEDIALAYER_H
#define MEDIALAYER_H

#include <vector>
#include <string>
#include "medialayer_drawing_renderer.h"

// Keyboard inputs and window events
enum class Medialayer_Key_Code{
    null=0, // default
    quit,
    esc,
    spc,
    w,
    a,
    s,
    d,
    semicolon
};

class MediaLayer{

public:

    MediaLayer(int window_width = 0, int window_height = 0, int window_x = 0, int window_y = 0):
        _window_width(window_width),
        _window_height(window_height),
        _win_coordinate_x(window_x),
        _win_coordinate_y(window_y)
    {};
    virtual ~MediaLayer(){};

    // --------------------------------------------------
    // Static Wrapper Functions -------------------------

    // Wrapper function for initializing media layer object
    static bool MediaLayer_Initialize(std::string title, MediaLayer* layer, int window_width, int window_height);

    // Wrapper function for shutting down media layer object
    static void MediaLayer_Shutdown(MediaLayer* layer);

    // Wrapper function for retrieving keyboard input
    static std::vector<Medialayer_Key_Code> MediaLayer_GetInput(MediaLayer* layer);

    // Wrapper function for rendering screen
    static void MediaLayer_GenerateOutput(MediaLayer* layer);

    // Wrapper function for getting delta time
    static double MediaLayer_GetDeltaTime(MediaLayer* layer);

    // --------------------------------------------------

    // Initializes media layer
    virtual bool initialize() =0;

    // Initializes media layer with window dimension, positions window at the center of screen
    virtual bool initialize(std::string title, int window_width, int window_height) =0;

    // Initializes media layer with window dimention and position
    virtual bool initialize(std::string title, int window_width, int window_height, int window_x, int window_y) =0;

    // Shuts down media layer
    virtual void shutdown() =0;

    // Renders output to screen
    virtual void generate_output() =0;

    // Creates and opens window
    virtual bool create_window() =0;

    // Retrieves input from devices
    virtual std::vector<Medialayer_Key_Code> get_input() =0;

    // Calculates delta time
    virtual double get_delta_time() =0;

    // Get pointer to drawing renderer
    virtual MediaLayer_Drawing_Renderer* get_drawing_renderer() =0;

    // --------------------------------------------------

    // Window Width
    int window_width();

    // Window Height
    int window_height();

protected:

    std::string _title;
    int _window_width, _window_height;          // Window size
    int _win_coordinate_x, _win_coordinate_y;   // Coordinate where the window will be created

    int _ticks_count{0};                // For calculating delta time
    const int _ms_per_frame{16};        // For delta time: 60fps = apprx. 1 frame per 16ms
    const double _delta_max{0.05};      // Cap for delta time, in seconds

private:

};
#endif