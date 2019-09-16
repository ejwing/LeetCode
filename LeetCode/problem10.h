//
// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/
//
#pragma once
#include <string>
#include <vector>

using namespace std;

//
namespace PROBLEM7
{
	class Solution {
	public:
		bool isMatch(string s, string p)
		{
			// parse pattern
			vector<char> vChars;
			for (int i = 0; i < p.length(); i++)
			{
				if ((p[i] >= 'a' && p[i] <= 'z') || p[i] == '.')
					vChars.push_back(p[i]);
				else if (p[i] == '*')
					vChars[vChars.size() - 1] = vChars[vChars.size() - 1] | 0x80;
			}

			// match the sentence
			int pos1 = 0, pos2 = 0;
			int size1 = s.length();
			int size2 = vChars.size();
			vector<int> vBranch1, vBranch2;
			while (1)
			{

				if (pos1 == size1 && pos2 == size2)
					break;
				char c1 = pos1 == size1 ? 0 : s[pos1];
				char c2 = pos2 == size2 ? 0 : vChars[pos2];
				if (c1 && c2)
				{
					if (c1 == (c2 & 0x7F) || '.' == (c2 & 0x7F))
					{
						if ((c2 & 0x80) == 0)
							pos2++;
						else
						{
							vBranch1.push_back(pos1);
							vBranch2.push_back(pos2);
						}
						pos1++;
					}
					else if (c2 & 0x80)
					{
						pos2++;
					}
					else
					{	// backward
						if (vBranch1.empty() || vBranch2.empty())
							return false;
						else
						{
							pos1 = vBranch1.back();
							pos2 = vBranch2.back() + 1;
							vBranch1.pop_back();
							vBranch2.pop_back();
						}
					}
				}
				else if (c2 & 0x80)
				{
					pos2++;
				}
				else
				{	// backward
					if (vBranch1.empty() || vBranch2.empty())
						return false;
					else
					{
						pos1 = vBranch1.back();
						pos2 = vBranch2.back() + 1;
						vBranch1.pop_back();
						vBranch2.pop_back();
					}
				}
			}

			return true;
		}
	};
}

using namespace PROBLEM7;