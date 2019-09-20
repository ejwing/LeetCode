//
// 15. 3Sum
// https://leetcode.com/problems/3sum/
//
#pragma once

#include <vector>
#include <algorithm>

using namespace std;

//
namespace PROBLEM15
{
	class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> ret;
			if (nums.size() < 3)
				return ret;
			sort(nums.begin(), nums.end());
			int n = nums.size();
			for (int i = 0; i < nums.size() - 2; i++)
			{
				if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
					break;
				if (nums[i] + nums[n - 1] + nums[n - 2] < 0)
					continue;

				int j = i + 1, k = nums.size() - 1;
				while (k > j)
				{
					int sum = nums[i] + nums[j] + nums[k];
					if (sum == 0)
					{
						ret.push_back({ nums[i], nums[j], nums[k] });
						k--;
						j++;
						while (k > 0 && nums[k] == nums[k + 1]) k--;
						while (j < nums.size() - 1 && nums[j] == nums[j - 1]) j++;
					}
					else if (sum > 0)
						k--;
					else
						j++;
				}
				while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
			}
			return ret;
		}
	};
}

using namespace PROBLEM15;