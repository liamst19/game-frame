/** drawig.h
 * 
 */

#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include <memory>
#include "drawing_element.h"

namespace Drawing{
    
    class Drawing{
    public:

        // Constructor
        Drawing();

        // Destructor
        ~Drawing();

        // Add drawing element
        void add_drawing_element(std::unique_ptr<DrawingElement> element);

        // Render Drawing
        void render();

    private:

        std::vector<std::unique_ptr<DrawingElement>> _drawing_elements;

    };
    
} // namespace Drawing
#endif
