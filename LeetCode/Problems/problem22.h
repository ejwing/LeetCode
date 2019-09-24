//
// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/
//
#pragma once
#include <vector>
#include <string>

using namespace std;

//
namespace PROBLEM22
{
	class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			vector<string> strs;
			string str(n * 2, ' ');
			generateParenthesis(strs, str, 0, n, n);
			return strs;
		}

		void generateParenthesis(vector<string> &strs, string &str, int pos, int l, int r) {
			if (!l && !r)
			{
				strs.push_back(str);
				return;
			}
			if (l > 0)
			{
				str[pos] = '(';
				generateParenthesis(strs, str, pos + 1, l - 1, r);
			}
			if (r > l)
			{
				str[pos] = ')';
				generateParenthesis(strs, str, pos + 1, l, r - 1);
			}
		}
	};
}

using namespace PROBLEM22;