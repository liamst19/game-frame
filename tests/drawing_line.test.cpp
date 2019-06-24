/** drawing_line.test.cpp
 *
 */

#include <vector>
#include "gtest/gtest.h"

#include "../src/drawing/drawing_line.h"
#include "../src/drawing/drawing_element.h"

#include "mocks/medialayer_mock_drawing_renderer.hpp"

using namespace Drawing;

namespace
{

    TEST(Drawing_Line, Constructor_Ints)
    {
        MediaLayer::Mock_Drawing_Renderer renderer;
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
        MediaLayer::Mock_Drawing_Renderer renderer;
        DrawingElement::Position a{29, 57};
        DrawingElement::Position b{55, 107};
        DrawingElement::Color color{1, 2, 3, 4};
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
        MediaLayer::Mock_Drawing_Renderer renderer;
        LineDrawing line(&renderer, 
                         DrawingElement::Position{100, 100}, 
                         DrawingElement::Position{500, 500}, 
                         DrawingElement::Color{256, 256, 256, 0});
        ASSERT_TRUE(line.render());   
    }

}
