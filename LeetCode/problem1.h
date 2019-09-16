//
// 1. Two Sum
// https://leetcode.com/problems/two-sum/
//
#pragma once
#include <vector>
#include <unordered_map>

using namespace std;

//
namespace PROBLEM1
{
	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> um;
			for (int i = 0; i < nums.size(); i++)
			{
				auto it = um.find(nums[i]);
				if (it != um.end())
				{
					vector<int> ret = { it->second , i };
					return ret;
				}
				else
				{
					um[target - nums[i]] = i;
				}
			}
			return vector<int>(2, -1);
		}
	};
}

using namespace PROBLEM1;