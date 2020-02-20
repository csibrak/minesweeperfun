cmake_minimum_required(VERSION 2.8)
project( minesweeperfun )
#find_package( OpenCV REQUIRED )
#add_subdirectory( src )
#include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( minesweeperfun main.cpp )
target_link_libraries( minesweeperfun \
#${OpenCV_LIBS} 
)
