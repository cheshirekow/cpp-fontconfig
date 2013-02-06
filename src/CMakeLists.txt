find_package( Fontconfig )
find_package( CppFreetype )
find_package( Freetype2 )

if( Fontconfig_FOUND )
                                                                    
    include_directories( 
        ${Fontconfig_INCLUDE_DIRS}
        )
    
    set( LIBRARY_SOURCES
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
            TypeMap.cpp )
            
    if( (CppFreetype_FOUND) AND (Freetype2_FOUND) )
        include_directories(
            ${CppFreetype_INCLUDE_DIRS}
            ${Freetype2_INCLUDE_DIRS} )
        
        set( LIBRARY_SOURCE ${LIBRARY_SOURCES} freetype.cpp )
        message( STATUS
            "-----\n"
            "Found cppfreetype so will build with freetype support\n"
            "-----\n" )
    else()
        message( WARNING 
            "failed to find cppfreetype or freetype2, so cppfontconfig "
            "wont build with freetype support" )
    endif()
            
    add_library( ${CMAKE_PROJECT_NAME} SHARED
                    ${LIBRARY_SOURCES} )
                    
    add_library( ${CMAKE_PROJECT_NAME}_static STATIC
                    ${LIBRARY_SOURCES} )
                
 
    INSTALL( TARGETS ${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_static
      RUNTIME DESTINATION bin
      LIBRARY DESTINATION lib
      ARCHIVE DESTINATION lib
    )
     
else()
    message( WARNING 
        "fontconfig was not found, disabling build of cppfontconfig library"
        "you may still build the doc target"  )  
endif()