project(cnn LANGUAGES CXX)

file(GLOB EXAMPLE_SOURCE_FILES *.cpp)

foreach(EXAMPLE_PATH ${EXAMPLE_SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${EXAMPLE_PATH} NAME_WE)

    add_executable(${EXECUTABLE_NAME} ${EXAMPLE_PATH})

    target_link_libraries(${EXECUTABLE_NAME} PRIVATE cnn) 
    
endforeach(EXAMPLE_PATH ${EXAMPLE_SOURCE_FILES})
