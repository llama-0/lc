/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
	
*/
#include <iostream>
#include <vector>

using namespace std;

// the first solution
// time complexity is about O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index_i, index_j;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            index_i = i;
            int tmp = target - nums[index_i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == tmp) {
                    index_j = j;
                    res.push_back(index_i);
                    res.push_back(index_j);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    int target = 6;
    vector<int> res = solution.twoSum(v, target);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}