set( CMAKE_INCLUDE_CURRENT_DIR ON )

add_library( demangle demangle.cpp )

install( TARGETS demangle
         ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib )
