//
// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//
#pragma once
#include "datastruct.h"

using namespace std;
using namespace LeetCode;

//
namespace PROBLEM19
{
	class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode *tmp = head, *tmp_n = NULL;
			int i = 0;
			while (tmp)
			{
				if (i == n)
					tmp_n = head;
				else if (i > n)
					tmp_n = tmp_n->next;
				tmp = tmp->next;
				i++;
			}
			//
			if (tmp_n)
			{
				ListNode* del = tmp_n->next;
				tmp_n->next = del->next;
				delete del;
			}
			else if (n == i)
			{
				ListNode* del = head;
				head = head->next;
				delete del;
			}
			return head;
		}
	};
}

using namespace PROBLEM19;