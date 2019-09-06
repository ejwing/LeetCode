//
// 1. Two Sum
// http://https://leetcode.com/problems/two-sum/
//

#include <vector>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		unordered_map<int, int> um;
		for (int i = 0; i < nums.size(); i++)
		{
			auto it = um.find(nums[i]);
			if (it != um.end())
			{
				ret.push_back(it->second);
				ret.push_back(i);
				return ret;
			}
			else
			{
				um[target - nums[i]] = i;
			}
		}
		ret.push_back(-1);
		ret.push_back(-1);
		return ret;
	}
};