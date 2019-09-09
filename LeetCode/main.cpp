#include "util.h"
#include "Util_String.h"

using namespace std;

#include "problem1.h"



int main()
{
	vector<string> inputs;
	utility::LoadInput(inputs);
	vector<int> a = utility::Input2IntVec(inputs[0].c_str());
	vector<vector<int>> b = utility::Input2IntVecVec(inputs[1].c_str());

	Solution s;
	
	
	getchar();
	return 0;
}

