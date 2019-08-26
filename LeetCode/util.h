#ifndef _UTIL_H_
#define _UTIL_H_

#include <vector>

using namespace std;

class utility
{
public:
	static void LoadInput(vector<string> &strs);
	static int Input2Int(const char *str);
	static string Input2Str(const char *str);
	static vector<int> Input2IntVec(const char *str);
	static vector<string> Input2StrVec(const char *str);
	static vector<vector<int>> Input2IntVecVec(const char *str);
	static vector<vector<char>> Input2CharVecVec(const char *str);
	static vector<vector<string>> Input2StrVecVec(const char *str);
};



#endif