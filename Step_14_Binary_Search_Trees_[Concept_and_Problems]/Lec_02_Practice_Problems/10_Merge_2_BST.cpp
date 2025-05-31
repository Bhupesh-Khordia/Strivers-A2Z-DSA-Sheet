#include <bits/stdc++.h>
using namespace std;

// 3 Questions are there in this file, all of them are related to merging two BSTs.


// -------------------------------------------------------------------------------------------------------------------------------
// https://leetcode.com/problems/binary-search-tree-iterator/description/
// -------------------------------------------------------------------------------------------------------------------------------


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;
        while(temp) {
            st.push(temp);
            temp = temp -> left;
        }
    }
    
    int next() {
        TreeNode* top = st.top(); st.pop();
        int toReturn = top -> val;
        if(top -> right) {
            top = top -> right;
            while(top) {
                st.push(top);
                top = top -> left;
            }
        }

        return toReturn;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


// -------------------------------------------------------------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/h_920474
// -------------------------------------------------------------------------------------------------------------------------------



/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

// APPROACH - 1 :

// vector<int> mergeTwoArray(vector<int> &in1, vector<int> &in2){

//     vector<int> ans(in1.size() + in2.size());

 

//     int i=0,j=0,k=0;

 

//     while(i<in1.size() && j<in2.size()){

//         if(in1[i] < in2[j]){

//             ans[k++] = in1[i++];

//         }

//         else{

//             ans[k++] = in2[j++];

//         }

//     }

//     while(i<in1.size()){

//         ans[k++] = in1[i++];

//     }

//     while(j<in2.size()){

//         ans[k++] = in2[j++];

//     }

//     return ans;

// }

 

// void inorder(TreeNode * root, vector<int> &IN){

 

//     if(root == NULL){

//         return ;

//     }

//     inorder(root -> left, IN);

//     IN.push_back(root -> data);

//     inorder(root -> right, IN);

// }

 

// vector<int> mergeBST(TreeNode *root1, TreeNode *root2)

// {

//     // Write your code here.

//     vector<int> in1, in2;

 

//     inorder(root1, in1);

//     inorder(root2, in2);

 

//     return mergeTwoArray(in1, in2);

// }










// APPROACH - 2 :


void flattenBST(TreeNode* root, TreeNode* &head) {
    if(root == NULL) {
        return;
    }

    flattenBST(root->right, head);
    root->right = head;
    
    if(head != NULL) {
        head->left = root;
    }

    head = root;
    flattenBST(root->left, head);
}


TreeNode* mergeLinkedhead(TreeNode* head1, TreeNode* head2) {
    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            if(head == NULL) {
                head = tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if(head == NULL) {
                head = tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(TreeNode* head) {
    int cnt = 0;
    TreeNode* temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode* LL_2_BST(TreeNode* head, int n) {
    if(n <= 0 || head == NULL) {
        return NULL;
    }

    int temp = n/2;
    TreeNode* root = head;
    while(temp--) {
        root = root->right;
    }

    root->left = LL_2_BST(head, n/2);
    root->right = LL_2_BST(root->right, n-n/2-1);
    return root;

    // TreeNode* left = LL_2_BST(head, n/2);

    // TreeNode* root = head;
    // root->left = left;
    // head = head->right;
    // root->right = LL_2_BST(head, n-n/2-1);

    // return root;
}

void LL_2_Vector(TreeNode*  &list, vector<int> &ans) {
    TreeNode* temp = list;
    while(temp != NULL) {
        ans.push_back(temp -> data);
        temp = temp -> right;
    }
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    // Step 1 : Convert BST into DLL
    TreeNode* head1 = NULL;
    TreeNode* head2 = NULL;

    flattenBST(root1, head1);
    flattenBST(root2, head2);

    head1->left = NULL;
    head2->left = NULL;

    // Step 2 : Merge Sorted Linked List
    TreeNode* list = mergeLinkedhead(head1, head2);

    // Step 3 : Convert List into BST
    // TreeNode* result = LL_2_BST(list, countNodes(list));

    // Step 4 : Convert to vector to return
    // Step 3 is not needed particularly in this questions because we have to return an array here, not a BST.
    vector<int> ans;
    LL_2_Vector(list, ans);
    

    return ans;
}

// -------------------------------------------------------------------------------------------------------------------------------
// https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
// -------------------------------------------------------------------------------------------------------------------------------


/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    void inorder(Node* root, vector<int> &ino) {
        if(root == NULL) return;
        
        inorder(root -> left, ino);
        ino.push_back(root -> data);
        inorder(root -> right, ino);
    }
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        
        inorder(root1, ans);
        inorder(root2, ans);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};