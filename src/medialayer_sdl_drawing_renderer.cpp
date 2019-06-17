/** medialayer_sdl_drawing_renderer.cpp
 * 
 *  Collection of functions that render various drawings
 *  Using the SDL library. A pointer to this is attached to the Drawing object
 *  upon its creation, so that they can be rendered by simply calling
 *  render() method.
 * 
 *  Use of the SDL2_gfx library was preferred, but I could not get it to work,
 *  and so, much of the code here for rendering shapes are borrowed from its source code.
 *  
 *  [SDL2_gfx - Graphics primitives and surface functions for SDL2]
 * 	  http://www.ferzkopp.net/Software/SDL2_gfx/Docs/html/index.html
 * 
 */

#include "medialayer_sdl_drawing_renderer.h"
#include <SDL2/SDL.h>

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

/** private function: _set_color()
 *  Sets color and blend mode for whatever is about to be rendererd.
 *    @r, @g, @b: Color of the pixels
 *    @alpha: Transparency
 */
int MediaLayer_SDL_Drawing_Renderer::_set_color(int r, int g, int b, int alpha)
{
	int result = 0;
	result |= SDL_SetRenderDrawBlendMode(_renderer, (alpha == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND);
	result |= SDL_SetRenderDrawColor(_renderer, r, g, b, alpha);
	return result;
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
    int result = 0;
	result |= _set_color(r, g, b, alpha);
	result |= SDL_RenderDrawPoint(_renderer, x, y);
    return result == 0;
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
	result |= _set_color(r, g, b, alpha);	
	result |= SDL_RenderDrawLine(_renderer, aX, aY, bX, bY);
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
	int tmp; // For swapping
	SDL_Rect rect;

	// Test for special cases of straight lines or single point 
	if (x1 == x2) {
		if (y1 == y2) {
			return (render_point(x1, y1, r, g, b, alpha));
		} else {
			return (render_line(x1, y1, x2, y2, r, g, b, alpha));
		}
	} else {
		if (y1 == y2) {
			return (render_line(x1, y1, x2, y2, r, g, b, alpha));
		}
	}

	// Swap x, x2 if required 
	if (x1 > x2) {
		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}

	// Swap y, y2 if required 
	if (y1 > y2) {
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	// Create destination rect
	rect.x = x1;
	rect.y = y1;
	rect.w = x2 - x1;
	rect.h = y2 - y1;
	
	// Draw
	result = 0;
	result |= _set_color(r, g, b, alpha);	
	
	if(fill)
	{
		result |= SDL_RenderFillRect(_renderer, &rect);
	}
	else
	{
		result |= SDL_RenderDrawRect(_renderer, &rect);
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
    return render_ellipse(centerX, centerY, radius, radius, r, g, b, alpha); 
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
	// Currently, for outlined ellipse, each point is rendered with 
	// SDL_RenderDrawPoint(). But it may be more efficient to bundle all 
	// the points into an array of SDL_Point objects, and call a single
	// SDL_DrawPoints() at the end.
	//
	// Likewise, for filled ellipse, perhaps there is an algorithm which
	// fills an ellipse by sequencially rendering rectangles of decreasing
	// size. I'm not sure how it compares to the current method of rendering
	// lines.
	//
	// In either case, this is an optimization problem which is unnecessary
	// for whatever this object might come to be used for.

	// Radii less than zero is not a shape
	if (radiusX < 0 || radiusY < 0)
	{
		return false;
	}

	// Special cases for horizontal/vertical line, or single point
	if(radiusX == 0)
	{
		if(radiusY == 0)
		{
			return render_point(x, y, r, g, b, alpha);
		} else
		{
			return render_line(x, y - radiusY, x, y + radiusY, r, g, b, alpha); // vertical line
		}
	} 
	else if(radiusY == 0)
	{
		return render_line(x - radiusX, y, x + radiusX, y, r, g, b, alpha); // horizontal line
	}

	// -------------------------------------------------

    int result = 0;

	// Set Color
	result |= _set_color(r, g, b, alpha);	

	// --------------------------------------------------

	int rXi, rYi;
	int rx2, ry2, rx22, ry22; 
    int error;
    int curX, curY, curXp1, curYm1;	// Curve coordinates
	int scrX, scrY, oldX, oldY; 	// Screen coordinates
    int deltaX, deltaY;
	int ellipseOverscan;

	rXi = radiusX;
	rYi = radiusY;

	// adjust overscan
	ellipseOverscan = _ellipse_adjust_overscan(rXi, rYi);

	// Top/bottom center points
	oldX = scrX = 0;
	oldY = scrY = rYi;
	result |= _ellipse_draw_quadrants(x, y, 0, radiusY, fill);

	// Midpoint ellipse algorithm with overdraw
	rXi *= ellipseOverscan;
	rYi *= ellipseOverscan;
	rx2 = rXi * rXi;
	rx22 = rx2 + rx2;
    ry2 = rYi * rYi;
	ry22 = ry2 + ry2;
    curX = 0;
    curY = rYi;
    deltaX = 0;
    deltaY = rx22 * curY;

	// Points in segment 1 
    error = ry2 - rx2 * rYi + rx2 / 4;
    while (deltaX <= deltaY)
    {
		// Passing deltaX by reference
		result |= _ellipse_draw_segment_1(
					error,
					deltaX, deltaY, scrX, scrY,
					curX, curY, oldX, oldY,
					x, y, rx2, ry2, rx22, ry22,
					ellipseOverscan, fill);
    }

	// Points in segment 2
	if (curY > 0) 
	{
		curXp1 = curX + 1;
		curYm1 = curY - 1;
		error = ry2 * curX * curXp1 + ((ry2 + 3) / 4) + rx2 * curYm1 * curYm1 - rx2 * ry2;
		while (curY > 0)
		{
			// Passing curY by reference
			result |= _ellipse_draw_segment_2(
						error,
						deltaX, deltaY, scrX, scrY,
						curX, curY, oldX, oldY,
						x, y, rx2, ry2, rx22, ry22,
						ellipseOverscan, fill);
		}

		/* Remaining points in vertical */
		if (!fill)
		{
			oldY--;
			for (;oldY >= 0; oldY--)
			{
				result |= _ellipse_draw_quadrants(x, y, scrX, oldY, fill);
			}
		}
	}

    return result == 0;
}

/** private function: _ellipse_adjust_overscan
 * 	Calculates the ellipse's overscan according to its radii
 *    @rXi, @rYi: 
 */
int MediaLayer_SDL_Drawing_Renderer::_ellipse_adjust_overscan(int rXi, int rYi)
{
	const int default_ellipse_overscan = 4;

	if(rXi >= 512 || rYi >= 512)
	{
		return default_ellipse_overscan / 4;
	} 
	else if(rXi >= 256 || rYi >= 256)
	{
		return default_ellipse_overscan / 2;
	} 
	else
	{
		return default_ellipse_overscan;
	}	
}

/** private function: _ellipse_draw_quadrants()
 *  Actual rendering of the ellipse. Since ellipse is made 
 *  up of four symmetric quadrants, it is more efficient to render
 *  four points at a time.
 * 
 * 	In the current state the ellipse is axis-aligned.
 * 
 * 	  @x, @y: coordinates of one point on the ellipse's quadrant.
 * 	  @dx, @dy: slopes for calculating symmetry
 * 	  @fill: draws a line for solid shape if true, points for outline if false
 */
int MediaLayer_SDL_Drawing_Renderer::_ellipse_draw_quadrants(int x, int y, int dx, int dy, bool fill)
{
	int result = 0;
	int xpdx, xmdx;
	int ypdy, ymdy;

	// Horizontal
	if (dx == 0) {
		if (dy == 0) {
			result |= SDL_RenderDrawPoint(_renderer, x, y);
		} else {
			ypdy = y + dy;
			ymdy = y - dy;
			if (fill) {
				result |= SDL_RenderDrawLine(_renderer, x, ymdy, x, ypdy);
			} else {
				result |= SDL_RenderDrawPoint(_renderer, x, ypdy);
				result |= SDL_RenderDrawPoint(_renderer, x, ymdy);
			}
		}
	} else {	
		xpdx = x + dx;
		xmdx = x - dx;
		ypdy = y + dy;
		ymdy = y - dy;
		if (fill) {
				result |= SDL_RenderDrawLine(_renderer, xpdx, ymdy, xpdx, ypdy);
				result |= SDL_RenderDrawLine(_renderer, xmdx, ymdy, xmdx, ypdy);
		} else {
				result |= SDL_RenderDrawPoint(_renderer, xpdx, ypdy);
				result |= SDL_RenderDrawPoint(_renderer, xmdx, ypdy);
				result |= SDL_RenderDrawPoint(_renderer, xpdx, ymdy);
				result |= SDL_RenderDrawPoint(_renderer, xmdx, ymdy);
		}
	}
	return result;
}

/** private function: _ellipse_draw_segment_1()
 * 	Draws the first segment of an ellipse
 */
int MediaLayer_SDL_Drawing_Renderer::_ellipse_draw_segment_1(
		int& error,
		int& deltaX, int& deltaY,
		int& scrX, int& scrY,
		int& curX, int& curY, int& oldX, int& oldY,
		int x, int y,
		int rx2, int ry2, int rx22, int ry22,
		int ellipseOverscan,
		bool fill)
{
	int result;	

	curX++;
	deltaX += ry22;

	error +=  deltaX + ry2; 
	if (error >= 0)
	{
		curY--;
		deltaY -= rx22; 
		error -= deltaY;
	}

	scrX = curX / ellipseOverscan;
	scrY = curY / ellipseOverscan;
	if ((scrX != oldX && scrY == oldY) || (scrX != oldX && scrY != oldY)) 
	{
		result |= _ellipse_draw_quadrants(x, y, scrX, scrY, fill);
		oldX = scrX;
		oldY = scrY;
	}

	return result;
}		

/** private function: _ellipse_draw_segment_2()
 * 	Draws the second segment of an ellipse
 */
int MediaLayer_SDL_Drawing_Renderer::_ellipse_draw_segment_2(
		int& error,
		int& deltaX, int& deltaY,
		int& scrX, int& scrY,
		int& curX, int& curY,
        int& oldX, int& oldY,
		int x, int y,
		int rx2, int ry2, int rx22, int ry22,
		int ellipseOverscan,
		bool fill)
{
	int result;

	curY--;
	deltaY -= rx22;

	error += rx2;
	error -= deltaY;

	if (error <= 0) 
	{
		curX++;
		deltaX += ry22;
		error += deltaX;
	}

	scrX = curX / ellipseOverscan;
	scrY = curY / ellipseOverscan;
	if ((scrX != oldX && scrY == oldY) || (scrX != oldX && scrY != oldY))
	{
		oldY--;
		for (;oldY >= scrY; oldY--)
		{
			result |= _ellipse_draw_quadrants(x, y, scrX, oldY, fill);
			// prevent overdraw
			if (fill)
			{
				oldY = scrY - 1;
			}
		}
		oldX = scrX;
		oldY = scrY;
	}		

	return result;
}
