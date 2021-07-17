cmake_minimum_required( VERSION 3.0 FATAL_ERROR )
project( cmdargs )
set( version 1.1 )
set( CMAKE_INCLUDE_CURRENT_DIR ON )

##
# for submodules, this needs to be reset to avoid
# preferencing parent module paths.
##
set( CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

include( CheckSTD )

include_directories( ${PROJECT_SOURCE_DIR}/include )

add_subdirectory( lib )
add_subdirectory( include )

enable_testing()
add_subdirectory( testsuite )
##
# assuming WIN32 doesn't care about pkg-config
##
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
    message( WARNING "You should set ${RED}PKG_CONFIG_PATH=${CMAKE_INSTALL_PREFIX}/pkgconfig/:$PKG_CONFIG_PATH ${ColourReset} when installing to non-standard prefix for pkg-config to work correctly!" )
else()
    message( STATUS "Setting PKG_CONFIG_PATH to: ${PKG_CONFIG_PATH}" )
endif()

configure_file( "cmdargs.pc.in" "cmdargs.pc" @ONLY )
install( FILES ${CMAKE_CURRENT_BINARY_DIR}/cmdargs.pc DESTINATION ${CMAKE_INSTALL_PREFIX}/pkgconfig/ )

endif( NOT WIN32 )
