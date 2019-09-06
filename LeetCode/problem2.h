//
// 2. Add Two Numbers
// http://leetcode.com/problems/add-two-numbers/
//

#include <vector>
#include "DataStruct.h"

using namespace std;
using namespace PROBLEM2;
using namespace LeetCode;

//

namespace PROBLEM2
{
	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			bool bCarry = false;
			ListNode *head = NULL, *tail = NULL;
			while (l1 || l2 || bCarry)
			{
				int sum = bCarry ? 1 : 0;
				if (l1)
				{
					sum += l1->val;
					l1 = l1->next;
				}
				if (l2)
				{
					sum += l2->val;
					l2 = l2->next;
				}

				bCarry = sum / 10;
				sum = sum % 10;
				if (!head)
				{
					head = new ListNode(sum);
					tail = head;
				}
				else
				{
					tail->next = new ListNode(sum);
					tail = tail->next;
				}
			}
			return head;
		}
	};
}