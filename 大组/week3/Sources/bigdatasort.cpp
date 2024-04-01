#define _CRT_SECURE_NO_WARNINGS  // 忽略 scanf_s 函数的警告
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "sort.h"

using namespace std;


// 测试函数
void testSorts(vector<int>& data, int dataSize) {
    vector<int> temp(data);

    auto start = chrono::high_resolution_clock::now();
    insertionSort(temp);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "插入排序时间（元素数：" << dataSize << "）: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    mergeSort(temp, 0, dataSize - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "归并排序时间（元素数：" << dataSize << "）: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    quickSort(temp, 0, dataSize - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "快速排序时间（元素数：" << dataSize << "）: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    countSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "计数排序时间（元素数：" << dataSize << "）: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    radixCountSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "基数计数排序时间（元素数：" << dataSize << "）: " << elapsed_seconds.count() << "秒\n";
}

int main() {
    int dataSize;
    cout << "输入要处理的数据大小: ";
    cin >> dataSize;

    vector<int> data(dataSize);
    srand(time(0));
    for (int i = 0; i < dataSize; ++i) {
        data[i] = rand() % 1000; 
    }

    testSorts(data, dataSize);

    return 0;
}
