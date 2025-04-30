// https://leetcode.com/problems/lfu-cache/description/

using namespace std;
#include <bits/stdc++.h>

class Node {
public : 
    int key;
    int value;
    int freq;
    Node* next;
    Node* prev;

    Node (int k, int val) {
        key = k;
        value = val;
        freq = 1;
        next = prev = nullptr;
    }
};

// List of Nodes (Doubly Linked List)
class DoubleLinkedList {
public:
    int listSize;
    Node* head;
    Node* tail;

    DoubleLinkedList () {
        listSize = 0;
        head = new Node (-1, -1);
        tail = new Node (-1, -1);

        head -> next = tail;
        tail -> prev = head;
    }

    void insert(Node* node) {
        Node* next = head -> next;
        head -> next = node;
        node -> next = next;
        node -> prev = head;
        next -> prev = node;
        listSize++;
    }

    void remove (Node* node) {
        Node* next = node -> next;
        Node* prev = node -> prev;
        next -> prev = prev;
        prev -> next = next;
        listSize--;
    }
};

class LFUCache {
private:
    int cap;
    int size;
    int minFreq;  // Current Least Freq
    unordered_map<int, Node*> cache; // Key to Node
    unordered_map<int, DoubleLinkedList*> freqMap; // Freq to List of Nodes (Double linked list)


public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* currNode = cache[key];
            int ans = currNode -> value;
            update(currNode);

            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* currNode = cache[key];
            currNode -> value = value;
            update(currNode);
        } else {
            size++;
            if(size > cap) {
                DoubleLinkedList* lfu = freqMap[minFreq];
                Node* nodeToDelete = lfu->tail->prev;
                cache.erase(nodeToDelete->key);
                lfu->remove(nodeToDelete);
                delete nodeToDelete;
                size--;
            }

            minFreq = 1;
            Node* newNode = new Node(key, value);
            
            if(freqMap.find(1) != freqMap.end()) {
                freqMap[1]->insert(newNode);
            } else {
                DoubleLinkedList* newList = new DoubleLinkedList();
                newList->insert(newNode);
                freqMap[1] = newList;
            }
            cache[key] = newNode;
        }
    }

    void update(Node* currNode) { // To Update frequency map
        int currFreq = currNode -> freq;

        freqMap[currFreq]->remove(currNode);
        if(currFreq == minFreq && freqMap[currFreq] -> listSize == 0) {
            minFreq++;
        }
        currNode -> freq ++;

        if(freqMap.find(currNode -> freq) != freqMap.end()) {
            freqMap[currNode-> freq]->insert(currNode);
        } else {
            DoubleLinkedList* newList = new DoubleLinkedList();
            newList->insert(currNode);
            freqMap[currNode -> freq] = newList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */