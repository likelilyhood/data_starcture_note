#include <iostream>
#include <vector>

using namespace std;

// 存储所有满足条件的组合，即能使权重总和达到目标容量的各种权重组合情况
vector<vector<int>> solution;

// 临时存储当前正在构建的组合，在回溯过程中不断更新这个组合
vector<int> current;

// 回溯函数，用于寻找满足条件的权重组合
// 参数说明：
// index：表示当前从weights数组中的哪个位置开始考虑选择权重
// currentWeight：记录当前已经选择的权重之和
// weights：是输入的权重数组，包含了所有可供选择的权重值
// capacity：目标容量，即要找到的权重组合之和需要达到的值
void backtrack(int index, int currentWeight, const vector<int>& weights, int capacity) {
    // 如果当前已选权重等于目标容量，说明找到了一个满足条件的组合
    if (currentWeight == capacity) {
        // 将当前构建好的组合添加到solution中，用于存储所有找到的满足条件的组合
        solution.push_back(current);
        return;
    }
    // 如果当前已选权重超过目标容量，不符合要求，直接返回，不再继续尝试添加更多权重
    if (currentWeight > capacity) return;

    for (int i = index; i < weights.size(); ++i) {
        // 检查加上当前物品（即当前考虑的权重）是否超过背包容量
        // 由于物品（权重）是有序的，一旦当前选择的权重加上后超过容量，
        // 后面的物品（更大索引对应的权重）也必定超过容量，所以可以直接break跳出循环
        if (currentWeight + weights[i] > capacity) {
            break;
        }

        // 将当前考虑的权重添加到当前正在构建的组合current中
        current.push_back(weights[i]);

        // 递归调用backtrack函数，继续从下一个位置（i + 1）开始考虑选择权重，
        // 并更新当前已选权重为加上当前选择的权重（currentWeight + weights[i]）
        backtrack(i + 1, currentWeight + weights[i], weights, capacity);

        // 回溯操作，移除最后加入的物品（权重），以便尝试其他可能的组合
        // 例如，先添加了权重A，然后递归调用后发现不行，需要回退到添加A之前的状态，继续尝试其他权重
        current.pop_back();
    }
}

// 对外提供的函数，用于启动寻找组合的过程
// 参数说明：
// capacity：目标容量，即要找到的权重组合之和需要达到的值
// weights：是输入的权重数组，包含了所有可供选择的权重值
// 返回值：返回找到的所有满足条件的组合，存储在solution中
vector<vector<int>> findCombinations(int capacity, const vector<int>& weights) {
    // 调用回溯函数开始寻找满足条件的组合，初始从weights数组的第一个位置（索引为0）开始，
    // 初始已选权重为0
    backtrack(0, 0, weights, capacity);

    // 返回找到的所有满足条件的组合
    return solution;
}

int main() {
    int T;
    cout << "请输入目标容量：";
    cin >> T;

    int numWeights;
    cout << "请输入权重的个数：";
    cin >> numWeights;

    // 根据输入的权重个数创建weights向量，并初始化为相应大小
    vector<int> weights(numWeights);
    cout << "请依次输入各个权重的值：";
    for (int i = 0; i < numWeights; ++i) {
        cin >> weights[i];
    }

    // 检查输入的目标容量是否有效，若小于等于0则输出错误提示并返回
    if (T <= 0) {
        cerr << "无效的目标容量，请输入大于0的值。" << endl;
        return 1;
    }

    // 检查输入的权重数组是否为空，若为空则输出错误提示并返回
    if (weights.empty()) {
        cerr << "权重数组不能为空，请重新输入。" << endl;
        return 1;
    }

    // 调用函数寻找满足条件的组合
    vector<vector<int>> combinations = findCombinations(T, weights);

    cout << "Combinations that sum up to " << T << ":\n";
    for (const auto& combination : combinations) {
        for (int weight : combination) {
            cout << weight << " ";
        }
        cout << "\n";
    }

    return 0;
}