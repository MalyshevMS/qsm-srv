cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

set(PROJECT_NAME qsm-srv)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
    src/main.cpp

    src/tcp/server.hpp
    src/tcp/server.cpp

    src/tcp/handler.hpp
    src/tcp/handler.cpp

    src/ssl/ssl.hpp
    src/ssl/ssl.cpp

    src/fs/get.hpp
    src/fs/get.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 23
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_subdirectory(ext/sfml)

target_link_libraries(${PROJECT_NAME}
    sfml-network
    ssl
    crypto
    SQLiteCpp
)