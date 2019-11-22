#include "util.h"
#include "Util_String.h"
#include "DataStruct.h"

using namespace std;
using namespace LeetCode;

#include ".\problems\problem31.h"

int main()
{
	vector<string> inputs;
	utility::LoadInput(inputs);
	vector<int> p1 = utility::Input2IntVec(inputs[0].c_str());

	Solution s;
	s.nextPermutation(p1);

	//int c = getchar();
	return 0;
}