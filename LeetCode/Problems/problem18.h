//
// 18. 4Sum
// https://leetcode.com/problems/4sum/
//
#pragma once

#include <vector>
#include <algorithm>

using namespace std;

//
namespace PROBLEM18
{
	class Solution {
	public:
		// 3sum + 1
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> ret;
			sort(nums.begin(), nums.end());
			int n = nums.size();
			for (int i = 0; i + 3 < nums.size(); i++)
			{
				if (i > 0 && nums[i] == nums[i - 1])
					continue;
				if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
					break;
				if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
					continue;

				for (int j = i + 1; j + 2 < nums.size(); j++)
				{
					if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
						break;
					if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
						continue;

					int k = j + 1, l = nums.size() - 1;
					while (l > k)
					{
						int sum = nums[i] + nums[j] + nums[k] + nums[l];
						if (sum == target)
						{
							// eureka
							ret.push_back({nums[i], nums[j], nums[k], nums[l]});
							l--;
							k++;
							while (l > 0 && nums[l] == nums[l + 1]) l--;
							while (k < nums.size() - 1 && nums[k] == nums[k - 1]) k++;
						}
						else if (sum > target)
							l--;
						else
							k++;
					}
					while (j < nums.size() - 1 && nums[j] == nums[j + 1]) j++;
				}
			}
			return ret;
		}
	};
}

using namespace PROBLEM18;