#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Time Complexity: O(n) - loops through the array once
// Space Complexity: O(n) - uses a hash set to track numbers
vector<int> findAllMissingNumbers(vector<int>& nums) {
    int n = nums.size();
    cout << "Array Size: " << n << endl;
    
    // Create a hash set to mark present numbers - O(n) space
    unordered_set<int> numSet;
    
    // Mark all numbers in the array as present - O(n) time
    for (int num : nums) {
        numSet.insert(num);
    }
    cout << "Set inserted";
    for(auto i : numSet){
        cout << i << " ";
    }
    cout << endl;
    
    // Check which numbers are missing in the range [0,n] - O(n) time
    vector<int> missingNumbers;
    for (int i = 0; i <= n; i++) {
        // If number i is not in the set, it's missing
        if (numSet.find(i) == numSet.end()) {
            missingNumbers.push_back(i);
        }
    }
    
    return missingNumbers;
}

int main() {
    vector<int> nums = {0, 1, 2, 4, 6};
    vector<int> missing = findAllMissingNumbers(nums);
    
    cout << "Missing Numbers: ";
    for (int num : missing) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}