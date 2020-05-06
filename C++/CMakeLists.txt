# ToDo := Copyright

cmake_minimum_required(VERSION 3.0)
project(RabbitSSL)

include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(AMQP-CPP
    GIT_REPOSITORY https://github.com/CopernicaMarketingSoftware/AMQP-CPP
    GIT_TAG v4.1.6
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

add_executable(AMQP-SSL Main.cpp RabbitConnectionHandler.cpp RabbitConnectionHandler.h Define.h)
add_dependencies(AMQP-SSL AMQP-CPP)
target_link_libraries(AMQP-SSL amqpcpp)