#include "../include/decompressor.h"
#include "../include/huffman_tree.h"
#include "../include/utils.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <limits>

// 从文件读取哈夫曼树构建信息（这里简单假设按顺序先存字符频率对的数量，再依次存字符和频率）
void readHuffmanTreeInfo(const char* inputFileName, std::vector<char>& data, std::vector<int>& freq) {
    std::ifstream file(inputFileName, std::ios::binary);
    if (file.is_open()) {
        int numPairs;
        file.read(reinterpret_cast<char*>(&numPairs), sizeof(int));

        // 验证读取到的字符频率对数量是否合理
        if (numPairs < 0 || numPairs > 10000) {  // 这里设定一个合理范围的阈值，可根据实际情况调整
            std::cerr << "【错误信息】读取到的字符频率对数量不合理: " << numPairs << "，可能文件已损坏" << std::endl;
            return;
        }

        for (int i = 0; i < numPairs; ++i) {
            char ch;
            int frequency;
            file.read(&ch, sizeof(char));
            file.read(reinterpret_cast<char*>(&frequency), sizeof(int));

            // 验证频率值是否在合理范围内
            if (frequency < 0 || frequency > std::numeric_limits<int>::max() / 2) {  // 防止频率值过大或为负数
                std::cerr << "【错误信息】读取到的频率值不合理: " << frequency << "，对应字符: " << ch << "，可能文件已损坏" << std::endl;
                continue;  // 跳过这个不合理的数据对，继续尝试读取下一组
            }

            data.push_back(ch);
            freq.push_back(frequency);
        }

        file.close();
    } else {
        std::cerr << "无法打开文件: " << inputFileName << " 读取哈夫曼树信息" << std::endl;
    }
}

// 解压函数（完整示例，包含重建哈夫曼树逻辑）
void decompress(const char* inputFileName, const char* outputFileName) {
    // 读取重建哈夫曼树的字符和频率信息
    std::vector<char> dataForTree;
    std::vector<int> freqForTree;
    readHuffmanTreeInfo(inputFileName, dataForTree, freqForTree);

    // 构建哈夫曼树，添加错误处理
    HuffmanNode* huffmanTree = buildHuffmanTree(dataForTree, freqForTree);
    if (huffmanTree == nullptr) {
        std::cerr << "【错误信息】构建哈夫曼树失败，可能文件头信息损坏或数据异常" << std::endl;
        return;
    }

    std::vector<char> inputData;
    readFileToBuffer(inputFileName, inputData);

    // 开始解压，基于构建好的哈夫曼树反向还原数据
    HuffmanNode* current = huffmanTree;
    std::vector<char> decompressedData;
    size_t index = sizeof(int) + dataForTree.size() * (sizeof(char) + sizeof(int));  // 跳过文件头信息开始解压
    while (index < inputData.size()) {
        char bit = inputData[index];
        if (bit == '0') {
            if (current->left == nullptr) {
                std::cerr << "【错误信息】解压过程中，哈夫曼树节点左子树为空，不符合预期，可能文件已损坏" << std::endl;
                return;
            }
            current = current->left;
        } else {
            if (current->right == nullptr) {
                std::cerr << "【错误信息】解压过程中，哈夫曼树节点右子树为空，不符合预期，可能文件已损坏" << std::endl;
                return;
            }
            current = current->right;
        }
        if (current->left == nullptr && current->right == nullptr) {
            decompressedData.push_back(current->data);
            current = huffmanTree;
        }
        index++;
    }

    writeBufferToFile(outputFileName, decompressedData);
}