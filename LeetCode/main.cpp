#include "util.h"
#include "Util_String.h"

using namespace std;

#include "problem3.h"



int main()
{
	vector<string> inputs;
	utility::LoadInput(inputs);
	string p = utility::Input2Str(inputs[0].c_str());

	Solution s;
	int ret = s.lengthOfLongestSubstring(p);

	getchar();
	return 0;
}

