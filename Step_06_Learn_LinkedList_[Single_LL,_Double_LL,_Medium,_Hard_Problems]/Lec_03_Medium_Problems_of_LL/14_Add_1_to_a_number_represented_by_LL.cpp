#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  private:
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* first = l1;
        Node* second = l2;
        int carry = 0;

        Node* answer = new Node(-1);
        Node* ans = answer;
        int temp = carry + first -> data + second -> data;
        int unit = temp % 10;
        int ones = temp / 10;
        ans -> data = unit;
        carry = ones;

        while (first -> next != NULL && second -> next != NULL)  {
            first = first -> next;
            second = second -> next;
            temp = carry + first -> data + second -> data;

            unit = temp % 10;
            ones = temp / 10;

            ans -> next = new Node(-1);
            ans = ans -> next;
            ans -> data = unit;
            carry = ones;
        }

        while (first -> next != NULL)  {
            first = first -> next;
            temp = carry + first -> data;

            unit = temp % 10;
            ones = temp / 10;

            ans -> next = new Node(-1);
            ans = ans -> next;
            ans -> data = unit;
            carry = ones;
        }

        while (second -> next != NULL)  {
            second = second -> next;
            temp = carry + second -> data;

            unit = temp % 10;
            ones = temp / 10;

            ans -> next = new Node(-1);
            ans = ans -> next;
            ans -> data = unit;
            carry = ones;
        }

        if(carry != 0) ans -> next = new Node(carry);

        return answer;
    }
    
    Node* reverseLL (Node* head) {
        if(!head || !head -> next) return head;
        
        Node* prev = head;
        Node* curr = head -> next;
        prev -> next = NULL;
        
        while(curr) {
            Node* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
  public:
    Node* addOne(Node* head) {
        Node* headNew = reverseLL(head);
        Node* one = new Node(1);
        return reverseLL(addTwoNumbers(headNew, one));
    }
};