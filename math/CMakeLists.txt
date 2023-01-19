cmake_minimum_required(VERSION 3.24)
project(test1)

set(CMAKE_CXX_STANDARD 17)

set (CMAKE_C_COMPILER "/opt/homebrew/bin/gcc-12")
set (CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-12")
# FIND_PACKAGE(GMP REQUIRED)

# 相当于gcc `-I`参数
include_directories("/opt/homebrew/include")
# 相当于gcc `-L`参数
link_directories("/opt/homebrew/lib")

# 相当于gcc `-l`参数
link_libraries("gmp")
link_libraries("gmpxx")

# 添加可执行程序
add_executable(test1 gmp-2.cpp)

# MESSAGE(${FLTK_LIBRARIES})
# TARGET_LINK_LIBRARIES(test1 gmp)
# TARGET_LINK_LIBRARIES(test1 gmpxx)
target_link_libraries(test1 "/opt/homebrew//lib/libgmp.a")
target_link_libraries(test1 "/opt/homebrew//lib/libgmpxx.a")
