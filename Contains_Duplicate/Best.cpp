// Approach 3: Hash Set (Best)
// Use a hash set to keep track of seen elements.
// 
// Time Complexity: O(n)
// Explanation: 
// - We iterate through the array once, performing O(1) operations at each step
// - unordered_set provides average O(1) lookup and insertion time
// - In the worst case, we process all n elements exactly once
//
// Space Complexity: O(n) 
// Explanation:
// - In the worst case (no duplicates), we store all elements in the hash set
// - The space required grows linearly with the input size
// - For n elements in the array, we could potentially store up to n elements in the set

#include <iostream>  // std::cout, std::endl
#include <vector>    // std::vector
#include <unordered_set>  // std::unordered_set
using namespace std;

bool ConatainDuplicate(vector<int> &nums){
    // unordered_set: A container that stores unique elements in no particular order
    // - Implemented using a hash table
    // - Average O(1) time complexity for search, insert, and delete operations
    // - Does not allow duplicate values
    unordered_set<int> seen;
    
    // Range-based for loop to iterate through each element in nums
    for(int num : nums){
        // seen.find(num): Searches for num in the set
        // - Returns iterator to the element if found
        // - Returns seen.end() if not found
        // - Average time complexity: O(1)
        if(seen.find(num) != seen.end()){
            // Element already exists in set, found a duplicate
            return true;
        }
        // seen.insert(num): Add num to the set
        // - Average time complexity: O(1)
        seen.insert(num);
    }
    return false;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 1};
    cout << (ConatainDuplicate(nums) ? "true" : "false") << endl;
    return 0;
}