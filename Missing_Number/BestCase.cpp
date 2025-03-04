#include <iostream>
#include <vector>
using namespace std;
///only for one missing value
// Time Complexity: O(n) - only loops through the array once
// Space Complexity: O(1) - uses only a fixed amount of extra space
int missingNumberFormula(vector<int>& nums) {
    int n = nums.size();
    cout << "Array Size: " << n << endl;
    int expectedSum=0;
    for(int i=0;i<=nums.size();i++){
        expectedSum += i;
    }
    cout << "Expected Sum: " << expectedSum << endl;
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    cout << "Actual Sum: " << actualSum << endl;
    return expectedSum - actualSum;
}

int main() {
    vector<int> nums = {0, 1, 2, 4, 5, 6};
    cout << "Missing Number: " << missingNumberFormula(nums) << endl;
    return 0;
}
