#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 物品结构体，用于表示每个物品的属性
// 这里包含了两个属性：weight表示物品的体积（在背包问题情境下，可理解为占据背包空间的量），value表示物品的价值（即放入背包能获得的收益）
struct Item {
    int weight;
    int value;
};

// 动态规划求解0-1背包问题的函数
// 参数：
// items：一个常量引用类型的参数，它接收一个包含所有物品信息的向量。通过引用传递避免不必要的复制操作，提高效率，且保证函数内不会修改该向量内容。
// capacity：表示背包的容量，即背包能够容纳的物品体积总和的上限。
int knapsack(const vector<Item>& items, int capacity) {
    // 获取物品的数量，即输入的物品向量items中的元素个数
    int n = items.size();

    // 创建一个二维向量dp，用于存储动态规划过程中的中间结果
    // dp的类型是vector<vector<int>>，其大小被初始化为(n + 1)×(capacity + 1)，且所有元素初始化为0
    // dp[i][w]表示在前i个物品中，当背包容量为w时能够获得的最大价值
    // 多出来的一行一列（i = 0和w = 0的情况）是为了方便处理边界条件，比如没有物品可选（i = 0）或背包容量为0（w = 0）时，最大价值显然为0
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // 动态规划填表过程，通过两层嵌套的for循环来遍历所有可能的物品选择情况和背包容量情况
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            // 判断当前物品（索引为i - 1，因为items向量索引从0开始）是否能放入背包，即判断其体积是否小于等于当前背包容量w
            if (items[i - 1].weight <= w) {
                // 如果当前物品能放入背包，需要考虑两种情况来确定当前状态（前i个物品，背包容量为w）下的最大价值：
                // 1. 不选择当前物品，此时最大价值就是前i - 1个物品在背包容量为w时能够获得的最大价值，即dp[i - 1][w]
                // 2. 选择当前物品，此时最大价值就是前i - 1个物品在背包容量为w - 当前物品体积（items[i - 1].weight）时能够获得的最大价值，再加上当前物品的价值（items[i - 1].value）
                // 取这两种情况中的最大值作为当前状态下的最大价值
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                // 如果当前物品不能放入背包，那么当前状态（前i个物品，背包容量为w）下的最大价值就和前i - 1个物品在背包容量为w时能够获得的最大价值相同，即dp[i - 1][w]
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // 当两层循环结束后，dp[n][capacity]就存储了在前n个物品中，当背包容量为capacity时能够获得的最大价值
    // 返回这个最大价值作为背包中物品的最大价值
    return dp[n][capacity];
}

int main() {
    // 用于存储用户输入的背包容量
    int capacity;
    cout << "请输入背包的容量：";
    cin >> capacity;

    // 用于存储用户输入的物品数量
    int numItems;
    cout << "请输入物品的数量：";
    cin >> numItems;

    // 根据用户输入的物品数量创建一个向量，用于存储所有物品的信息
    vector<Item> items(numItems);
    cout << "请依次输入每个物品的体积和价值：" << endl;
    for (int i = 0; i < numItems; ++i) {
        // 读取每个物品的体积和价值，并存储到items向量中相应的元素里
        cin >> items[i].weight >> items[i].value;
    }

    // 调用knapsack函数求解背包中物品的最大价值
    int max_value = knapsack(items, 2000);
    cout << "背包中物品的最大价值为: " << max_value << endl;

    return 0;
}