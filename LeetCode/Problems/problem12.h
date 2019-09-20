//
// 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/
//
#pragma once

#include <string>

using namespace std;

//
namespace PROBLEM12
{
	class Solution {
	public:
		string intToRoman(int num) {
			char* rs = "IIIVIIIXXXLXXXCCCDCCCMMM";
			int sl[31][2] = {
				{0, 0},
				{0,	1}, {0,	2}, {0,	3}, {2,	2}, {3,	1}, {3,	2}, {3,	3}, {3,	4}, {6, 2},
				{7,	1}, {7,	2}, {7,	3}, {9,	2}, {10,1}, {10,2}, {10,3}, {10,4}, {13,2},
				{14,1}, {14,2}, {14,3}, {16,2}, {17,1}, {17,2}, {17,3}, {17,4}, {20,2},
				{21,1}, {21,2}, {21,3}
			};

			char* roman = new char[16];
			int pos = 0;
			int n1 = num % 10;
			num /= 10;
			int n2 = num % 10;
			num /= 10;
			int n3 = num % 10;
			int n4 = num / 10;
			if (n4)
			{
				memcpy(roman + pos, rs + sl[n4 + 27][0], sl[n4 + 27][1]);
				pos += sl[n4 + 27][1];
			}
			if (n3)
			{
				memcpy(roman + pos, rs + sl[n3 + 18][0], sl[n3 + 18][1]);
				pos += sl[n3 + 18][1];
			}
			if (n2)
			{
				memcpy(roman + pos, rs + sl[n2 + 9][0], sl[n2 + 9][1]);
				pos += sl[n2 + 9][1];
			}
			if (n1)
			{
				memcpy(roman + pos, rs + sl[n1][0], sl[n1][1]);
				pos += sl[n1][1];
			}
			roman[pos] = '\0';
			string ret = roman;
			delete [] roman;
			return ret;
		}
	};
}

using namespace PROBLEM12;