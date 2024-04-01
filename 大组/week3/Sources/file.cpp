#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include "sort.h"

using namespace std;

// ���ɲ������ݲ����浽�ļ�
void generateTestData(int dataSize, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "�޷����ļ���" << filename << endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < dataSize; ++i) {
        file << rand() % 1000 << endl; // ����0��999֮������������д���ļ�
    }

    file.close();
}

// ���ļ��ж�ȡ����
vector<int> readDataFromFile(const string& filename) {
    vector<int> data;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "�޷����ļ���" << filename << endl;
        return data;
    }

    int num;
    while (file >> num) {
        data.push_back(num); // ��ȡ�ļ��е�ÿ����������vector
    }

    file.close();
    return data;
}

// �������
void printData(const vector<int>& data) {
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
}

// ���������㷨
void testSorts(const vector<int>& data, int iterations) {
    vector<int> temp(data);

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        insertionSort(temp);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "��������ʱ��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        mergeSort(temp, 0, temp.size() - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "�鲢����ʱ��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        quickSort(temp, 0, temp.size() - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "��������ʱ��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        countSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "��������ʱ��: " << elapsed_seconds.count() << "��\n";

    temp = data;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        radixCountSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "������������ʱ��: " << elapsed_seconds.count() << "��\n";
}

int main() {
    int dataSize, iterations;
    string filename;

    cout << "������Ҫ���ɵĲ������ݴ�С: ";
    cin >> dataSize;
    cout << "������Ҫ���浽���ļ���: ";
    cin >> filename;

    generateTestData(dataSize, filename);
    cout << "�����ɲ������ݲ����浽�ļ� " << filename << endl;

    cout << "�������������: ";
    cin >> iterations;

    cout << "���ļ��ж�ȡ����...\n";
    vector<int> data = readDataFromFile(filename);
    cout << "��ȡ��������Ϊ: ";
    printData(data);

    cout << "��ʼ���������㷨...\n";
    testSorts(data, iterations);

    return 0;
}
