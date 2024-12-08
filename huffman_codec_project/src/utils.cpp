#include "../include/utils.h"
#include <fstream>
#include <iostream>

// 从文件读取数据到缓冲区的函数示例（简单以字符读取为例）
void readFileToBuffer(const char* fileName, std::vector<char>& buffer) {
    std::ifstream file(fileName, std::ios::binary);
    if (file.is_open()) {
        char ch;
        while (file.get(ch)) {
            buffer.push_back(ch);
        }
        file.close();
    } else {
        std::cerr << "无法打开文件: " << fileName << std::endl;
    }
}

// 将缓冲区数据写入文件的函数示例
void writeBufferToFile(const char* fileName, const std::vector<char>& buffer) {
    std::ofstream file(fileName, std::ios::binary);
    if (file.is_open()) {
        for (char ch : buffer) {
            file.put(ch);
        }
        file.close();
    } else {
        std::cerr << "无法打开文件: " << fileName << std::endl;
    }
}