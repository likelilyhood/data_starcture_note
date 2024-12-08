#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <vector>

// 完整定义哈夫曼树节点结构体
struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// 比较函数结构体，用于优先队列比较节点频率大小
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};


// 构建哈夫曼树的函数声明
HuffmanNode* buildHuffmanTree(std::vector<char>& data, std::vector<int>& freq);

#endif