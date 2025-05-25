#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-list/description/

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
private:
    ListNode* getMiddle (ListNode* head) {
        ListNode* fast = head -> next;
        ListNode* slow = head;
        while (fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* merge (ListNode*& first, ListNode*& second) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(first && second) {
            if(first -> val < second -> val) {
                temp -> next = first;
                first = first -> next;
            } else {
                temp -> next = second;
                second = second -> next;
            }
            temp = temp -> next;
        }
        if(first) {
            temp -> next = first;
        } else {
            temp -> next = second;
        }
        return dummyNode -> next;
    }
public:
    ListNode* sortList(ListNode* head) {
        // Using Merge Sort.

        //Base Case
        if (head == NULL || head -> next == NULL) {
            return head;
        }

        // Split LL in half
        ListNode* mid = getMiddle (head);
        ListNode* second = mid -> next;
        mid-> next = NULL;

        //Sort both halves by recursion
        ListNode* sorted1 = sortList(head);
        ListNode* sorted2 = sortList(second);

        //Merge 2 sorted LL
        if(sorted1 -> val <= sorted2 -> val) {
            ListNode* ans = merge(sorted1, sorted2);
            return ans;
        }

        ListNode* ans = merge(sorted2, sorted1);
        return ans;
    }
};