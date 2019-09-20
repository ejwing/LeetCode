//
// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
//
#pragma once

#include <vector>
#include <string>

using namespace std;

//
namespace PROBLEM14
{
	class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			if (strs.empty())
				return "";
			int i = 0;
			while(i < strs[0].length())
			{
				for (int j = 1; j < strs.size(); j++)
				{
					if (strs[j].size() > i)
					{
						if (strs[j][i] != strs[0][i])
							return strs[0].substr(0, i);
					}
					else
						return strs[0].substr(0, i);
				}
				i++;
			}
			return strs[0].substr(0, i);
		}
	};
}

using namespace PROBLEM14;