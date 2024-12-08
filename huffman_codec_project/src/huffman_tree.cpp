#include "../include/huffman_tree.h"
#include <queue>
#include <vector>
#include <iostream>


// 构建哈夫曼树的函数
HuffmanNode* buildHuffmanTree(std::vector<char>& data, std::vector<int>& freq) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;

    for (size_t i = 0; i < data.size(); ++i) {
        HuffmanNode* newNode = new HuffmanNode(data[i], freq[i]);
        pq.push(newNode);
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    return pq.top();
}
