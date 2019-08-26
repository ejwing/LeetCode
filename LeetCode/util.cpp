#include "util.h"

#include <fstream>
#include <sstream>


void utility::LoadInput(vector<string> &strs)
{
	ifstream infile("inputs.txt");
	string line;
	int balance = 0;
	while (getline(infile, line))
	{
		if (balance == 0)
			strs.push_back(line);
		else
			strs.back().append(line);

		std::size_t found = line.find("[");
		while (found != string::npos)
		{
			balance++;
			found = line.find("[", found + 1);
		}
		found = line.find("]");
		while (found != string::npos)
		{
			balance--;
			found = line.find("]", found + 1);
		}
	}
}

int utility::Input2Int(const char *str)
{
	vector<int> nums = Input2IntVec(str);
	return nums.empty() ? 0 : nums[0];
}

string utility::Input2Str(const char *str)
{
	vector<string> strs = Input2StrVec(str);
	return strs.empty() ? "" : strs[0];
}

vector<int> utility::Input2IntVec(const char *str)
{
	char *_str = new char[strlen(str) + 1], *pch;
	memcpy(_str, str, sizeof(char) * (strlen(str) + 1));
	vector<int> nums;
	pch = strtok(_str, " ,[]");
	while (pch != NULL)
	{
		if (strlen(pch) > 0)
			nums.push_back(atoi(pch));
		pch = strtok(NULL, " ,[]");
	}
	delete [] _str;
	return nums;
}

vector<string> utility::Input2StrVec(const char *str)
{
	vector<string> strs;
	int s = -1;
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		char c = *(str + i);
		if (c == '"')
		{
			if (s < 0)
				s = i;
			else
			{
				string str(str + s + 1, str + i);
				strs.push_back(str);
				s = -1;
			}
		}
	}

	return strs;
}

vector<vector<int>> utility::Input2IntVecVec(const char *str)
{
	vector<vector<int>> ret;
	int balance = 0, pos = 0, s = -1;
	while (1)
	{
		char c = *(str + pos);
		if (c == '[')
		{
			balance++;
			if (balance == 2)
				s = pos;
		}
		else if (c == ']')
		{
			balance--;
			if (balance == 1 && s >= 0)
			{
				string _str(str + s, pos - s);
				ret.push_back(Input2IntVec(_str.c_str()));
				s = -1;
			}
			else if (balance == 0)
				break;
		}
		else if (c == '\0')
			break;
		pos++;
	}

	return ret;
}

vector<vector<char>> utility::Input2CharVecVec(const char *str)
{
	vector<vector<string>> svv = Input2StrVecVec(str);
	vector<vector<char>> ret;
	for (auto it1 = svv.begin(); it1 != svv.end(); it1++)
	{
		ret.push_back(vector<char>());
		for (auto it2 = it1->begin(); it2 != it1->end(); it2++)
		{
			ret.back().push_back((*it2)[0]);
		}
	}

	return ret;
}

vector<vector<string>> utility::Input2StrVecVec(const char *str)
{
	vector<vector<string>> ret;
	int balance = 0, pos = 0, s = -1;
	while (1)
	{
		char c = *(str + pos);
		if (c == '[')
		{
			balance++;
			if (balance == 2)
				s = pos;
		}
		else if (c == ']')
		{
			balance--;
			if (balance == 1 && s >= 0)
			{
				string _str(str + s, pos - s);
				ret.push_back(Input2StrVec(_str.c_str()));
				s = -1;
			}
			else if (balance == 0)
				break;
		}
		else if (c == '\0')
			break;
		pos++;
	}

	return ret;
}