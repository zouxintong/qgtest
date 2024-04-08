#include "sort.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

// 测试函数
void testSorts(vector<int>& data, int dataSize, int iterations) {
    vector<int> temp(data);

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        insertionSort(temp);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "插入排序时间（元素数：" << dataSize << "，迭代次数：" << iterations << "）: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        mergeSort(temp, 0, dataSize - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "归并排序时间（元素数：" << dataSize << "，迭代次数：" << iterations << "）: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        quickSort(temp, 0, dataSize - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "快速排序时间（元素数：" << dataSize << "，迭代次数：" << iterations << "）: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        countSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "计数排序时间（元素数：" << dataSize << "，迭代次数：" << iterations << "）: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        radixCountSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "基数计数排序时间（元素数：" << dataSize << "，迭代次数：" << iterations << "）: " << elapsed_seconds.count() << "秒\n";
}

int main() {
    int dataSize, iterations;
    cout << "请输入要处理的数据大小: ";
    cin >> dataSize;
    cout << "请输入迭代次数: ";
    cin >> iterations;

    vector<int> data(dataSize);
    srand(time(0));
    for (int i = 0; i < dataSize; ++i) {
        data[i] = rand() % 1000;
    }

    testSorts(data, dataSize, iterations);
    system("pause");
    return 0;
}