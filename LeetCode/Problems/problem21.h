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
			ListNode *head = NULL;
			ListNode *curr = NULL;
			while (l1 || l2)
			{
				ListNode *tmp;
				if (l1 && l2)
				{
					if (l1->val < l2->val)
					{
						tmp = l1;
						l1 = l1->next;
					}
					else
					{
						tmp = l2;
						l2 = l2->next;
					}
				}
				else if (l1)
				{
					tmp = l1;
					l1 = l1->next;
				}
				else if (l2)
				{
					tmp = l2;
					l2 = l2->next;
				}

				if (!head)
				{
					head = tmp;
					curr = head;
				}
				else
				{
					curr->next = tmp;
					curr = tmp;
				}
			}
			return head;
		}
	};
}

using namespace PROBLEM21;