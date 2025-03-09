#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findDisappearedNumbersHashSet(vector<int>& nums) {
    // Create a hash set with all values from the array
    // This automatically eliminates duplicates
    // O(n) time and space
    unordered_set<int> numSet(nums.begin(), nums.end());
    
    vector<int> result;
    
    // Check each number from 1 to n
    for (int i = 1; i <= nums.size(); i++) {
        // find(i) searches for value i in the hash set
        // find() returns an iterator - either pointing to the element,
        // or to numSet.end() if the element wasn't found
        
        // numSet.end() is a special iterator that points PAST the last element
        // It serves as a "not found" marker in STL containers
        
        // So "find(i) == end()" means "i is NOT in the set"
        // This is the standard C++ idiom for checking if an element is absent
        if (numSet.find(i) == numSet.end()) {
            // If i is not in the set, it's a disappeared number
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = findDisappearedNumbersHashSet(nums);
    
    cout << "Missing numbers: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
