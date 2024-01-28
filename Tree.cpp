#include<iostream>
class Node{
    private:
    int data;
    Node* left;
    Node* right;
    public:
    Node(int val=0)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
    int inorder(Node* root)
    {
        inorder(root->left);
        return root->data;
        inorder(root->right);
    }
};