#include "include/compressor.h"
#include "include/decompressor.h"
#include <iostream>

int main() {
    const char* inputFileName = "../sources/xiqian.txt";  // 替换为实际输入文件名
    const char* compressedFileName = "../sources/compressed.bin";
    const char* decompressedFileName = "../sources/decompressed.txt";

    // 压缩文件
    compress(inputFileName, compressedFileName);
    std::cout << "文件压缩完成" << std::endl;

    // 解压文件
    decompress(compressedFileName, decompressedFileName);
    std::cout << "文件解压完成" << std::endl;
    std::cout<<"111"<<std::endl;
    return 0;
}