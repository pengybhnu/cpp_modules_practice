project(asyn CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(read)
target_sources(read PUBLIC ${CMAKE_SOURCE_DIR}/src/coroutine/read.cpp)
# target_compile_features(read PUBLIC cxx_std_23)
target_link_libraries(read )