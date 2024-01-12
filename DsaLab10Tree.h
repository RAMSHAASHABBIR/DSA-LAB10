#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
//2
    node* insertAtTree(int val, node* root)
    {
        if (root == nullptr)
        {
            return new node(val);
        }
        if (val < root->data)
        {
            root->left = insertAtTree(val, root->left);
        }
        else
        {
            root->right = insertAtTree(val, root->right);
        }
        return root;
    }
    void print(node* root)
    {
        if (root == nullptr)
        {
            return;
        }
        print(root->left);
        cout << root->data << " " ;
        print(root->right);
    }
    node* searchInTree(node* root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            return searchInTree(root->left, key);
        }
        else if (root->data < key)
        {
            return searchInTree(root->right, key);
        }
    }
    //4
    void preorder(node* root) //root left right
    {
        if (root==nullptr)
        {
            return;
        }
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(node* root) // left root right
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
    void postorder(node* root) // left right root
    {
        if (root == nullptr)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
    //7
    int calculateHeight(node* root)
    {
        if (root == nullptr)
            return -1;
        int left = calculateHeight(root->left);
        int right = calculateHeight(root->right);
        if (left >= right)
            return left + 1;
        if (right > left)
            return right + 1;
    }
    //8
    vector<int> v1;
    bool checkBst(node* root) {

        if (root == nullptr) {
            return true;
        }
        checkBst(root->left);
        v1.push_back(root->data);
        checkBst(root->right);
        for (int i = 0, j = 1;j < v1.size();i++, j++)
        {
            if (v1[i] >= v1[j])
                return false;
        }
        return true;
    }
    //12
    int noOfLeaves(node* root) //external nodes
    {
        if (root==nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        return noOfLeaves(root->left) + noOfLeaves(root->right);
    }
    //10
    int internalNodes(node* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int count = 0;
        if (root->left != nullptr || root->right != nullptr)
        {
            count = 1;
        }
        return count + internalNodes(root->left) + internalNodes(root->right);
    }
    //6
    int evenNumberNodes(node* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int count = 0;
        if (root-> data%2 == 0)
        {
            count=1;
        }
        return count+ evenNumberNodes(root->left) + evenNumberNodes(root->right);
    }
    //5
    void levelOrderTraversal(node* root)
    {
        if (root == nullptr)
        {
            return;
        }
        queue <node*> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty())
        {
            node* nodee = q.front();
            q.pop();
            if (nodee != nullptr)
            {
                cout << nodee->data;
                if (nodee->left)
                    q.push(nodee->left);
                if (nodee->right)
                    q.push(nodee->right);
            }
            else if (!q.empty())
            {
                q.push(nullptr);
            }
        }
    }
    //leetcode
    //2
   /* class Solution {
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            if (root == nullptr)
            {
                return new TreeNode(val);
            }
            if (val < root->val)
            {
                root->left = insertIntoBST(root->left, val);
            }
            else
            {
                root->right = insertIntoBST(root->right, val);
            }
            return root;
        }
    };*/


    //4
    //a
   /* class Solution {
    public:
        vector<int> v1;
        vector<int> inorderTraversal(TreeNode* root) {

            if (root == nullptr) {
                return v1;
            }
            inorderTraversal(root->left);
            v1.push_back(root->val);
            inorderTraversal(root->right);
            return v1;
        }

    };*/

    //b
   /* class Solution {
    public:
        vector<int> v1;
        vector<int> postorderTraversal(TreeNode* root) {

            if (root == nullptr) {
                return v1;
            }
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            v1.push_back(root->val);
            return v1;
        }
    };*/



    //c
    /*class Solution {
    public:
        vector<int> v1;
        vector<int> preorderTraversal(TreeNode* root) {

            if (root == nullptr) {
                return v1;
            }
            v1.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
            return v1;
        }
    };*/