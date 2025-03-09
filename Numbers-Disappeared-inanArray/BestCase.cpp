#include <iostream>
#include <vector>
using namespace std;

vector<int> findDisappearedNumber(vector<int> &nums)
{
    vector<int> result;  // Vector to store missing numbers

    // First pass: mark visited indices by making them negative
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;  // abs() gives absolute value (ignores negative sign)
                                       // Convert value to 0-indexed position
        
        nums[index] = -abs(nums[index]);  // Mark the index as visited by making it negative
                                         // abs() ensures we don't flip the sign twice
    }

    // Second pass: find indices that were never marked (still positive)
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)  // If value is positive, its index+1 was never seen
        {
            result.push_back(i + 1);  // Add the missing number (convert from 0-indexed to 1-indexed)
        }
    }
    return result;  // Return all missing numbers
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};  // Example array with numbers 5 and 6 missing
    vector<int> result = findDisappearedNumber(nums);  // Find missing numbers

    // Print results
    for (int num : result)
    {
        cout << num << " ";  // Output: 5 6
    }
    cout << endl;
    return 0;
}


// Common Names for This Approach:
// Index Marking Technique – It modifies the array in place by marking visited indices as negative.
// In-Place Hashing – The array itself acts as a hash table, where presence is tracked via sign changes.
// Cyclic Sort Approach (Variation) – This is related to the Cyclic Sort method, where numbers are placed at their correct indices.
// Negative Marking Method – Uses negative values to indicate visited indices.
// Why This Works?
// By treating the array as a hash map, we avoid using extra space.
// The numbers are between 1 and n, so we can map values to indices.
// Unvisited indices remain positive, helping us find the missing numbers.
// This is an optimized 
// 𝑂(𝑛) time,  O(1) space solution for finding disappeared numbers in an array.
// The approach modifies the input array in place to track visited indices.