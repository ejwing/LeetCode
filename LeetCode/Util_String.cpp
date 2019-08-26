#include "Util_String.h"


vector<string> Util_String::SplitString(const char * target, const char * splitter)
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
	delete [] str;
	return vStrs;
}