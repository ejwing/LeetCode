//
// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//
#pragma once

#include <string>
#include <vector>
#include <stack>
using namespace std;

//
namespace PROBLEM20
{
	class Solution {
	public:
		bool isValid(string str) {
			stack<char> s;
			for (int i = 0; i < str.length(); i++)
			{
				char c = str[i];
				if (c == '(' || c == '[' || c == '{')
					s.push(c);
				else if ((c == ')' || c == ']' || c == '}') && s.empty())
					return false;
				// '('   ')'   '['   ']'   '{'   '}'
				// 0x28  0x29  0x5B  0x5D  0x7B  0x7D
				else if (c - s.top() == 1 || c - s.top() == 2)
				{
					s.pop();	
				}
				else
					return false;
			}
			return s.empty();
		}
	};
}

using namespace PROBLEM20;