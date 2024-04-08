#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    int i = 0;

    while (i <= high) {
        if (nums[i] == 0) {
            swap(nums[i], nums[low]);
            low++;
            i++;
        }
        else if (nums[i] == 1) {
            i++;
        }
        else {
            swap(nums[i], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = { 1, 2, 1, 0, 2, 0, 0 };

    cout << "排序前的数组：" << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    sortColors(nums);

    cout << "排序后的数组：" << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}