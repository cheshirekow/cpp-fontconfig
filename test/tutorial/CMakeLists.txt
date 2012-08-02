find_package(Fontconfig)
                       
                       
if( Fontconfig_FOUND )
                                                                    
include_directories( 
    ${Fontconfig_INCLUDE_DIRS}
    )


set(LIBS ${LIBS} 
    ${CMAKE_PROJECT_NAME} 
    ${Fontconfig_LIBRARIES}
    )
 
add_executable( tutorial tutorial.cpp )

target_link_libraries( tutorial ${LIBS} )
 
else()
    message( WARNING 
        "fontconfig was not found, disabling build of cppfontconfig tutorial"
        "you may still build the doc target"  )  
endif()