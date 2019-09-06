#pragma once

#include <stddef.h>


namespace LeetCode
{
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

}