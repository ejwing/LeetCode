//
// 6. ZigZag Conversion
// https://leetcode.com/problems/zigzag-conversion/
//
#pragma once
#include <string>

using namespace std;

//
namespace PROBLEM6
{
	class Solution {
	public:
		string convert(string s, int numRows)
		{
			string ret = s;
			int interval = numRows > 1 ? (numRows - 1) * 2 : 1;
			int index = 0;
			for (int i = 0; i < numRows; i++)
			{
				int pos, counter = 0;
				while (1)
				{
					pos = counter * interval + i;
					if (pos >= s.length())
						break;
					ret[index++] = s[pos];
					if (i != 0 && i != numRows - 1)
					{
						pos = pos + interval - 2 * i;
						if (pos >= s.length())
							break;
						ret[index++] = s[pos];
					}
					counter++;
				}
			}
			return ret;
		}
	};
}

using namespace PROBLEM6;