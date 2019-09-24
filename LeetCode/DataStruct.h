#pragma once


#include <vector>

using namespace std;

namespace LeetCode
{
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	ListNode* CreateList(vector<int>& nums)
	{
		ListNode* fakeHead = new ListNode(0), *curr = fakeHead;
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			curr->next = new ListNode(*it);
			curr = curr->next;
		}
		curr = fakeHead->next;
		delete fakeHead;
		return curr;
	}

	vector<ListNode*> CreateListVec(vector<vector<int>>& nums)
	{
		vector<ListNode*> result;
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			ListNode* node = CreateList(*it);
			if (node)
				result.push_back(node);
		}
		return result;
	}

	void ReleaseList(ListNode* head)
	{
		while (head)
		{
			ListNode *node = head;
			head = head->next;
			delete node;
		}
	}

	void ReleaseListVec(vector<ListNode*>& lists)
	{
		for (auto it = lists.begin(); it != lists.end(); it++)
		{
			ReleaseList(*it);
		}
	}
}