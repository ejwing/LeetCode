#include "util.h"
#include "Util_String.h"

using namespace std;

#include "problem4.h"



int main()
{
	vector<string> inputs;
	utility::LoadInput(inputs);
	vector<int> n1 = utility::Input2IntVec(inputs[0].c_str());
	vector<int> n2 = utility::Input2IntVec(inputs[1].c_str());

	Solution s;
	double ret = s.findMedianSortedArrays(n1, n2);

	int c = getchar();
	return 0;
}

