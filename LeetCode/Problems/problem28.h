//
// 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/
//
#pragma once
#include <string>

using namespace std;

//
namespace PROBLEM28
{
	class Solution {
	public:
		int strStr(string haystack, string needle) {
			const char* h = haystack.c_str();
			const char* n = needle.c_str();
			size_t hlen = haystack.length(), nlen = needle.length();
			for (int i = 0; i + nlen <= hlen; i++)
			{
				if (memcmp(h + i, n, nlen) == 0)
					return i;
			}
			return -1;
		}
	};
}

using namespace PROBLEM28;
