//
// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
//
#pragma once

#include <vector>
#include <algorithm>

using namespace std;

//
namespace PROBLEM11
{
	class Solution {
	public:
		int maxArea(vector<int>& height) {
			int l = 0;
			int r = height.size() - 1;
			int area = 0;
			while (r > l)
			{
				area = max(area, (r - l) * min(height[l], height[r]));
				if (height[l] > height[r])
					r--;
				else
					l++;
			}
			return area;
		}
	};
}

using namespace PROBLEM11;