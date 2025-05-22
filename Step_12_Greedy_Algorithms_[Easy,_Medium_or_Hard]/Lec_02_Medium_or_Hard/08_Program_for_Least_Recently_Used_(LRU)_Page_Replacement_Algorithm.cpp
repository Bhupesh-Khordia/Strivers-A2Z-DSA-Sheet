// https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

class Solution {
public:
    int pageFaults(int N, int C, int pages[]) {
        int faults = 0;
        unordered_map<int, Node*> mp;
        Node* head = nullptr;
        Node* tail = nullptr;
        int count = 0;

        for (int i = 0; i < N; i++) {
            int page = pages[i];

            // Case 1: Page is already in cache (move it to tail = most recently used)
            if (mp.count(page)) {
                Node* curr = mp[page];

                if (curr != tail) {
                    // Remove current node from its position
                    if (curr->prev) curr->prev->next = curr->next;
                    if (curr->next) curr->next->prev = curr->prev;

                    // Update head if needed
                    if (curr == head) head = curr->next;

                    // Move to tail
                    curr->prev = tail;
                    curr->next = nullptr;
                    tail->next = curr;
                    tail = curr;
                }
                continue; // No fault
            }

            // Case 2: Page not in cache (Page Fault)
            faults++;

            Node* newNode = new Node(page);
            mp[page] = newNode;

            // If cache not full
            if (count < C) {
                count++;

                if (!head) {
                    head = tail = newNode;
                } else {
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                }
            }
            // If cache full
            else {
                // Remove LRU (head)
                mp.erase(head->data);

                Node* temp = head;
                head = head->next;
                if (head) head->prev = nullptr;
                delete temp;

                // Add newNode at tail
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        return faults;
    }
};