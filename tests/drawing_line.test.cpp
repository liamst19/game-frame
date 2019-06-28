/** drawing_line.test.cpp
 *
 */

#include <vector>
#include "gtest/gtest.h"

#include "../src/drawing/drawing_line.h"
#include "../src/drawing/drawing.h"

#include "mocks/medialayer_mock_drawing_renderer.hpp"

using namespace Drawing;

namespace
{
    MediaLayer::Mock_Drawing_Renderer renderer;

    TEST(Drawing_Line, Constructor_Ints)
    {
        LineDrawing line{&renderer, 0, 1, 2, 3, 4, 5, 6, 7};
        
        ASSERT_EQ(0, line.a().x);
        ASSERT_EQ(1, line.a().y);
        ASSERT_EQ(2, line.b().x);
        ASSERT_EQ(3, line.b().y);
        ASSERT_EQ(4, line.color().r);
        ASSERT_EQ(5, line.color().g);
        ASSERT_EQ(6, line.color().b);
        ASSERT_EQ(7, line.color().alpha);
    };
    
    TEST(Drawing_Line, Constructor_Structs)
    {
        Drawing::Position a{29, 57};
        Drawing::Position b{55, 107};
        Drawing::Color color{1, 2, 3, 4};
        LineDrawing line{&renderer, a, b, color};

        ASSERT_EQ(29, line.a().x);
        ASSERT_EQ(57, line.a().y);
        ASSERT_EQ(55, line.b().x);
        ASSERT_EQ(107, line.b().y);
        ASSERT_EQ(1, line.color().r);
        ASSERT_EQ(2, line.color().g);
        ASSERT_EQ(3, line.color().b);
        ASSERT_EQ(4, line.color().alpha);
    }

    TEST(Drawing_Line, Render)
    {
        LineDrawing line(&renderer, 
                         Drawing::Position{100, 100}, 
                         Drawing::Position{500, 500}, 
                         Drawing::Color{256, 256, 256, 0});
        ASSERT_TRUE(line.render());   
    }

}
