#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// for check only one missing number
int missingNumberSorting(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    cout << "Sorted Array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i) return i;
    }
    cout<<"no missing number"<<endl;
    return nums.size();
}

int main() {
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "Missing Number: " << missingNumberSorting(nums) << endl;
    return 0;
}
