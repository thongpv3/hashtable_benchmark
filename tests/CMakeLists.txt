add_executable(test_benchmark test.cpp)
target_link_libraries(test_benchmark PRIVATE benchmark)
target_include_directories(test_benchmark PRIVATE GG_BENCHMARK_INCLUDE)


add_executable(test1 test1.cpp)
target_link_libraries(test1 PRIVATE benchmark)
target_include_directories(test1 PRIVATE GG_BENCHMARK_INCLUDE)
