add_library(lib-medialayer
  medialayer.h                        medialayer.cpp
  medialayer_drawing_renderer.h       medialayer_drawing_renderer.cpp 
  )

add_library(lib-medialayer-sdl
  medialayer_sdl.h                    medialayer_sdl.cpp
  medialayer_sdl_drawing_renderer.h   medialayer_sdl_drawing_renderer.cpp 
  medialayer_sdl_texture.h            medialayer_sdl_texture.cpp 
  medialayer_sdl_texture_drawing.h    medialayer_sdl_texture_drawing.cpp 
  medialayer_sdl_texture_image.h      medialayer_sdl_texture_image.cpp 
  medialayer_sdl_texture_text.h       medialayer_sdl_texture_text.cpp 
  )
