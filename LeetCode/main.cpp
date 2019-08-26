#include <stdio.h>
#include <Windows.h>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <unordered_set>

using namespace std;

#include "util.h"
#include "Util_String.h"

class Solution {
private:
	bool isLeapYear(int y)
	{
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y % 3200 != 0))
			return true;
		return false;
	}
	vector<string> SplitString(const char * target, const char * splitter)
	{
		vector<string> vStrs;
		char *str = new char[strlen(target) + 1], *pch;
		memcpy(str, target, strlen(target) + 1);
		pch = strtok(str, splitter);
		while (pch != NULL)
		{
			vStrs.push_back(pch);
			pch = strtok(NULL, splitter);
		}
		delete[] str;
		return vStrs;
	}
public:
	int dayOfYear(string date) {
		vector<string> strs = SplitString(date.c_str(), "-");
		int y = atoi(strs[0].c_str());
		int m = atoi(strs[1].c_str());
		int d = atoi(strs[2].c_str());

		bool isLeap = isLeapYear(y);

		int days[]	   = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int leapdays[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		int *_days = isLeap ? leapdays : days;
		int ret = d;
		for (int i = 0; i < m - 1; i++)
		{
			ret += _days[i];
		}
		return ret;
	}
};

int main()
{
	vector<string> inputs;
	utility::LoadInput(inputs);
	string p = utility::Input2Str(inputs[0].c_str());

	Solution sol;
	int ret = sol.dayOfYear(p);
	printf("result = %d", ret);

	printf("\npause\n");
	getchar();
	return 0;
}

