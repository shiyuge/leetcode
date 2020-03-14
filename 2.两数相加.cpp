/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getVal(const ListNode* const node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return node->val;
        }
    }

    void inc(ListNode** node)
    {
        if (*node != NULL)
        {
            *node = (*node)->next;
        }
    }

    void push(ListNode** node, int value)
    {
        ListNode* next = new ListNode{ value };
        (*node)->next = next;
        *node = next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* result = new ListNode{ -1 };
        ListNode* begin = result;
        int bit = 0;
        while (!(l1 == NULL && l2 == NULL && bit==0))
        {
            int current_val = getVal(l1) + getVal(l2) + bit;
            if (current_val > 9)
            {
                bit = 1;
                current_val = current_val - 10;
            }
            else
            {
                bit = 0;
            }
            inc(&l1);
            inc(&l2);
            push(&result, current_val);
        }
        return begin->next;
    }
};
// @lc code=end

