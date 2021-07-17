cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(affinity)
set( version 1.1 )
set( CMAKE_INCLUDE_CURRENT_DIR ON )

find_package( Threads )



##
# AFFINITY_CUSTOM_NAMESPACE - set to true if you want
# to inject a custom namespace. 
##
mark_as_advanced( AFFINITY_CUSTOM_NAMESPACE )

if( NOT DEFINED AFFINITY_CUSTOM_NAMESPACE )
set( AFFINITY_CUSTOM_NAMESPACE false CACHE BOOL "Wrap the affinity call in a custom namespace using -DAFFINITY_NAMESPACE=\"namespace\" when configuring cmake." )
endif() 

##
# AFFINITY_NAMESPACE - set to actual name you want to 
# inject. 
##
mark_as_advanced( AFFINITY_NAMESPACE )

if( NOT DEFINED AFFINITY_NAMESPACE )
set( AFFINITY_NAMESPACE "" CACHE STRING "Namespace to inject" )
endif()

if( AFFINITY_CUSTOM_NAMESPACE )
message (STATUS "Injecting the following namespace into your libaffinity build: ${AFFINITY_NAMESPACE}" )
add_definitions( "-DINJECT_AFFINITY_NAMESPACE=1" )
add_definitions( "-DAFFINITY_NAMESPACE=${AFFINITY_NAMESPACE}" )
endif( AFFINITY_CUSTOM_NAMESPACE )

include_directories ( ${PROJECT_SOURCE_DIR} )
include_directories ( ${PROJECT_SOURCE_DIR}/include )
add_subdirectory( src )
add_subdirectory( include )


set( BUILD_TESTS true CACHE BOOL "Build test cases" ) 
mark_as_advanced( BUILD_TESTS )

##
# Set up unit tests
##
if( BUILD_TESTS AND NOT WIN32 AND NOT APPLE )
enable_testing()
add_subdirectory( testsuite )
endif()

if( NOT WIN32 )
##
# make and setup pkg-config
##
mark_as_advanced( PKG_CONFIG_PATHWAY )
set( PKG_CONFIG_PATH "" CACHE STRING "Set the pkg-config path, othwerwise will figure out" )
if( NOT PKG_CONFIG_PATH )
execute_process( COMMAND  pkg-config --variable pc_path pkg-config 
                 COMMAND  tr ':' '\n' 
                 COMMAND  head -n 1
                 OUTPUT_VARIABLE LOCAL_PKG_CONFIG_PATHWAY )
set( PKG_CONFIG_PATH ${LOCAL_PKG_CONFIG_PATHWAY} )
endif()

string(REPLACE ":" ";" PREFIX_LIST "${CMAKE_SYSTEM_PREFIX_PATH}")
list(FIND PREFIX_LIST ${CMAKE_INSTALL_PREFIX}  _index)

if(${_index} GREATER 0)
    file( MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/pkgconfig ) 
    set( PKG_CONFIG_PATH ${CMAKE_INSTALL_PREFIX}/pkgconfig )
    message( WARNING "You should set PKG_CONFIG_PATH=${CMAKE_INSTALL_PREFIX}/pkgconfig/:$PKG_CONFIG_PATH when installing to non-standard prefix for pkg-config to work correctly!" )
else()
    message( STATUS "Setting PKG_CONFIG_PATH to: ${PKG_CONFIG_PATH}" )
endif()



configure_file( "affinity.pc.in" "affinity.pc" @ONLY )
install( FILES ${CMAKE_CURRENT_BINARY_DIR}/affinity.pc DESTINATION ${CMAKE_INSTALL_PREFIX}/pkgconfig/ )
endif()
