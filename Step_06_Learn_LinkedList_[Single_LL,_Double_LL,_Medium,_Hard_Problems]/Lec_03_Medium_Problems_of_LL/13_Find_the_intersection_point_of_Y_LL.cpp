#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // This is also working
        /*
        int lenA = 0;
        int lenB = 0;

        ListNode* temp = headA;
        while(temp) {
            temp = temp -> next;
            lenA++;
        }
        temp = headB;
        while(temp) {
            temp = temp -> next;
            lenB++;
        }

        int skipA = lenA - min(lenA, lenB);
        int skipB = lenB - min(lenA, lenB);

        ListNode* currA = headA;
        while(skipA) {
            currA = currA -> next;
            skipA--;
        }
        ListNode* currB = headB;
        while(skipB) {
            currB = currB -> next;
            skipB--;
        }

        while(currA && currB) {
            if(currA == currB) return currA;
            currA = currA -> next;
            currB = currB -> next;
        }
        return NULL;
        */

        // Another  solution to remember

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2) {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;

            if(temp1 == temp2) return temp1; // Always exit here (except one case)

            if(temp1 == NULL) temp1 = headB;
            if(temp2 == NULL) temp2 = headA;
        }
        return temp1; // When both Linked lists are same then it will exit here.
    }
};