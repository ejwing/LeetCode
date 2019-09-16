//
// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
//
#pragma once
#include <string>
#include "DataStruct.h"

using namespace std;

//

namespace PROBLEM5
{
	class Solution {
	
	public:
		string longestPalindrome(string s)
		{
			return method1(s);
		}
	private:
		// find the maximum length of Palindrom from index i
		string method1(string& s)
		{
			int len = s.size();
			int strstart = 0, strend = 0;
			int pLen = 0;
			//
			for (int i = 0; i < len; i++)
			{
				int counter = 0, sub_len = 0;
				int pos1 = 0, pos2 = 0;
				// the length is odd
				while (1)
				{
					pos1 = i - (1 + counter);
					pos2 = i + (1 + counter);
					if (pos1 < 0 || pos2 >= len || s[pos1] != s[pos2])
						break;
					else/* if(s[pos1] == s[pos2])*/
						counter++;
				}
				sub_len = counter * 2 + 1;
				if (sub_len > pLen)
				{
					strstart = pos1 + 1;
					strend = pos2 - 1;
					pLen = sub_len;
				}
				// the length is even
				counter = 0;
				while (1)
				{
					pos1 = i - counter;
					pos2 = i + counter + 1;
					if (pos1 < 0 || pos2 >= len || s[pos1] != s[pos2])
						break;
					else/* if(s[pos1] == s[pos2])*/
						counter++;
				}
				sub_len = counter * 2;
				if (sub_len > pLen)
				{
					strstart = pos1 + 1;
					strend = pos2 - 1;
					pLen = sub_len;
				}
			}
			//
			return s.substr(strstart, strend - strstart + 1);
		}
		// f(x, y) is true -> Substring from index x to y is Palindrome
		// f(x, y) = f(x + 1, y - 1) and String(x) == String(y)
		// -- longer than method1
		string method_DP(string& s)
		{
			if (s.empty())
				return "";
			int len = 1, start = 0;
			bool* pDP = new bool[s.length()];
			memset(pDP, true, s.length());
			for (int i = 0; i < s.length(); i++)
			{
				for (int j = 0; j < i; j++)
				{
					pDP[j] = pDP[j + 1] && s[i] == s[j];
					if (pDP[j] && i - j + 1 > len)
					{
						len = i - j + 1;
						start = j;
					}
				}
			}
			return s.substr(start, len);
		}
	};

}

using namespace PROBLEM5;