// Approach 2: Sorting (Better)
// Sort the array and check for adjacent duplicates.
// 
// Time Complexity: O(n log n) (due to sorting)
// Explanation: 
// - Sorting the array takes O(n log n) time
// - The subsequent linear scan through the sorted array takes O(n) time
// - Overall time complexity is dominated by the sorting operation: O(n log n)
//
// Space Complexity: O(1) 
// Explanation:
// - The sort is performed in-place on the input array
// - Only a constant amount of extra space is used (variables for iteration)
// - No additional data structures that grow with input size are used

#include <iostream> // std::cout, std::endl
#include <vector>   // std::vector
#include <algorithm> // std::sort
using namespace std;

bool ContainDuplicate(vector<int>& nums){
    // std::sort: A function from the <algorithm> library that arranges elements
    // in ascending order by default
    // - Time complexity: O(n log n)
    // - Uses a hybrid sorting algorithm (typically introsort - combining quicksort, 
    //   heapsort, and insertion sort)
    //
    // nums.begin(): Returns an iterator pointing to the first element of the vector
    // nums.end(): Returns an iterator pointing just past the last element (not to the last element)
    //
    // After sorting, any duplicate elements will be adjacent to each other,
    // making them easy to find with a single pass
    sort(nums.begin(),nums.end());
    
    cout << "Sorted Array: ";
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    for(int i=0;i<nums.size()-1;i++){
        if(nums[i] == nums[i+1]){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 1};
    cout << (ContainDuplicate(nums) ? "true" : "false") << endl;
    return 0;
}