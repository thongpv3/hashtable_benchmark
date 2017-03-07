#add google benchmark library
add_subdirectory(benchmark)
#add google benchmark include directory to parent scope
set(GG_BENCHMARK_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/include PARENT_SCOPE)

#add junction library
add_subdirectory(junction)
set(JUNCTION_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/junction PARENT_SCOPE)
#add turf for junction dependency