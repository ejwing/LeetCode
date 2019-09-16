//
// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
//
#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//
namespace PROBLEM4
{
	class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			vector<int>& _nums1 = nums1.size() >= nums2.size() ? nums1 : nums2;
			vector<int>& _nums2 = nums1.size() < nums2.size() ? nums1 : nums2;
			size_t len1 = _nums1.size();
			size_t len2 = _nums2.size();
			size_t len3 = len1 + len2;
			size_t lenhalf = len3 / 2;
			bool bOdd = len3 % 2;

			size_t pick11 = len1 / 2, pick12, pick21, pick22;
			size_t leftbound = 0, rightbound = len1 + 1;
			while(1)
			{
				pick21 = lenhalf - pick11;
				int a1, a2, b1, b2, c1, c2;
				a1 = pick11 > 0 ? _nums1[pick11 - 1] : INT_MIN;
				a2 = pick11 < len1 ? _nums1[pick11] : INT_MAX;
				b1 = pick21 > 0 ? _nums2[pick21 - 1] : INT_MIN;
				b2 = pick21 < len2 ? _nums2[pick21] : INT_MAX;
				c1 = min(a2, b2);
				c2 = max(a1, b1);
				c1 = c1 == INT_MAX ? c2 : c1;
				if (c1 >= c2)
				{
					if (bOdd)
						return c1;
					else
						return ((double)c1 + c2) / 2;
				}
				else if (a1 > c1)
				{
					rightbound = pick11;
					pick11 = (pick11 + leftbound) / 2;
					pick11 = lenhalf - pick11 >= len2 ? lenhalf - len2 : pick11;
				}
				else
				{
					leftbound = pick11 + 1;
					pick11 = (pick11 + rightbound) / 2;
					pick11 = pick11 > lenhalf ? lenhalf : pick11;
				}
			}
		}
	};
}

using namespace PROBLEM4;
