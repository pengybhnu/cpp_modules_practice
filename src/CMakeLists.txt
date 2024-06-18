project(base)
set(CMAKE_CXX_STANDARD 23)
add_executable(infot)
target_sources(infot PRIVATE info.cpp)
target_link_libraries(infot)


# add_executable(coroute)
# target_include_directories(coroute PRIVATE ${stdexec_SOURCE_DIR})
# target_sources(coroute PUBLIC ${CMAKE_SOURCE_DIR}/src/corout.cpp)
# target_link_libraries(coroute )

add_library(basegeo)
target_sources(basegeo
PUBLIC FILE_SET
       cxx_modules
       TYPE
       CXX_MODULES
       FILES ${CMAKE_SOURCE_DIR}/src/common/basegeo.cppm)
target_link_libraries(basegeo )

add_executable(c20deduce)
target_sources(c20deduce PUBLIC ${CMAKE_SOURCE_DIR}/src/deduce.cpp)
target_compile_features(c20deduce PUBLIC cxx_std_23)
target_link_libraries(c20deduce PUBLIC basegeo stlm stdc++exp)

add_executable(semt)
target_sources(semt PUBLIC ${CMAKE_SOURCE_DIR}/src/sem.cpp)
target_link_libraries(semt )

add_subdirectory(coroutine)