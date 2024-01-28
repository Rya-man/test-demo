#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
class Queue
{
    public:
    int front,rear,size;
    unsigned cap;
    int *arr;
    Queue* createQueue(unsigned cap)
    {
        Queue *queue= new Queue();
        queue->cap=cap;
        queue->front=0;
        queue->size=0;
        queue->rear=cap-1;
        return queue;
    }
};
class BinaryTreeNode
{
    public:
    int data;
    BinaryTreeNode *left,*right;
    BinaryTreeNode()
    {
        data=0;
        left=NULL;
        right=NULL;
    }
    BinaryTreeNode(int val)
    {
        data=val;
        left = NULL;
        right=NULL;
    }
    void PreOrder(BinaryTreeNode *root)
    {
        if(root)
        {
            cout<<root->data<<'\t';
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }
    void NonRecursivePreOrder(BinaryTreeNode *root)
    {
        stack<BinaryTreeNode> stack;
        while(1)
        {
            while(root)
            {
                cout<<root->data<<'\t';
                stack.push(*root);
                root=root->left;
            }
            if(stack.empty())
            break;
            stack.pop();
            root = root->right;
        }
    }
    void InOrder(BinaryTreeNode *root)
    {
        if(root)
        {
            InOrder(root->left);
            cout<<root->data<<'\t';
            InOrder(root->right);
        }
    }
    void PostOrder(BinaryTreeNode *root)
    {
        if(root)
        {
            PostOrder(root->left);
            PostOrder(root->right);
            cout<<root->data<<'\t';
        }
    }
};
int main()
{
    BinaryTreeNode* root= new BinaryTreeNode(1);
    root->left=new BinaryTreeNode(2);
    root->right= new BinaryTreeNode(3);
        root->left->left= new BinaryTreeNode(4);
        root->left->right = new BinaryTreeNode(5);
        root->right->left = new BinaryTreeNode(6);
        root->right->right = new BinaryTreeNode(7);
            root->left->left->left = new BinaryTreeNode(8);
            root->left->left->right = new BinaryTreeNode(9);
            root->left->right->left = new BinaryTreeNode(10);
            root->left->right->right = new BinaryTreeNode(11);
            root->right->left->left = new BinaryTreeNode(12);
            root->right->left->right = new BinaryTreeNode(13);
            root->right->right->left = new BinaryTreeNode(14);
            root->right->right->right = new BinaryTreeNode(15);
    root->InOrder(root);
}