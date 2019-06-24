/** drawing.test.cpp
 * 
 */

#include <vector>
#include "gtest/gtest.h"
#include "../src/drawing/drawing_factory.h"
#include "../src/drawing/drawing_element.h"

#include "../src/drawing/drawing_point.h"
#include "../src/drawing/drawing_line.h"
// #include "../src/drawing/drawing_ellipse.h"
// #include "../src/drawing/drawing_polygon.h"
// #include "../src/drawing/drawing_rectangle.h"

// Mock Object
#include "mocks/medialayer_mock.hpp"
#include "mocks/medialayer_mock_drawing_renderer.hpp"

using namespace Drawing;

namespace
{
    TEST(DrawingFactory_Test, Constructor)
    {
        MediaLayer::Mock_Drawing_Renderer renderer; // MediaLayer will contain functions for rendering

        // Create factory
        DrawingFactory factory{&renderer}; 

        // Create opaque white point 
        PointDrawing drawing = factory.getPoint(50, 50, 255, 255, 255, 0);
        ASSERT_TRUE(drawing.render());
    }

    TEST(DrawingFactory_Test, Point)
    {
        MediaLayer::Mock_Drawing_Renderer renderer; // MediaLayer will contain functions for rendering

        // Create factory
        DrawingFactory factory{&renderer}; 

        // Create opaque white point 
        PointDrawing point = factory.getPoint(50, 60, 255, 255, 255, 0);
        ASSERT_EQ(50, point.x());
        ASSERT_EQ(60, point.y());
        ASSERT_TRUE(point.render());
    }

    TEST(DrawingFactory_Test, Line)
    {
        MediaLayer::Mock_Drawing_Renderer renderer; // MediaLayer will contain functions for rendering

        // Create factory
        DrawingFactory factory{&renderer}; 

        // Create opaque white point 
        LineDrawing line = factory.getLine(50, 55, 60, 65, 255, 255, 255, 0);
        ASSERT_EQ(50, line.a().x);
        ASSERT_EQ(55, line.a().y);
        ASSERT_EQ(60, line.b().x);
        ASSERT_EQ(65, line.b().y);
        ASSERT_TRUE(line.render());
    }

    TEST(DrawingFactory_Test, Rectangle)
    {

    }

    TEST(DrawingFactory_Test, Ellipse)
    {

    }
}
