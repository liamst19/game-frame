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
# FreeType 

find_package(Freetype REQUIRED)

include_directories(${FREETYPE_INCLUDE_DIRS})

# -----------------------------------------------------
# External libraries

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

# -----------------------------------------------------
# Project Sources

# Gather headers
FILE(GLOB GAME_HEADERS 
          ${SRC_DIR}/*.h
     )
# Gather sources
FILE(GLOB GAME_SOURCES
          ${SRC_DIR}/*.cpp
     )
LIST(REMOVE_ITEM GAME_SOURCES ${SRC_DIR}/main.cpp) # Remove main.cpp

#Add library
add_library(lib-game ${GAME_SOURCES} ${GAME_HEADERS})

# -----------------------------------------------------

# Executable
add_executable(game WIN32 ${SRC_DIR}/main.cpp)

# Link dependencies to executable
target_link_libraries(game lib-game)

# SDL2
target_link_libraries(game SDL2_gfx) # SDL_gfx needs to come before core SDL2, apparently
target_link_libraries(game ${SDL2_TTF_LIBRARIES})
target_link_libraries(game ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(game ${SDL2_LIBRARIES})

# FreeType
target_link_libraries(game ${FREETYPE_LIBRARIES})