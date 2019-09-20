#include "util.h"
#include "Util_String.h"

using namespace std;

#include ".\problems\problem20.h"

int main()
{
	vector<string> inputs;
	utility::LoadInput(inputs);
	string p1 = utility::Input2Str(inputs[0].c_str());
	

	Solution s;
	bool ret = s.isValid(p1);

	//int c = getchar();
	return 0;
}

