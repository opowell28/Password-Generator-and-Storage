cmake_minimum_required(VERSION 3.13)
project(7__BoostRandom)

message(STATUS "start running cmake...")

find_package(Boost REQUIRED system random)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()

add_executable(7__BoostRandom main.cpp)

if(Boost_FOUND)

    target_link_libraries(7__BoostRandom Boost::system Boost::random)

endif()