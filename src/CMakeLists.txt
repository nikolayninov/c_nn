project(c_nn LANGUAGES CXX)

file(GLOB functions_SRC
    "Functions/*.cpp"
)

add_library(c_nn ${functions_SRC})

target_include_directories(c_nn
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_include_directories(c_nn
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party)