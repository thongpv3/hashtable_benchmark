
set(GENERATOR_HEADERS generator/Generator.h
        generator/UniformNumberGenerator.h
        generator/DiscreteGenerator.h
        generator/UniformStringGerator.h)

set(BENCHMARK_HEADERS HashTableWrapper.h HashTable.h LeapfrogMapBinding.h StdMapBinding.h StdUnorderedMapBinding.h)


add_executable(test_hashtable main.cpp HashTable.h HashTableWrapper.h StdMapBinding.h ${GENERATOR_HEADERS})

add_executable(bm_stdmap benchmark.cpp)
target_include_directories(bm_stdmap PRIVATE ${GG_BENCHMARK_INCLUDE} ${JUNCTION_INCLUDE})
target_link_libraries(bm_stdmap PRIVATE benchmark)
message(STATUS "${JUNCTION_INCLUDE}")