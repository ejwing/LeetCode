//
// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/
//
#pragma once

#include <string>

using namespace std;

//
namespace PROBLEM13
{
	class Solution {
	public:
		int romanToInt(string s) {
			int i = 0;
			int ret = 0;
			while (i < s.length())
			{
				if (s[i] == 'M')
					ret += 1000;
				else if (s[i] == 'D')
					ret += 500;
				else if (s[i] == 'C')
				{
					if ((i + 1 < s.length()) && (s[i + 1] == 'M' || s[i + 1] == 'D'))
						ret -= 100;
					else
						ret += 100;
				}
				else if (s[i] == 'L')
					ret += 50;
				else if (s[i] == 'X')
				{
					if ((i + 1 < s.length()) && (s[i + 1] == 'C' || s[i + 1] == 'L'))
						ret -= 10;
					else
						ret += 10;
				}
				else if (s[i] == 'V')
					ret += 5;
				else if (s[i] == 'I')
				{
					if ((i + 1 < s.length()) && (s[i + 1] == 'X' || s[i + 1] == 'V'))
						ret -= 1;
					else
						ret += 1;
				}
				i++;
			}

			return ret;
		}
	};
}

using namespace PROBLEM13;