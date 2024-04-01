#define _CRT_SECURE_NO_WARNINGS  // ���� scanf_s �����ľ���
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "sort.h"

using namespace std;


// ���Ժ���
void testSorts(vector<int>& data, int dataSize) {
    vector<int> temp(data);

    auto start = chrono::high_resolution_clock::now();
    insertionSort(temp);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "��������ʱ�䣨Ԫ������" << dataSize << "��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    mergeSort(temp, 0, dataSize - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "�鲢����ʱ�䣨Ԫ������" << dataSize << "��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    quickSort(temp, 0, dataSize - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "��������ʱ�䣨Ԫ������" << dataSize << "��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    countSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "��������ʱ�䣨Ԫ������" << dataSize << "��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    radixCountSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "������������ʱ�䣨Ԫ������" << dataSize << "��: " << elapsed_seconds.count() << "��\n";
}

int main() {
    int dataSize;
    cout << "����Ҫ��������ݴ�С: ";
    cin >> dataSize;

    vector<int> data(dataSize);
    srand(time(0));
    for (int i = 0; i < dataSize; ++i) {
        data[i] = rand() % 1000; 
    }

    testSorts(data, dataSize);

    return 0;
}
