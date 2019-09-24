//
// 27. Remove Element
// https://leetcode.com/problems/remove-element/
//
#pragma once
#include <vector>

using namespace std;

//
namespace PROBLEM27
{
	class Solution {
	public:
		int removeElement(vector<int>& nums, int val) {
			int curr = 0;
			for (int i = 0; i < nums.size(); i++)
				if (nums[i] != val)
					nums[curr++] = nums[i];
			return curr;
		}
	};
}

using namespace PROBLEM27;