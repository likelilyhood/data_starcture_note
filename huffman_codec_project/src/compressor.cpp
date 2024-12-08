#include "../include/compressor.h"
#include "../include/huffman_tree.h"
#include "../include/utils.h"
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
// 添加对<fstream>头文件的包含
#include <fstream>
// 简单示例，统计字符频率，这里可以进一步优化性能等方面
// 比如可以预先分配足够大小的 freqMap 空间，或者使用更高效的数据结构和算法来统计频率
void countFrequencies(const std::vector<char>& data, std::unordered_map<char, int>& freqMap) {
    for (char ch : data) {
        freqMap[ch]++;
    }
}

// 构建哈夫曼编码表（简单示例，实际可能更复杂）
void buildHuffmanCodeTable(HuffmanNode* root, std::string code, std::unordered_map<char, std::string>& codeTable) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        codeTable[root->data] = code;
    }
    buildHuffmanCodeTable(root->left, code + "0", codeTable);
    buildHuffmanCodeTable(root->right, code + "1", codeTable);
}

// 压缩函数
void compress(const char* inputFileName, const char* outputFileName) {
    // 读取输入文件内容到 inputData 向量中
    std::vector<char> inputData;
    readFileToBuffer(inputFileName, inputData);
    if (inputData.empty()) {
        std::cerr << "输入文件为空，无需压缩，直接返回" << std::endl;
        return;
    }

    // 统计字符频率
    std::unordered_map<char, int> freqMap;
    countFrequencies(inputData, freqMap);

    // 构建用于哈夫曼树的数据向量（字符和对应的频率）
    std::vector<char> data;
    std::vector<int> freq;
    for (auto& it : freqMap) {
        data.push_back(it.first);
        freq.push_back(it.second);
    }

    // 显式记录字符频率对数量
    int numPairs = data.size();
    std::vector<char> fileHeader;
    // 将字符频率对数量转换为char数组（假设按小端序存储，根据实际情况可能需调整字节序）
    char* numPairsBytes = reinterpret_cast<char*>(&numPairs);
    for (int i = 0; i < sizeof(int); ++i) {
        fileHeader.push_back(numPairsBytes[i]);
    }

    // 构建哈夫曼树
    HuffmanNode* huffmanTree = buildHuffmanTree(data, freq);
    if (huffmanTree == nullptr) {
        std::cerr << "构建哈夫曼树失败，无法进行压缩" << std::endl;
        return;
    }

    // 构建哈夫曼编码表
    std::unordered_map<char, std::string> codeTable;
    buildHuffmanCodeTable(huffmanTree, "", codeTable);

    // 根据编码表对输入数据进行编码，生成压缩数据
    std::vector<char> compressedData;
    for (char ch : inputData) {
        std::string code = codeTable[ch];
        for (char bit : code) {
            compressedData.push_back(bit);
        }
    }

    // 先将文件头信息写入文件
    std::ofstream file(outputFileName, std::ios::binary);
    if (file.is_open()) {
        try {
            // 写入字符频率对数量信息（文件头部分）
            for (char ch : fileHeader) {
                file.put(ch);
            }

            // 写入每个字符及其对应的频率信息（文件头部分，可用于解压时重建哈夫曼树）
            for (size_t i = 0; i < data.size(); ++i) {
                file.put(data[i]);
                int frequency = freq[i];
                char* freqBytes = reinterpret_cast<char*>(&frequency);
                for (int j = 0; j < sizeof(int); ++j) {
                    file.put(freqBytes[j]);
                }
            }

            // 写入压缩后的数据
            for (char ch : compressedData) {
                file.put(ch);
            }

            file.close();
        } catch (...) {
            std::cerr << "写入文件过程中出现未知错误" << std::endl;
            // 尝试关闭文件，尽量保证文件处于合理状态
            if (file.is_open()) {
                file.close();
            }
        }
    } else {
        std::cerr << "无法打开文件: " << outputFileName << " 进行压缩数据写入" << std::endl;
    }
}