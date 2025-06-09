# include <bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/complete-string_2687860?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char data) {
        this -> data = data;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    string longest;

    Trie() {
        root = new TrieNode('0');
        root -> isTerminal = true;
        longest = "";
    }
    

    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            root -> isTerminal = true;
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
    void insert(string word) {
        insertUtil(root, word);
    }
    

    void completeUtil(TrieNode* root, string curr) {
        if(root -> isTerminal) {
            // Update if longer or lexicographically smaller with same length
            if(curr.length() > longest.length() || 
            (curr.length() == longest.length() && curr < longest)) {
                longest = curr;
            }
        
            for(int i = 0; i < 26; i++) {
                if(root -> children[i]){
                    completeUtil(root -> children[i], curr + (char)('a' + i));
                }
            }
        }
    }

    string complete () {
        completeUtil(root, "");

        return longest == "" ? "None" : longest;
    }
};


string completeString(int n, vector<string> &a){
    Trie t;
    for(auto str : a) t.insert(str);

    return t.complete();
}