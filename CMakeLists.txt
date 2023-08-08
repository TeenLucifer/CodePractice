cmake_minimum_required(VERSION 3.10)

project(CodePractice)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 添加可执行文件
add_executable(main src/main.cpp)

# 添加头文件目录
include_directories(include)

# 添加库文件目录（如果有的话）
# link_directories(lib)

# 链接库（如果有的话）
# target_link_libraries(myapp mylib)

# 可以添加更多的源代码文件
# add_executable(myapp src/main.cpp src/file1.cpp src/file2.cpp)
