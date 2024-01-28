#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
struct Queue
{
    
};

Node* CreateNode(int value)
{
    Node* newnode = new Node();
    newnode->data= value;
    newnode->left=nullptr;
    newnode->right=nullptr;
    return newnode;
}
Node* insert_node(Node* root,int value)
{
    if(root==NULL)
    {
        Node* newnode = CreateNode(value);
        return newnode;
    }
    queue<Node*> q;
}
int main()
{
    
    
}
