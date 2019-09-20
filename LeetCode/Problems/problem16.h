//
// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/
//
#pragma once

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//
namespace PROBLEM16
{
	class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {
			if (nums.size() < 3)
				return 0;
			int ret = nums[0] + nums[1] + nums[2];
			sort(nums.begin(), nums.end());
			for (int i = 0; i < nums.size() - 2; i++)
			{
				int j = i + 1;
				int k = nums.size() - 1;
				while (k > j)
				{
					int sum = nums[i] + nums[j] + nums[k];
					int diff = sum - target;
					if (abs(target - ret) > abs(diff))
						ret = sum;

					if (diff == 0)
						return sum;
					else if (diff > 0)
					{
						k--;
						while (k > 0 && nums[k] == nums[k + 1]) k--;
					}
					else
					{
						j++;
						while (j < nums.size() - 1 && nums[j] == nums[j - 1]) j++;
					}
				}
			}
			return ret;
		}
	};
}

using namespace PROBLEM16;