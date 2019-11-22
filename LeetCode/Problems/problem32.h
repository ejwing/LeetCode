//
// 32. Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/
//
#pragma once

#include <string>

using namespace std;

//
namespace PROBLEM32
{
	class Solution {
	public:
		int longestValidParentheses(string s) {
			if (s.empty())
				return 0;
			int ret = 0;

			std::size_t found = 0;
			while (found < s.length())
			{
				found = s.find("()", found);
				if (found == string::npos)
					break;
				//
				int start = found;
				int end = found + 1;
				while (1)
				{
					bool b1 = ExpandLeft(s, start, end);
					bool b2 = ExpandOut(s, start, end);
					if (!b2)
						break;
				}
				if (ret < end - start + 1)
					ret = end - start + 1;
				found = end + 1;
			}
			return ret;
		}

		bool ExpandLeft(string& str, int& start, int& end)
		{
			int pos = end + 1;
			int balance = 0, valid = -1;

			while (pos < str.length())
			{
				char c = str[pos];

				if (c == '(')
				{
					balance++;
				}
				else if (c == ')')
				{
					if (balance > 0)
					{
						balance--;
						if (balance == 0)
							valid = pos;
					}
					else
						break;
				}
				else
				{
					// should not happen
				}
				pos++;
			}
			if (valid > 0)
				end = valid;
			return valid > 0;
		}

		bool ExpandOut(string& str, int& start, int& end)
		{
			bool bExpand = false;
			while (start > 0 && end < str.length() - 1)
			{
				if (str[start - 1] == '(' && str[end + 1] == ')')
				{
					bExpand = true;
					start--;
					end++;
				}
				else
					break;
			}

			return bExpand;
		}
	};
}

using namespace PROBLEM32;
