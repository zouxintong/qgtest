#include <iostream>
#include <vector>

using namespace std;

// ��������
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// ��������
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// �ҵ��� k С����
int findKthSmallest(vector<int>& arr, int k) {
    if (k > arr.size() || k <= 0) {
        cout << "��Ч�� k ֵ\n";
        return -1;
    }

    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        }
        else if (pivotIndex < k - 1) {
            low = pivotIndex + 1;
        }
        else {
            high = pivotIndex - 1;
        }
    }

    cout << "δ�ҵ��� " << k << " С����\n";
    return -1;
}

int main() {
    vector<int> arr = { 5, 2, 8, 4, 3, 7, 6 };
    int k = 3;
    int result = findKthSmallest(arr, k);
    if (result != -1) {
        cout << "�� " << k << " С����Ϊ: " << result << endl;
    }
    system("pause");
    return 0;
}