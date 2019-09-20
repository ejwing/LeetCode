//
// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//
#pragma once

#include <vector>
#include <string>

using namespace std;

//
namespace PROBLEM17
{
	class Solution {
	public:
		static const char* d2c[];
		vector<string> letterCombinations(string digits) {
			return method1(digits);
		}
		// assign vector size in the beginning and fill the characters
		vector<string> method1(string digits) {
			if (digits.empty())
				return vector<string>();
			int size = 1;
			for (int i = 0; i < digits.length(); i++)
				size = size * strlen(d2c[digits[i] - '0']);
			vector<string> strs(size, digits);
			int repeat = 1;
			for (int i = 0; i < digits.length(); i++)
			{
				int len = strlen(d2c[digits[i] - '0']);

				for (int j = 0, k = 0, l = 0; j < strs.size(); j++, k++)
				{
					if (k == repeat)
					{
						k = 0;
						l++;
						if (l == len)
							l = 0;
					}
					char c = d2c[digits[i] - '0'][l];
					strs[j][i] = c;
				}
				repeat = repeat * len;
			}
			return strs;
		}
		// recurrsive
		vector<string> method2(string digits) {
			vector<string> strs;
			if (digits.length() > 0)
			{
				vector<string> _strs = method2(digits.substr(1));
				int i = digits[0] - 0x30;
				for (int j = 0; d2c[i][j] != '\0'; j++)
				{
					if (_strs.size() > 0)
					{
						for (int k = 0; k < _strs.size(); k++)
						{
							string str;
							str.append(d2c[i], j, 1);
							str.append(_strs[k]);
							strs.push_back(str);
						}
					}
					else
					{
						string str;
						str.append(d2c[i], j, 1);
						strs.push_back(str);
					}
				}
			}
			return strs;
		}
	};
	const char* Solution::d2c[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
}

using namespace PROBLEM17;