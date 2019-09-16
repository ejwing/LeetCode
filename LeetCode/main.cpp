#include "util.h"
#include "Util_String.h"

using namespace std;

#include "problem10.h"

int main()
{
	vector<string> inputs;
	utility::LoadInput(inputs);
	string p1 = utility::Input2Str(inputs[0].c_str());
	string p2 = utility::Input2Str(inputs[1].c_str());

	Solution s;
	bool ret = s.isMatch(p1, p2);

	int c = getchar();
	return 0;
}

