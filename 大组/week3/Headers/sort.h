#pragma once
#ifndef SORT_H
#define SORT_H

#include <vector>;
using namespace std;

void insertionSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr, int l, int r);
void quickSort(std::vector<int>& arr, int low, int high);
void countSort(std::vector<int>& arr);
void radixCountSort(std::vector<int>& arr);

#endif // SORT_H
