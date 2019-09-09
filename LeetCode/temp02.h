#pragma once


#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;


//
namespace PROBLEM5070
{
	class Solution {


	public:
		vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries)
		{
			vector<int> dist1(1, -1), dist2(1, -1), dist3(1, -1);
			for (auto it = colors.rbegin(); it != colors.rend(); it++)
			{
				if (*it == 1)
				{
					dist1.push_back(0);
					dist2.push_back(dist2.back() == -1 ? - 1 : dist2.back() + 1);
					dist3.push_back(dist3.back() == -1 ? - 1 : dist3.back() + 1);
				}
				else if (*it == 2)
				{
					dist1.push_back(dist1.back() == -1 ? -1 : dist2.back() + 1);
					dist2.push_back(0);
					dist3.push_back(dist3.back() == -1 ? -1 : dist3.back() + 1);
				}
				else if (*it == 3)
				{
					dist1.push_back(dist1.back() == -1 ? -1 : dist2.back() + 1);
					dist2.push_back(dist2.back() == -1 ? -1 : dist2.back() + 1);
					dist3.push_back(0);
				}
			}
			reverse(dist1.begin(), dist1.end());
			dist1.pop_back();
			reverse(dist2.begin(), dist2.end());
			dist2.pop_back();
			reverse(dist3.begin(), dist3.end());
			dist3.pop_back();
			//
			vector<int> ret;
			for (int i = 0; i < queries.size(); i++)
			{
				int idx = queries[i][0];
				int clr = queries[i][1];
				if (clr == 1)
					ret.push_back(dist1[idx]);
				else if(clr == 2)
					ret.push_back(dist2[idx]);
				else if (clr == 3)
					ret.push_back(dist3[idx]);
			}
			return ret;
		}
	};
}

//
using namespace PROBLEM5070;