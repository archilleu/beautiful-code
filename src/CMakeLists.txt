#---------------------------------------------------------------------------
#CMake minimum required version
cmake_minimum_required (VERSION 2.8)
#---------------------------------------------------------------------------
#look up dir's file, and add to var
aux_source_directory(. DIR_SRC)
#---------------------------------------------------------------------------
#generate test
add_executable(regular_expressions regular_expressions.cc)
add_executable(quit_sort quit_sort.cc)
#---------------------------------------------------------------------------
#add include path
#include_directories(../../thirdpart)
#---------------------------------------------------------------------------
#add lib
#---------------------------------------------------------------------------
#add link lib
#---------------------------------------------------------------------------
#install target 
install(TARGETS regular_expressions DESTINATION ${EXECUTABLE_INSTALL_PATH})
install(TARGETS quit_sort DESTINATION ${EXECUTABLE_INSTALL_PATH})
#---------------------------------------------------------------------------
