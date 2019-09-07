//
// 1. Two Sum
// http://https://leetcode.com/problems/two-sum/
//

#include <vector>
#include <unordered_map>

using namespace std;
using namespace PROBLEM1;

//
namespace PROBLEM1
{
	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> um;
			for (int i = 0; i < nums.size(); i++)
			{
				auto it = um.find(nums[i]);
				if (it != um.end())
				{
					vector<int> ret = { it->second , i };
					return ret;
				}
				else
				{
					um[target - nums[i]] = i;
				}
			}
			return vector<int>(2, -1);
		}
	};
}
