//
// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//
#pragma once
#include <vector>

using namespace std;

//
namespace PROBLEM26
{
	class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			// special cases
			if (nums.size() == 0)
				return 0;
			else if (nums.size() == 1)
				return 1;
			//
			int ret = 1, num;
			vector<int>::iterator it1, it2;
			it1 = nums.begin();
			num = *it1;
			it2 = it1 + 1;
			while (it2 != nums.end())
			{
				if (*it2 != num)
				{
					it1++;
					*it1 = *it2;
					num = *it2;
					ret++;
				}
				it2++;
			}
			return ret;
		}
	};
}

using namespace PROBLEM26;