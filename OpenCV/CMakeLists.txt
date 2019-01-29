cmake_minimum_required(VERSION 2.8)
project( testopen )
find_package( OpenCV REQUIRED )
add_executable( testopen testopen.cpp )
target_link_libraries( testopen ${OpenCV_LIBS} )

