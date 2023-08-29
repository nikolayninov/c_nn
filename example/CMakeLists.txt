project(c_nn LANGUAGES CXX)



add_executable(main main.cpp)


target_link_libraries(main 
    PRIVATE
    c_nn)