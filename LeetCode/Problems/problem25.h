//
// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/
//
#pragma once
#include "..\DataStruct.h"

using namespace std;
using namespace LeetCode;

//
namespace PROBLEM25
{
	class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			if (k == 1)
				return head;
			ListNode* ret = head, * s = head, * e = head, * pre = NULL;
			while (1)
			{
				for (int i = 1; i < k && e; i++)
					e = e->next;
				if (e)
				{
					ReverseList(s, e);
					if (pre)
						pre->next = e;
				}
				else
					break;
				// set new head note as result
				if (ret == head)
					ret = e;
				//
				pre = s;
				s = s->next;
				e = s;
			}

			return ret;
		}

		void ReverseList(ListNode* b, ListNode* e)
		{
			if (b == e)
				return;
			ListNode* n1 = b, * n2 = b->next;
			while (n1 != e)
			{
				ListNode* n3 = n2->next;
				n2->next = n1;

				n1 = n2;
				n2 = n3;
			}
			b->next = n2;
		}
	};
}

using namespace PROBLEM25;