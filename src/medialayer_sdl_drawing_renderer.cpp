/** medialayer_sdl_drawing_renderer.cpp
 * 
 *  Collection of functions that render various drawings
 *  Using the SDL library. A pointer to this is attached to the Drawing object
 *  upon its creation, so that they can be rendered by simply calling
 *  render() method.
 * 
 *  SDL2_gfx library is used.
 *  
 *  [SDL2_gfx - Graphics primitives and surface functions for SDL2]
 * 
 * 	  	http://www.ferzkopp.net/Software/SDL2_gfx/Docs/html/index.html
 * 
 *   Reference for SDL2_gfxPrimitives
 * 		http://www.ferzkopp.net/Software/SDL2_gfx/Docs/html/_s_d_l2__gfx_primitives_8h.html
 * 
 */

#include "medialayer_sdl_drawing_renderer.h"
#include <SDL2/SDL.h>
#include "../include/SDL2/SDL2_gfxPrimitives.h"

#include "medialayer_sdl_texture_text.h"

/** Constructor
 */
MediaLayer_SDL_Drawing_Renderer::MediaLayer_SDL_Drawing_Renderer()
{
}

/** Destructor
 */
MediaLayer_SDL_Drawing_Renderer::~MediaLayer_SDL_Drawing_Renderer()
{
    free(); // Free resources, if any
}

/** public function: initialize()
 * 	Assigns SDL_Renderer and SDL_Window for rendering.
 *    @renderer: The rendering object used to output images to screen
 * 	  @window: Pointer to application window
 */
bool MediaLayer_SDL_Drawing_Renderer::initialize(SDL_Renderer* renderer, SDL_Window* window)
{

	_renderer = renderer;
	_window = window;	

	return true;
}

/** public function: free()
 *  Frees resources.
 */
void MediaLayer_SDL_Drawing_Renderer::free()
{
    _renderer = nullptr;
    _window = nullptr;
}

/** public function: render_text
 * Renders text to screen.
 *   @text: text to be printed
 *   @font_src: font source file
 *   @font_size: font size
 *   @x, @y, position of the text
 *   @color: font color
 */
bool MediaLayer_SDL_Drawing_Renderer::render_text(
		std::string text,
		std::string font_src, int font_size,
		int x, int y,
		int r, int g, int b, int alpha)
{
	// This renders text to screen, but perhaps inefficient, and so 
	// should be modified to keep a cache of SDL_Texture pointers
	// and call render() until text content is changed.
	MediaLayer_SDL_Texture_Text texture;
	if(texture.initialize(_renderer, _window))
	{
		texture.load(text, font_src, font_size, SDL_Color{r, g, b, alpha});
		texture.render(x, y);
	}
	else
	{
		// Initialize failed
		return false;
	}

	return true;
}

/** public function: render_point()
 *  Renders single pixel to screen.
 *   @x, @y: Coordinates on the screen to be changed.
 *   @r, @g, @b, @alpha: Color and transparency.
 */
bool MediaLayer_SDL_Drawing_Renderer::render_point(
		int x, int y, 
		int r, int g, int b, int alpha)
{
    return pixelRGBA(_renderer, x, y, r, g, b, alpha) == 0;
}

/** public function: render_line()
 *  Renders line from point a to b.
 *   @aX, @aY, @bX, @bY: Coordinates of the endpoints
 *   @r, @g, @b, @alpha: Color and transparency values
 *   @thickness: Line thickness [To be implemented]
 */
bool MediaLayer_SDL_Drawing_Renderer::render_line(
		int aX, int aY, 
		int bX, int bY, 
		int r, int g, int b, int alpha, 
		int thickness)
{
	int result = 0;
	if(thickness > 1)
	{
		result |= thickLineRGBA(_renderer, aX, aY, bX, bY, thickness, r, g, b, alpha);
	}
	else
	{
		result |= lineRGBA(_renderer, aX, aY, bX, bY, r, g, b, alpha);
	}
	return result == 0;
}

/** public function: render_rectangle()
 *  Renders rectangle.
 * 	  @x1, @y1, @x2, @y2: Coordinates of the rectangle to be rendered.
 * 	  @r, @g, @b, @alpha: Color in RGB and transparency
 *    @fill: Renders solid shape if true, outline if false.
 */
bool MediaLayer_SDL_Drawing_Renderer::render_rectangle(
		int x1, int y1, 
		int x2, int y2, 
		int r, int g, int b, int alpha, 
		bool fill)
{
	int result = 0;

	if(fill)
	{
		result = boxRGBA(_renderer, x1, y1, x2, y2, r, g, b, alpha);
	}
	else
	{
		result = rectangleRGBA(_renderer, x1, y1, x2, y2, r, g, b, alpha);
	}

	return result == 0;
}

/** public function: render_circle()
 * Renders circle.
 *   @x, @y: Coordinates of the center
 *   @radius: Radius of circle
 * 	 @r, @g, @b, alpha: Color and transparency
 *   @fill: Renders shape in solid color if true, outline if false.
 */
bool MediaLayer_SDL_Drawing_Renderer::render_circle(
			int centerX, int centerY, 
			int radius, 
			int r, int g, int b, int alpha, 
			bool fill)
{
	int result = 0;
	if(fill)
	{
		result = filledCircleRGBA(_renderer, centerX, centerY, radius, r, g, b, alpha);
	}
	else
	{
		result = circleRGBA(_renderer, centerX, centerY, radius, r, g, b, alpha);
	}
	return result == 0;
}

/** public function: render_ellipse()
 * Renders ellipse.
 *   @x, @y: Coordinates of the center
 *   @radiusX, radiusY: Horizontal and vertical radii, respectively
 * 	 @r, @g, @b, alpha: Color and transparency
 *   @fill: Renders shape in solid color if true, outline if false.
 */
bool MediaLayer_SDL_Drawing_Renderer::render_ellipse(
			int x, int y,
            int radiusX, int radiusY, 
			int r, int g, int b, int alpha, 
			bool fill)
{
	int result = 0;
	if(fill)
	{
		result = filledEllipseRGBA(_renderer, x, y, radiusX, radiusY, r, g, b, alpha);
	}
	else
	{
		result = ellipseRGBA(_renderer, x, y, radiusX, radiusY, r, g, b, alpha);
	}
	return result == 0;
}