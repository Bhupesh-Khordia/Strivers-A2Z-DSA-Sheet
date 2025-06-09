# include <bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/count-distinct-substrings_985292?leftPanelTabValue=PROBLEM


# include <bits/stdc++.h>

struct Node{
    Node* children [26];

    Node(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};

int countDistinctSubstrings(string &s) {
    Node* root = new Node();
    int count = 1; // "" (for empty string)

    for(int i=0;i<s.size();i++){
        Node* node =root;

        for(int j=i;j<s.size();j++){
            int index = s[j]-'a';

            if(node->children[index]==NULL){
                count++;
                node->children[index]=new Node();
            }

            node=node->children[index];
        }
    }

    return count;
}