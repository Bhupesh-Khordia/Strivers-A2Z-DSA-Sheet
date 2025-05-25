#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/add-two-numbers/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = l1;
        ListNode* second = l2;
        int carry = 0;

        ListNode* answer = new ListNode();
        ListNode* ans = answer;
        int temp = carry + first -> val + second -> val;
        int unit = temp % 10;
        int ones = temp / 10;
        ans -> val = unit;
        carry = ones;

        while (first -> next != NULL && second -> next != NULL)  {
            first = first -> next;
            second = second -> next;
            temp = carry + first -> val + second -> val;

            unit = temp % 10;
            ones = temp / 10;

            ans -> next = new ListNode();
            ans = ans -> next;
            ans -> val = unit;
            carry = ones;
        }

        while (first -> next != NULL)  {
            first = first -> next;
            temp = carry + first -> val;

            unit = temp % 10;
            ones = temp / 10;

            ans -> next = new ListNode();
            ans = ans -> next;
            ans -> val = unit;
            carry = ones;
        }

        while (second -> next != NULL)  {
            second = second -> next;
            temp = carry + second -> val;

            unit = temp % 10;
            ones = temp / 10;

            ans -> next = new ListNode();
            ans = ans -> next;
            ans -> val = unit;
            carry = ones;
        }

        if(carry != 0) ans -> next = new ListNode(carry);

        return answer;
    }
};