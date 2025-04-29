// https://leetcode.com/problems/lru-cache/description/

using namespace std;
#include <bits/stdc++.h>


class Node {
public : 
    int key;
    int value;
    Node* next;
    Node* prev;

    Node (int k, int val) {
        key = k;
        value = val;
        next = prev = nullptr;
    }
};

class LRUCache {
    int cap;
    Node* head = new Node (-1, -1);  // Recent to oldest 
    Node* tail = new Node (-1, -1);
    unordered_map<int, Node*> cache; // Key -> node

    void insert(Node* node) {
        Node* next = head -> next;
        head -> next = node;
        node -> next = next;
        node -> prev = head;
        next -> prev = node;
    }

    void remove (Node* node) {
        Node* next = node -> next;
        Node* prev = node -> prev;
        next -> prev = prev;
        prev -> next = next;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node -> value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            cache.erase(key);
            delete node;
        }
        Node* newNode = new Node (key, value);
        insert(newNode);
        cache[key] = newNode;
        if(cache.size() > cap) {
            Node* lru = tail -> prev;
            cache.erase(lru -> key);
            remove(lru);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */