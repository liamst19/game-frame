/** drawing.test.cpp
 * 
 */

#include <vector>
#include "gtest/gtest.h"

#include "../src/drawing/drawing_point.h"
#include "../src/drawing/drawing_element.h"

#include "mocks/medialayer_mock_drawing_renderer.hpp"

namespace
{

    TEST(Drawing_Point, Constructor_Ints)
    {
        MediaLayer::Mock_Drawing_Renderer renderer;
        PointDrawing point{&renderer, 0, 0, 0, 0, 0, 0};
        
        ASSERT_EQ(0, point.x());
        ASSERT_EQ(0, point.y());
        ASSERT_EQ(0, point.color().r);
        ASSERT_EQ(0, point.color().g);
        ASSERT_EQ(0, point.color().b);
        ASSERT_EQ(0, point.color().alpha);
    };
    
    TEST(Drawing_Point, Constructor_Structs)
    {
        MediaLayer::Mock_Drawing_Renderer renderer;
        DrawingElement::Position crd{29, 57};
        DrawingElement::Color color{1, 2, 3, 4};
        PointDrawing point{&renderer, crd, color};

        ASSERT_EQ(29, point.x());
        ASSERT_EQ(57, point.y());
        ASSERT_EQ(1, point.color().r);
        ASSERT_EQ(2, point.color().g);
        ASSERT_EQ(3, point.color().b);
        ASSERT_EQ(4, point.color().alpha);
    };

    TEST(Drawing_Point, Render)
    {
        MediaLayer::Mock_Drawing_Renderer renderer;
        PointDrawing point(&renderer, DrawingElement::Position{100, 100}, DrawingElement::Color{256, 256, 256, 0});
        ASSERT_TRUE(point.render());   
    }

}
