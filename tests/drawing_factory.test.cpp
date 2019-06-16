/** drawing.test.cpp
 * 
 */

#include <vector>
#include "gtest/gtest.h"
#include "../src/drawing_factory.h"
#include "../src/drawing.h"

// Mock Object
#include "mocks/medialayer_mock.hpp"

namespace
{
    TEST(DrawingFactory_Test, Constructor)
    {
        MediaLayer_Mock medialayer; // MediaLayer will contain functions for rendering

        // Create factory
        DrawingFactory factory{&medialayer}; 

        // Create opaque white point 
        PointDrawing drawing = factory.getPoint(50, 50, 255, 255, 255, 0);

    }
}