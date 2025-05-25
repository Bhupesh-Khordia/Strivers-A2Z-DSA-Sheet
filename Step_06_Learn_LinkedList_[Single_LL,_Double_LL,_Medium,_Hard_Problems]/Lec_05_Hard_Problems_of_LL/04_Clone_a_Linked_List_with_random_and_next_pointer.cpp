#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private :
    void insertAtTail (Node* & head, Node* & tail, int data) {
        Node* newNode = new Node(data);
        if (head == NULL && tail == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        // Step - 1 = Copy the LL using next pointers.
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while (temp != NULL) {
            insertAtTail (cloneHead, cloneTail, temp -> val);
            temp = temp -> next;
        }
        
        // Approach - 1
        // // Step - 2 = Create a map to map originalNode to cloneNode.
        // unordered_map <Node*, Node*> mapping;
        // Node* originalNode = head;
        // Node* cloneNode = cloneHead;
        // while (originalNode != NULL) {
        //     mapping[originalNode] = cloneNode;
        //     originalNode = originalNode -> next;
        //     cloneNode = cloneNode -> next;
        // }
        
        // temp = head;
        // Node* temp2 = cloneHead;
        // while(temp != NULL) {
        //     temp2 -> random = mapping[temp -> random];
        //     temp = temp -> next;
        //     temp2 = temp2 -> next;
        // }

        //Approach - 2
        //Step - 2 = Add clone nodes in between original nodes.

        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;

            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }

        // Step - 3 = Random Pointer Copy
        temp = head;
        while (temp != NULL) {
            if (temp -> next != NULL) {
                temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
            }
            temp = temp -> next -> next;
        }

        // Step - 4 = Revert Step 2
        originalNode =  head;
        cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL) {
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;

            if (originalNode != NULL) {
                cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }
        
        //Step - 5 = Return cloneHead
        return cloneHead;
    }
};