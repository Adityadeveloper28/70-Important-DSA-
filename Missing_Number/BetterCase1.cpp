#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// for all possible missing number
vector<int> missingNumber(vector<int> &nums){
    sort(nums.begin(),nums.end());  // Sort the array - O(n log n)
    vector<int> result;  // Vector to store missing numbers - O(1) initially
    int expected=0;  // Track the next expected number in sequence - O(1)
    
    // Iterate through sorted array - O(n)
    for(int i=0;i<nums.size();i++){
        // Find all missing numbers between expected and current number
        while(expected<nums[i]){  // This while loop may seem nested but overall runs O(range) times
            result.push_back(expected);  // Add missing number to result - O(1) amortized
            expected++;  // Move to next expected number
        }
        expected++;  // Current number found, move to next expected number
    }

    if(result.empty()){
        cout<<"NO Missing Number"<<endl;  // Output if no missing numbers
    }

    return result;  // Return all missing numbers - O(1)
}

int main(){
    vector<int> nums = {3,0,1,4,6};  // Example input array
    vector<int> missing = missingNumber(nums);  // Find missing numbers
    cout << "Missing Number: ";
    for (int num : missing)  // Iterate through missing numbers
    {
        cout << num << " ";  // Output each missing number
    }
    cout << endl;

    return 0;
}