set( CMAKE_INCLUDE_CURRENT_DIR ON )

include_directories( ${PROJECT_SRC_DIR}/include )

set( TESTAPPS basic two double )

foreach( APP ${TESTAPPS} )
    add_executable( ${APP} "${APP}.cpp" )
    target_link_libraries( ${APP} cmdargs )
    add_test( NAME "${APP}_test" COMMAND ${APP} )
endforeach( APP ${TESTAPPS} )
