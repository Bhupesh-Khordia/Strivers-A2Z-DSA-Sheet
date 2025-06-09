# include <bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/implement-trie_1387095

#include <bits/stdc++.h> 

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int terminal;

    TrieNode(char data) {
        this -> data = data;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        terminal = 0;
    }
};

class Trie{

    public:

    TrieNode* root;

    Trie(){
        root = new TrieNode('0');
    }

    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            root -> terminal++;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index]) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string &word){
        insertUtil(root, word);
    }

    int searchUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            return root -> terminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index]) {
            child = root -> children[index];
        }
        else {
            return 0;
        }

        return searchUtil(child, word.substr(1));
    }

    int countWordsEqualTo(string &word){
        return searchUtil(root, word);
    }

    int countTerminals(TrieNode* root) {
        int cnt = root -> terminal;

        for(int i = 0; i < 26; i++) {
            if(root -> children[i]) cnt += countTerminals(root -> children[i]);
        }

        return cnt;
    }

    int searchStaringWithUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            return countTerminals(root);
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index]) {
            child = root -> children[index];
        }
        else {
            return 0;
        }

        return searchStaringWithUtil(child, word.substr(1));
    }

    int countWordsStartingWith(string &word){
        return searchStaringWithUtil(root, word);
    }

    void deleteUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            root -> terminal--;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index]) {
            child = root -> children[index];
        }
        else {
            return;
        }

        deleteUtil(child, word.substr(1));
    }

    void erase(string &word){
        deleteUtil(root, word);
    }
};
