#pragma once


#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;


//
namespace PROBLEM5068
{
	class Solution {

		string getFirstWord(string& str)
		{
			size_t found = str.find_first_of(" ");
			string ret = str.substr(0, found);
			return ret;
		}

		string getLastWord(string& str)
		{
			size_t found = str.find_last_of(" ");
			string ret = str.substr(found + 1);
			return ret;
		}

		string combine2String(string& first, string& second)
		{
			size_t found = first.find_last_of(" ");
			if (found != string::npos)
			{
				string ret = first.substr(0, found + 1);
				ret.append(second);
				return ret;
			}
			else
			{
				return second;
			}
		}

	public:
		vector<string> beforeAndAfterPuzzles(vector<string>& phrases)
		{
			unordered_set<string> uset;
			
			// get all first word
			unordered_map<string, vector<int>> umap;
			for (int i = 0; i < phrases.size(); i++)
			{
				string word = getFirstWord(phrases[i]);
				auto it = umap.find(word);
				if (it != umap.end())
				{
					it->second.push_back(i);
				}
				else
				{
					umap[word] = vector<int>(1, i);
				}
			}
			//
			for (int i = 0; i < phrases.size(); i++)
			{
				string word = getLastWord(phrases[i]);
				auto it = umap.find(word);
				if (it != umap.end())
				{
					for (int j = 0; j < it->second.size(); j++)
					{
						if (i != it->second[j])
						{
							string combined = combine2String(phrases[i], phrases[it->second[j]]);
							uset.insert(combined);
						}
					}
					
				}
			}
			vector<string> result;
			for (auto it = uset.begin(); it != uset.end(); it++)
				result.push_back(*it);
			sort(result.begin(), result.end());
			return result;
		}
	};
}
//
using namespace PROBLEM5068;