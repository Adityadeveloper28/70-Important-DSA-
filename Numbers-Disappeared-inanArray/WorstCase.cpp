#include <iostream>
#include <vector>
using namespace std;

vector<int> findDispearedNumbers(vector<int> &nums){
   vector<int> result;
   int n=nums.size();
   for(int i=0;i<=n;i++){
    bool found=false;
    for(int num:nums){
        if(num==i){
            found=true;
            break;
        }
    }
    if(!found){
        result.push_back(i);
    }
   }
   return result;
}

int main(){
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result= findDispearedNumbers(nums);

    for(int num:result){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}