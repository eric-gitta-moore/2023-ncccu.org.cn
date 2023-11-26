#include "bits/stdc++.h"

bool isMaxHeap(const std::vector<int> &heapArray) {
    int size = heapArray.size();

    // 从最后一个非叶子节点开始，逐个检查是否满足大根堆性质
    for (int i = size / 2 - 1; i >= 0; --i) {
        int current = i;
        int leftChild = 2 * current + 1;
        int rightChild = 2 * current + 2;

        // 检查左孩子是否大于当前节点
        if (leftChild < size && heapArray[leftChild] > heapArray[current]) {
            return false;
        }

        // 检查右孩子是否大于当前节点
        if (rightChild < size && heapArray[rightChild] > heapArray[current]) {
            return false;
        }
    }

    return true;
}

int main() {
//    freopen("in", "r", stdin);
//    std::cout << "输入完全二叉树数组存储序列: ";

    int num;
    std::vector<int> heapArray;

    // 读取输入序列
    while (std::cin >> num) {
        heapArray.push_back(num);
    }

    // 判断是否为大根堆并输出结果
    if (isMaxHeap(heapArray)) {
        std::cout << "The input array is a max heap." << std::endl;
    } else {
        std::cout << "The input array is not a max heap." << std::endl;
    }

    return 0;
}
