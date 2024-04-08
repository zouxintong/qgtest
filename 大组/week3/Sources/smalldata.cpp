#include "sort.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

// ���Ժ���
void testSorts(vector<int>& data, int dataSize, int iterations) {
    vector<int> temp(data);

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        insertionSort(temp);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "��������ʱ�䣨Ԫ������" << dataSize << "������������" << iterations << "��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        mergeSort(temp, 0, dataSize - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "�鲢����ʱ�䣨Ԫ������" << dataSize << "������������" << iterations << "��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        quickSort(temp, 0, dataSize - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "��������ʱ�䣨Ԫ������" << dataSize << "������������" << iterations << "��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        countSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "��������ʱ�䣨Ԫ������" << dataSize << "������������" << iterations << "��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        radixCountSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "������������ʱ�䣨Ԫ������" << dataSize << "������������" << iterations << "��: " << elapsed_seconds.count() << "��\n";
}

int main() {
    int dataSize, iterations;
    cout << "������Ҫ��������ݴ�С: ";
    cin >> dataSize;
    cout << "�������������: ";
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