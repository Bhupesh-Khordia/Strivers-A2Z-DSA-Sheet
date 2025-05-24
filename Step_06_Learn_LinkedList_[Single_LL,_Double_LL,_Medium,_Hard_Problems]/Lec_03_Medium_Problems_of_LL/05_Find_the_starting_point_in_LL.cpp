#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/linked-list-cycle-ii/description/

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
    ListNode *detectCycle(ListNode *head) {
        // Floyd's cycle detection algorithm
        ListNode* fast = head;
        ListNode* slow = head;
        bool cycle = false;

        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;

            if(fast == slow) {
                cycle = true;
                break;
            }
        }
        
        if(!cycle) return nullptr;

        slow = head;
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};