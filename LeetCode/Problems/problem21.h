//
// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
//
#pragma once
#include "..\DataStruct.h"

using namespace std;
using namespace LeetCode;

//
namespace PROBLEM21
{
	class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if (!l1 && !l2)
				return NULL;
			else if (!l1)
				return l2;
			else if (!l2)
				return l1;
			//
			ListNode *fakeHead = new ListNode(0), *curr = fakeHead;
			while (l1 && l2)
			{
				if (l1->val < l2->val)
				{
					curr->next = l1;
					l1 = l1->next;
				}
				else
				{
					curr->next = l2;
					l2 = l2->next;
				}
				curr = curr->next;
			}
			//
			if (l1 || l2)
			{
				if (l1)
					curr->next = l1;
				else
					curr->next = l2;
			}
			//
			ListNode *head = fakeHead->next;
			delete fakeHead;
			return head;
		}
	};
}

using namespace PROBLEM21;