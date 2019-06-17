/** drawing.test.cpp
 * 
 */

#include <vector>
#include "gtest/gtest.h"

#include "../src/drawing_point.h"
#include "../src/drawing.h"

#include "mocks/medialayer_mock_drawing_renderer.hpp"

namespace
{

    TEST(Drawing_Point, Constructor_Ints)
    {
        MediaLayer_Mock_Drawing_Renderer renderer;
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
        MediaLayer_Mock_Drawing_Renderer renderer;
        Drawing::Point crd{29, 57};
        Drawing::Color color{1, 2, 3, 4};
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
        MediaLayer_Mock_Drawing_Renderer renderer;
        PointDrawing point(&renderer, Drawing::Point{100, 100}, Drawing::Color{256, 256, 256, 0});
        ASSERT_TRUE(point.render());   
    }

}