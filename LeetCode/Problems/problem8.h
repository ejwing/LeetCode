//
// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/
//
#pragma once

#include <string>
#include <vector>
using namespace std;

//
namespace PROBLEM8
{
	class Solution {
	public:
		int myAtoi(string str)
		{
			int index = 0, s = -1, len = 0;
			// skip white spaces
			for (; index < str.length(); index++)
			{
				if (str[index] != ' ')
					break;
			}
			// get sign
			int nSign = 1;
			if (str[index] == '+' || str[index] == '-')
			{
				nSign = str[index++] == '+' ? 1 : -1;
			}
			
			// get digits
			for (; index < str.length(); index++)
			{
				if (isdigit(str[index]))
				{
					if (s < 0)
						s = index;
					len++;
				}
				else
					break;
			}
			// get the number
			int result = 0, check1 = INT_MAX / 10, check2 = INT_MIN / 10;;
			for (int i = s; i < s + len; i++)
			{
				int n = str[i] - '0';
				if (result > check1)
					return INT_MAX;
				else if (result < check2)
					return INT_MIN;
				result = result * 10;
				if (result > 0 && INT_MAX - result < n)
					return INT_MAX;
				else if (result < 0 && INT_MIN + n > result)
					return INT_MIN;
				result = result + n * nSign;
			}
			return result;
		}
	};
}

using namespace PROBLEM8;