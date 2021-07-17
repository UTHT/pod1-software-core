set( MAINHEADER cmd )
file( GLOB_RECURSE SUBHEADERS ${PROJECT_SOURCE_DIR}/include/cmdargs/* )

install( FILES ${MAINHEADER} 
         DESTINATION ${CMAKE_INSTALL_PREFIX}/include )
##
# make subdir
##
set( SUBDIR ${CMAKE_INSTALL_PREFIX}/include/cmdargs )
install( DIRECTORY DESTINATION ${SUBDIR} )
foreach( F ${SUBHEADERS} )
    install( FILES ${F} 
             DESTINATION ${SUBDIR} )
endforeach( F ${SUBHEADERS} )
