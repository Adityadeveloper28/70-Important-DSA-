#include <iostream>
#include <vector>
using namespace std;

vector<int> missingNumber(vector<int> &nums)
{
    /// only for first in the array
    int n = nums.size();  // Get length of input array - O(1)
    vector<int> result;   // Create vector to store missing numbers - O(1) initially
    
    for (int i = 0; i <= n; i++) { // Outer loop runs (n+1) times - O(n)
        int found = false;  // Initialize flag to track if current number exists - O(1)
        
        for (int num : nums) { // Inner loop runs n times - O(n)
            if (num == i) {    // Check if current number exists in array - O(1)
                found = true;   // Set flag if found - O(1)
                break;          // Exit inner loop early if found - O(1)
            }
        }
        
        if (!found) {           // If number wasn't found in array - O(1)
            // return i;        // Original code would return early (commented out)
            result.push_back(i); // Add missing number to result vector - O(1) amortized
        }
    }

    return result;  // Return vector with all missing numbers - O(1)
}

int main()
{
    vector<int> nums = {3,0,1,4,6};
    vector<int> missing = missingNumber(nums);
    cout << "Missing Number: ";
    for (int num : missing)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
