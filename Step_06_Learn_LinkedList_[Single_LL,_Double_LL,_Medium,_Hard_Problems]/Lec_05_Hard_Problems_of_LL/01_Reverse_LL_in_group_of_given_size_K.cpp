#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    int getLength (ListNode* head) {
        ListNode* curr = head;
        int cnt = 0;
        while (curr != nullptr) {
            cnt++;
            curr = curr -> next;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case
        if (head == nullptr) {
            return nullptr;
        }

        // Step 1 - Reverse starting ke K nodes.
        ListNode* next = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int count = 0;

        while (curr != nullptr && count < k) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count ++;
        }

        // Step 2 - Baaki recursion sambhal lega.
        if(getLength(next) < k) {   // Case for last group which does not have k nodes.
            head -> next = curr;
            return prev;
        }
        head -> next = reverseKGroup(next, k);

        //Step 3 
        return prev;
    }
};