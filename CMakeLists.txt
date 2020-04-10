cmake_minimum_required(VERSION 2.17)

project(nier)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)

set(CMAKE_CXX_STANDAED 17)

add_subdirectory(external)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/tinyxml2
)

set( CMAKE_INSTALL_PREFIX ../ )

add_executable(
    nier

    # Header files
    include/nier/main.h
    include/nier/scene.h
    include/nier/common.h
    include/nier/parser.h
    include/nier/object.h
    include/nier/automata.h
    include/nier/set.h
    include/nier/transition.h
    include/nier/language.h

    # Source files
    src/main.cpp
    src/scene.cpp
    src/common.cpp
    src/parser.cpp
    src/object.cpp
    src/set.cpp
    src/transition.cpp
    src/language.cpp
    src/automata_dfa.cpp
)

target_link_libraries(nier tinyxml2)
