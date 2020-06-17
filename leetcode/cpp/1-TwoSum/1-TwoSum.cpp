//Source: https://leetcode.com/problems/two-sum/
//Date: 16.06.2020
//Solution by: David Luna
//Status: Accepted
//Runtime: 20ms
//Memory usage: 9.8 MB

#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Leetcode solution starts

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int, int>numMap;
        for(int i = 0; i < nums.size(); i++){
            if(numMap.find(target - nums[i]) != numMap.end()){
                ans.push_back(numMap.at(target - nums[i]));
                ans.push_back(i);
                return ans;
            }
            numMap.insert(pair<int,int>(nums[i], i));
        }
        return ans;
    }
};

// Leetcode solution ends

void makeTest(){
    vector<int> nums;
    int target, numElements, index1, index2;
    //Introduce the target
    cin >> target;
    //Introduce the number of elements in the nums array
    cin >> numElements;
    //Introduce the numbers of the array
    for(int i = 0; i < numElements; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    //Introduce the index of the two elements in the answer
    cin >> index1 >> index2;
    vector <int> ans1{index1, index2}, ans2{index2, index1};
    vector<int>ans = Solution().twoSum(nums, target);
    cout << "Answer:\n" << ans[0] << ' ' << ans[1] << '\n';
    if(ans == ans1|| ans == ans2){
        cout << "pass\n";
    } else {
        cout << "fail\n";
    }
}

int main(){
    int testNum;
    //Introduce number of tests to make
    cin >> testNum;
    for(int i = 0; i < testNum; i++){
        makeTest();
    }
    return 0;
}