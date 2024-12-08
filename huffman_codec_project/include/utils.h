#ifndef UTILS_H
#define UTILS_H

#include <vector>

// 从文件读取数据到缓冲区的函数声明
void readFileToBuffer(const char* fileName, std::vector<char>& buffer);

// 将缓冲区数据写入文件的函数声明
void writeBufferToFile(const char* fileName, const std::vector<char>& buffer);

#endif