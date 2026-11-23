
cmake_minimum_required(VERSION 3.10)

project(EcosystemSimulation)

file(GLOB_RECURSE PROJ_SRC "src/*.cpp" "src/*.hpp")

if ((NOT DEFINED VCPKG_TARGET_TRIPLET) AND ("${CMAKE_CXX_COMPILER}" MATCHES  g\\+\\+\\.exe) AND (${CMAKE_SIZEOF_VOID_P} EQUAL 4))
    message("Configuration pour MinGW 32")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/SFML/lib/cmake/SFML" CACHE FILEPATH "The directory containing a CMake configuration file for SFML.")
endif()

add_executable(${PROJECT_NAME} ${PROJ_SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)

if (APPLE)
    list(APPEND CMAKE_PREFIX_PATH /opt/homebrew/opt/sfml@2 /usr/local/opt/sfml@2)
endif()
set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2 COMPONENTS system window graphics REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE
        sfml-system
        sfml-window
        sfml-graphics
    )
if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE sfml-main)
endif()
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIR})
