//
// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/
//
#pragma once
#include <climits>

using namespace std;

//
namespace PROBLEM9
{
	class Solution {
	public:
		bool isPalindrome(int x) {
			return method1(x);
		}
	private:
		bool method1(int x)
		{
			if (x < 0)
				return false;
			char digits[10];
			memset(digits, '\0', 10);
			int index = 0;
			while (x)
			{
				digits[index++] = x % 10 + '0';
				x = x / 10;
			}
			for (int i = 0; i < index / 2; i++)
			{
				if (digits[i] != digits[index - i - 1])
					return false;
			}
			return true;
		}
		// reverse and compare
		bool method2(int x)
		{
			return x >= 0 ? reverse(x) == x : false;
		}
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

using namespace PROBLEM9;