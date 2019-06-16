/** drawing_point.h
 * 
 */

#ifndef DRAWING_POINT_H
#define DRAWING_POINT_H

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

class PointDrawing: public Drawing
{

public:

    // Constructor
    /* Probably would need a reference to an abstract class
     * containing method for rendering point
     */
    PointDrawing(int x, int y, int r, int g, int b, int alpha, MediaLayer_Drawing_Renderer* renderer);

    PointDrawing(Drawing::Point coordinates, Drawing::Color color, MediaLayer_Drawing_Renderer* renderer);

    ~PointDrawing();

    // Renders point to screen
    bool render() override;

    // Coordinates of the point
    Drawing::Point coordinates();

    // X-coordinate of the point
    int x();

    // Y-coordinate of the point
    int y();

    // Render color of the point
    Drawing::Color color();

private:

    Drawing::Point _point_coordinates;

    Drawing::Color _point_color;

};
#endif