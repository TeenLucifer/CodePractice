cmake_minimum_required(VERSION 3.10)

project(CodePractice)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE "Debug")

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加可执行文件
add_executable(main 
    src/main.cpp 
    src/code_caprice.cpp 
    src/real_question.cpp 
)

#将可执行文件输出到文件夹bin中
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)



# 添加库文件目录（如果有的话）
# link_directories(lib)

# 链接库（如果有的话）
# target_link_libraries(myapp mylib)