//
// 30. Substring with Concatenation of All Words
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//
#pragma once

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//
namespace PROBLEM30
{
	class Solution {
	public:
		vector<int> findSubstring(string s, vector<string>& words) {
			vector<int> ret;
			if (s.empty() || words.empty())
				return ret;
			//
			size_t len = words[0].length();
			unordered_map<std::string, int> strs(len);
			for (int i = 0; i < words.size(); i++)
			{
				auto it = strs.find(words[i]);
				if (it == strs.end())
					strs[words[i]] = 1;
				else
					it->second += 1;
			}
			//
			for (int i = 0; i < len; i++)
			{
				int start = i, curr = i, count = words.size();
				while (curr + len - 1 < s.length())
				{
					auto it = strs.find(s.substr(curr, len));
					if (it != strs.end())
					{
						if (it->second > 0)
						{
							curr += len;
							it->second--;
							count--;
						}
						else
						{
							auto _it = strs.find(s.substr(start, len));
							_it->second++;
							start += len;
							count++;
						}
					}
					else
					{
						// reset strs
						while (curr != start)
						{
							auto _it = strs.find(s.substr(start, len));
							_it->second++;
							start += len;
							count++;
						}
						start = curr = curr + len;
					}
					// is match all words
					if (count == 0)
					{
						// add the first word count in strs, move start postion to next word
						ret.push_back(start);
						auto _it = strs.find(s.substr(start, len));
						_it->second++;
						start += len;
						count++;
					}
				}
				// reset strs
				while (count != words.size())
				{
					auto _it = strs.find(s.substr(start, len));
					_it->second++;
					start += len;
					count++;
				}
			}
			return ret;
		}
	};
}

using namespace PROBLEM30;
