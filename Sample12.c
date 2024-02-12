#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* CreateNode(int d) {
    Node* new_node= (Node*)malloc(sizeof(Node));
    new_node->data = d;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* Insert(Node* root, int d) {
    if(root == NULL) {
        return CreateNode(d);
    }
    if(d < root->data) {
        root->left = Insert(root->left, d);
    }
    else if(d >= root->data) {
        root->right = Insert(root->right, d);
    }
    return root;
}

void Postorder(Node* root) {
    if(root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->data);
    }
}

void Inorder(Node* root) {
    if(root != NULL) {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

void Preorder(Node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

int main() {
    int ch, val;
    Node* Root = NULL;
    
    while(1) {
        printf("\n---------------------------");
        printf("\n      Binary Search Tree");
        printf("\n---------------------------");
        printf("\n1. Insert");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");
        printf("\n---------------------------");
        printf("\nEnter your choice: ");
        
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &val);
                Root = Insert(Root, val);
                break;
            case 2:
                printf("\nInorder Traversal: ");
                Inorder(Root);
                printf("\n");
                break; 
            case 3:
                printf("\nPreorder Traversal: ");
                Preorder(Root);
                printf("\n");
                break; 
            case 4:
                printf("\nPostorder Traversal: ");
                Postorder(Root);
                printf("\n");
                break; 
            case 5:
                printf("\nExiting...\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
