//
// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
//
#pragma once
#include <vector>
#include "..\DataStruct.h"

using namespace std;
using namespace LeetCode;

//
namespace PROBLEM22
{
	class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			int size = lists.size();
			while (size > 1)
			{
				for (int i = 0, j = size - 1; j > i; i++, j--)
				{
					lists[i] = mergeTwoLists(lists[i], lists[j]);
				}
				size = ceil((double)size / 2);
			}
			return size ? lists.front() : NULL;
		}
		// from problem21, merge two sorted lists
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if (!l1 && !l2)
				return NULL;
			else if (!l1)
				return l2;
			else if (!l2)
				return l1;
			//
			ListNode* fakeHead = new ListNode(0), * curr = fakeHead;
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
			ListNode* head = fakeHead->next;
			delete fakeHead;
			return head;
		}
	};
}

using namespace PROBLEM22;