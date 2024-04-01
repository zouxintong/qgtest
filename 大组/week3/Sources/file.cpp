#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include "sort.h"

using namespace std;

// 生成测试数据并保存到文件
void generateTestData(int dataSize, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "无法打开文件：" << filename << endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < dataSize; ++i) {
        file << rand() % 1000 << endl; // 生成0到999之间的随机数，并写入文件
    }

    file.close();
}

// 从文件中读取数据
vector<int> readDataFromFile(const string& filename) {
    vector<int> data;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "无法打开文件：" << filename << endl;
        return data;
    }

    int num;
    while (file >> num) {
        data.push_back(num); // 读取文件中的每个数并存入vector
    }

    file.close();
    return data;
}

// 输出数据
void printData(const vector<int>& data) {
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
}

// 测试排序算法
void testSorts(const vector<int>& data, int iterations) {
    vector<int> temp(data);

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        insertionSort(temp);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "插入排序时间: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        mergeSort(temp, 0, temp.size() - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "归并排序时间: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        quickSort(temp, 0, temp.size() - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "快速排序时间: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        countSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "计数排序时间: " << elapsed_seconds.count() << "秒\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        radixCountSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "基数计数排序时间: " << elapsed_seconds.count() << "秒\n";
}

int main() {
    int dataSize, iterations;
    string filename;

    cout << "请输入要生成的测试数据大小: ";
    cin >> dataSize;
    cout << "请输入要保存到的文件名: ";
    cin >> filename;

    generateTestData(dataSize, filename);
    cout << "已生成测试数据并保存到文件 " << filename << endl;

    cout << "请输入迭代次数: ";
    cin >> iterations;

    cout << "从文件中读取数据...\n";
    vector<int> data = readDataFromFile(filename);
    cout << "读取到的数据为: ";
    printData(data);

    cout << "开始测试排序算法...\n";
    testSorts(data, iterations);

    return 0;
}
