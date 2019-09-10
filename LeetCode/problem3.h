//
// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
//

#include <vector>
#include "DataStruct.h"

using namespace std;
using namespace LeetCode;

//

namespace PROBLEM3
{
	class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int ret = 0, start = 0, len = 0;
			vector<bool> vUsed(128, false);

			for (int i = 0; i < s.length(); i++)
			{
				int c = s[i];
				if (vUsed[c])
				{
					bool bFound = false;
					while (!bFound)
					{
						int _c = s[start];
						vUsed[_c] = false;
						if (c == _c)
							bFound = true;
						start++;
						len--;
					}
					//
					vUsed[c] = true;
					len++;
				}
				else
				{
					vUsed[c] = true;
					len++;
					if (len > ret)
						ret = len;
				}
			}


			return ret;
		}
	};
}

using namespace PROBLEM3;