//
// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/
//
#pragma once

#include <vector>

using namespace std;

//
namespace PROBLEM31
{
	class Solution {
	public:
		void nextPermutation(vector<int>& nums) {
			if (nums.size() < 2)
				return;
			for (int i = nums.size() - 1; i > 0; i--)
			{
				if (nums[i] > nums[i - 1])
				{
					int j;
					for (j = nums.size() - 1; j > i; j--)
						if (nums[i - 1] < nums[j])
							break;
					swap(nums[i - 1], nums[j]);
					reverse(nums.end() - (nums.size() - i), nums.end());
					break;
				}
				else if (i == 1)
					reverse(nums.begin(), nums.end());
			}
		}
	};
}

using namespace PROBLEM31;
