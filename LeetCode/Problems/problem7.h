//
// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/
//
#pragma once
#include <climits>

using namespace std;

//
namespace PROBLEM7
{
	class Solution {
	public:
		int reverse(int x)
		{
			int ret = 0, check1 = INT_MAX / 10, check2 = INT_MIN / 10;
			while (x)
			{
				if (ret > check1 || ret < check2)
					return 0;
				ret = ret * 10 + x % 10;
				x = x / 10;
			}
			return ret;
		}
	};
}

using namespace PROBLEM7;