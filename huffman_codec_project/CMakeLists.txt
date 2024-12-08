cmake_minimum_required(VERSION 3.10)
project(huffman_codec_project)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加源文件
add_executable(huffman_codec
    main.cpp
    src/compressor.cpp
    src/decompressor.cpp
    src/huffman_tree.cpp
    src/utils.cpp
)

# 添加头文件路径
target_include_directories(huffman_codec
    PRIVATE
    include
)