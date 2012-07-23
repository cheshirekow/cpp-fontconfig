find_package(Fontconfig REQUIRED)
                                                                    
include_directories( 
    ${Fontconfig_INCLUDE_DIRS}
    )


set(LIBS ${LIBS} 
    ${CMAKE_PROJECT_NAME} 
    ${Fontconfig_LIBRARIES}
    )
 
add_executable( tutorial tutorial.cpp )

target_link_libraries( tutorial ${LIBS} )
 
