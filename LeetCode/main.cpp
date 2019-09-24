#include "util.h"
#include "Util_String.h"
#include "DataStruct.h"

using namespace std;
using namespace LeetCode;

#include ".\problems\problem29.h"

int main()
{
	vector<string> inputs;
	utility::LoadInput(inputs);
	vector<vector<int>> p1 = utility::Input2IntVecVec(inputs[0].c_str());


	Solution s;
	int ret = s.divide(100, -3);

	//int c = getchar();
	return 0;
}

