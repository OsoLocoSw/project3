cmake_minimum_required(VERSION 3.12)
# project (pagesim C CXX)
project (pagesim)

# Note: If I'd added testing before, this project wouldn't build
add_executable(vm-sim pagesim.c mmu.c page_fault.c page_replacement.c proc.c stats.c swap.c swapops.c tests.c util.c)

project (testsim CXX C)
set (GOOGLETEST_VERSION 1.17.0)
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()
add_subdirectory(googletest)
# Need to remove page sim because it too has a main(...)
add_executable(test-vm-sim tests/some_test.cpp mmu.c page_fault.c page_replacement.c proc.c stats.c swap.c swapops.c util.c)
target_link_libraries(test-vm-sim PRIVATE gtest)
include(GoogleTest)
gtest_discover_tests(test-vm-sim)