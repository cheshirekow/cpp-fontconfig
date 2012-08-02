find_package(Fontconfig )

if( Fontconfig_FOUND )
                                                                    
include_directories( 
    ${Fontconfig_INCLUDE_DIRS}
    )


add_library( ${CMAKE_PROJECT_NAME} 
                Atomic.cpp
                Blanks.cpp
                CharSet.cpp
                Cache.cpp
                Config.cpp
                Constant.cpp
                file.cpp
                FontSet.cpp
                init.cpp
                LangSet.cpp
                Matrix.cpp
                name.cpp
                ObjectSet.cpp
                ObjectType.cpp
                Pattern.cpp
                string.cpp
                String.cpp
                StrList.cpp
                StrSet.cpp
                TypeMap.cpp
                )
                
 
INSTALL( TARGETS ${CMAKE_PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
 
else()
    message( WARNING 
        "fontconfig was not found, disabling build of cppfontconfig library"
        "you may still build the doc target"  )  
endif()