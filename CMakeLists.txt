cmake_minimum_required(VERSION 3.22)
project(
    first_raylibcpp_gaem
    VERSION 0.1.0 
    LANGUAGES CXX
)

##########################################################################
# Add dependencies with FetchContent
##########################################################################
include(FetchContent)
function(add_git_dependency libName gitURL gitTag)
    set(FETCHCONTENT_QUIET FALSE)
    FetchContent_Declare(${libName}
        GIT_REPOSITORY ${gitURL}
        GIT_TAG        ${gitTag}
        GIT_SHALLOW    TRUE
        GIT_PROGRESS   TRUE
    )
    FetchContent_MakeAvailable(${libName})
endfunction()

# Add Raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
    add_git_dependency(
        raylib
        https://github.com/raysan5/raylib.git
        4.5.0
    )
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    add_git_dependency(
        raylib_cpp
        https://github.com/RobLoach/raylib-cpp.git
        v4.5.1
    )
    # target_compile_options(raylib_cpp PRIVATE "-w")
endif()

find_package(EnTT QUIET)
if (NOT EnTT_FOUND)
    add_git_dependency(
        EnTT
        https://github.com/skypjack/entt.git
        v3.12.2
    )
endif()

##########################################################################
# Add executables and setup the project stuff
##########################################################################
# Adding our source files
# Define PROJECT_SOURCES as a list of all source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
# Define PROJECT_INCLUDE to be the path to the include directory of the project
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib_cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE EnTT)
