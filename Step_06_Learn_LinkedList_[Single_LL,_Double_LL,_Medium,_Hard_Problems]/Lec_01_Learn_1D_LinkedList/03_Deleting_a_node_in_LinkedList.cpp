#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-node-in-a-linked-list/description/

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
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        while(curr -> next != NULL) {
            curr -> val = curr -> next -> val;
            if(curr -> next -> next == NULL) curr -> next = NULL;
            else curr = curr -> next;
        }
    }
};