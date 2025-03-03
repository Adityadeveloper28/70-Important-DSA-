// Approach 1: Brute Force (Worst Case)
// Compare every element with every other element.
// 
// Time Complexity: O(n²) (worst case)
// Explanation: We use two nested loops to compare each element with all other elements.
// - The outer loop runs n times (where n is the size of the array)
// - For each iteration of outer loop, the inner loop runs approximately n times 
//   (specifically from i+1 to n-1)
// - Total comparisons: (n-1) + (n-2) + ... + 2 + 1 = n(n-1)/2, which simplifies to O(n²)
//
// Space Complexity: O(1)
// Explanation: We only use a fixed amount of extra space regardless of input size:
// - A few integer variables (n, i, j)
// - No additional data structures that scale with input size
// - We only work with references to the existing input array


#include <iostream> // std::cout, std::endl
#include <vector>   // std::vector
using namespace std;

bool ContainDuplicate(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 1};
    cout << (ContainDuplicate(nums) ? "true" : "false") << endl;
    return 0;
}