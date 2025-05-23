#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1

// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        Node * head = new Node(arr[0]);
        head -> prev = NULL;
        Node* curr = head;
        for(int i = 1; i < arr.size(); i++) {
            curr -> next = new Node(arr[i]);
            curr -> next -> prev = curr;
            curr = curr -> next;
        }
        curr -> next = NULL;
        return head;
    }
};