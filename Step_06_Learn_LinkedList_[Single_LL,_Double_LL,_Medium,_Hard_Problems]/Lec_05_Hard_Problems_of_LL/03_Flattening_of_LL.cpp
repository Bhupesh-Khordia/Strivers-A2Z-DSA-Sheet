#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  private:
     Node* merge (Node*& first, Node*& second) {
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;

        while(first && second) {
            if(first -> data < second -> data) {
                temp -> bottom = first;
                first = first -> bottom;
            } else {
                temp -> bottom = second;
                second = second -> bottom;
            }
            temp -> next = nullptr;
            temp = temp -> bottom;
        }
        if(first) {
            temp -> bottom = first;
        } else {
            temp -> bottom = second;
        }
        Node* toReturn = dummyNode -> bottom;
        delete dummyNode;
        return toReturn;
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Iterative
        
        /*
        if(!root || !root -> next) return root;
        
        Node* prev = root;
        Node* curr = root -> next;
        
        while(curr) {
            Node* next = curr -> next;
            prev = merge(prev, curr);
            curr = next;
        }
        return prev;
        */
        
        // Recursive
        
        // Base case
        if (!root || !root->next) return root;

        // Recursively flatten the next list
        Node* mergedHead = flatten(root->next);

        // Merge this list with the next flattened list
        root = merge(root, mergedHead);

        return root;
    }
};