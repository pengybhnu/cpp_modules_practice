project(base)
set(CMAKE_CXX_STANDARD 20)
add_executable(infot)
target_sources(infot PRIVATE info.cpp)
target_link_libraries(infot)


add_executable(coroute)
target_include_directories(coroute PRIVATE ${stdexec_SOURCE_DIR})
target_sources(coroute PUBLIC ${CMAKE_SOURCE_DIR}/src/corout.cpp)
target_link_libraries(coroute )