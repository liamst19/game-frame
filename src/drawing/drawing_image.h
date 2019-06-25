/** drawing_image.h
 *  
 * 
 */

#ifndef DRAWING_IMAGE_H
#define DRAWING_IMAGE_H

#include <string>

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

    class ImageDrawing: public DrawingElement
    {

    public:

        // Constructor
        ImageDrawing(MediaLayer::Drawing_Renderer* renderer, 
                    std::string source_path,
                    int x, int y);

        // Constructor
        ImageDrawing(MediaLayer::Drawing_Renderer* renderer, 
                    std::string source_path,
                    DrawingElement::Position position);

        // Destructor
        ~ImageDrawing();

        // Renders text to screen
        bool render() override;

        // Location of font file
        std::string image_source_path();

        // Set location of image file
        void set_image_source(std::string source_path);

        // Image position
        DrawingElement::Position position();

        // Set image position
        void set_position(DrawingElement::Position position);
    
        // Index for referring back to cache of textures.
        //   -- But is this necessary to be public?
        int texture_index();

    private:

        std::string _source_path;
        DrawingElement::Position _position;

        // Index for referring back to cache
        int _texture_index;

        // Initialize Image Object
        void _initialize();

        // Initialize texture in renderer
        void _initialize_texture();

    };

} // namespace Drawing
#endif
