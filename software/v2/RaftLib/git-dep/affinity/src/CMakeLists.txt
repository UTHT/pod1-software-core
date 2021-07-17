set( CMAKE_INCLUDE_CURRENT_DIR ON )

add_library( affinity affinity.cpp )

if (NOT WIN32)
  target_link_libraries( affinity PUBLIC ${CMAKE_THREAD_LIBS_INIT} )
endif()

install( TARGETS affinity
         ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib )
