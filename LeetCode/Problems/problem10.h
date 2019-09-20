//
// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/
//
#pragma once
#include <string>
#include <vector>

using namespace std;

//
namespace PROBLEM10
{
	class Solution {
	public:
		bool isMatch(string s, string p)
		{
			bool** dp = new bool* [s.length() + 1];
			for (int i = 0; i < s.length() + 1; i++)
				dp[i] = new bool[p.length() + 1];
			for (int i = 0; i < s.length(); i++)
				dp[i][p.length()] = false;
			dp[s.length()][p.length()] = true;

			for (int i = s.length(); i >= 0; i--)
			{
				for (int j = p.length() - 1; j >= 0; j--)
				{
					bool _m = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
					if (j + 1 < p.length() && p[j + 1] == '*') 
						dp[i][j] = dp[i][j + 2] || (_m && dp[i + 1][j]);
					else
						dp[i][j] = _m && dp[i + 1][j + 1];
				}
			}
			return dp[0][0];
		}
	};
}

using namespace PROBLEM10;