set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

FILE(GLOB TEST_SOURCES ${TEST_DIR}/*.test.cpp)
FILE(GLOB TEST_MOCK_SOURCES ${TEST_DIR}/mock/*.hpp)
add_executable(game-test ${TEST_SOURCES})

# Linking library from CMakeLists in ~/src
target_link_libraries(game-test lib-game)
target_link_libraries(game-test lib-util)
target_link_libraries(game-test lib-medialayer)
target_link_libraries(game-test lib-gameobject)
target_link_libraries(game-test lib-ui)
target_link_libraries(game-test lib-drawing)

# ----------------------------------------------------------------------
# Testing
# ----------------------------------------------------------------------
# Google Test
# ----------------------------------------------------------------------

# Download and unpack googletest at configure time
configure_file(${TEST_DIR}/CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# ----------------------------------------------------------------------
# ----------------------------------------------------------------------

# Adding Tests

include(GoogleTest)
target_link_libraries(game-test gtest_main)

gtest_add_tests(TARGET game-test
                TEST_SUFFIX .test.cpp
                TEST_LIST   game-tests)
set_tests_properties(${game-tests} PROPERTIES TIMEOUT 10)
