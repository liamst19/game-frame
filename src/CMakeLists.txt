set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# Copy assets to the compilation directory
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

# -----------------------------------------------------
# SDL Library

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

find_package(SDL2       REQUIRED)
find_package(SDL2_ttf   REQUIRED)
find_package(SDL2_image REQUIRED)

find_library(SDL2TTF_LIBRARIES   SDL_ttf)
find_library(SDL2IMAGE_LIBRARIES SDL_image)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# -----------------------------------------------------
# External libraries

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

# -----------------------------------------------------
# Project Sources

# # Gather headers
# FILE(GLOB GAME_HEADERS 
#           ${SRC_DIR}/*.h
#      )
# # Gather sources
# FILE(GLOB GAME_SOURCES
#           ${SRC_DIR}/*.cpp
#      )
# LIST(REMOVE_ITEM GAME_SOURCES ${SRC_DIR}/main.cpp) # Remove main.cpp
#
# #Add library
# add_library(lib-game ${GAME_SOURCES} ${GAME_HEADERS})

add_library(lib-game
     game.h                              game.cpp
     math.h                              math.cpp
     math_vector_2d.h                    math_vector_2d.cpp
     randomnumber.h                      randomnumber.cpp
)

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

add_library(lib-ui
     ui.h                                ui.cpp
     ui_element.h                        ui_element.cpp
     ui_element_clock.h                  ui_element_clock.cpp
)

add_library(lib-drawing
     drawing.h                           drawing.cpp
     drawing_factory.h                   drawing_factory.cpp
     drawing_element.h                   drawing_element.cpp
     drawing_text.h                      drawing_text.cpp
     drawing_image.h                     drawing_image.cpp
     drawing_point.h                     drawing_point.cpp
     drawing_line.h                      drawing_line.cpp
     drawing_rectangle.h                 drawing_rectangle.cpp
     drawing_ellipse.h                   drawing_ellipse.cpp
     drawing_polygon.h                   drawing_polygon.cpp
)

# -----------------------------------------------------

# Executable
add_executable(game WIN32 ${SRC_DIR}/main.cpp)

# Link dependencies to executable
target_link_libraries(game lib-game)
target_link_libraries(game lib-medialayer)
target_link_libraries(game lib-medialayer-sdl)
target_link_libraries(game lib-ui)
target_link_libraries(game lib-drawing)

# SDL2
target_link_libraries(game SDL2_gfx) # SDL_gfx needs to come before core SDL2, apparently
target_link_libraries(game ${SDL2_TTF_LIBRARIES})
target_link_libraries(game ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(game ${SDL2_LIBRARIES})

# FreeType
target_link_libraries(game ${FREETYPE_LIBRARIES})