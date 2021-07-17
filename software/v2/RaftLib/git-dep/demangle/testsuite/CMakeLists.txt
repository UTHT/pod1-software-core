list( APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake )
set( CMAKE_INCLUDE_CURRENT_DIR ON )

if( NOT WIN32 )
set( OPTIONAL simple )
else()
set( OPTIONAL "" )
endif()

set( TESTAPPS #list apps
        ${OPTIONAL}
        stringdemangle
    )


foreach( APP ${TESTAPPS} )
 add_executable( "${APP}_demangle" "${APP}.cpp" )
 target_link_libraries( "${APP}_demangle" demangle )
 add_test( NAME "${APP}_demangle_test" COMMAND "${APP}_demangle" )
endforeach( APP ${TESTAPPS} )
