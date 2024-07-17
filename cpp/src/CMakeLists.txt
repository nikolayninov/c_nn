project(cnn LANGUAGES CXX)

file(GLOB functions_SRC
    "Functions/*.cpp"
)

file(GLOB layers_SRC
    "Layers/*.cpp")

file(GLOB models_SRC
    "Models/*.cpp")

file(GLOB misc_SRC
    "./*.cpp")

file(GLOB_RECURSE headers_SRC "../include/*.hpp")


set(SOURCE_FILES ${functions_SRC} ${layers_SRC} ${models_SRC} ${misc_SRC} ${headers_SRC})

add_library(cnn SHARED ${SOURCE_FILES})

# source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})


target_include_directories(cnn
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party)

target_include_directories(cnn
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)

install(TARGETS cnn DESTINATION lib)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/Eigen/Eigen DESTINATION include)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/Eigen DESTINATION include)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../include/cnn.hpp DESTINATION include)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../include/cnn DESTINATION include)

install(TARGETS cnn DESTINATION lib)