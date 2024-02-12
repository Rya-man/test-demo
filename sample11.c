#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* CreateNode() {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void FirstInsert(Node** head, int value) {
    *head = CreateNode();
    (*head)->data = value;
}

void Insert_at_Left(Node** head, int key, int data) {
    Node* temp = *head;
    Node* new_node = CreateNode();
    new_node->data = data;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }
    new_node->prev = temp->prev;
    new_node->next = temp;
    temp->prev = new_node;
    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        *head = new_node;
}

void delete_node(Node** head, int key) {
    Node* temp = *head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Data not found");
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->prev == NULL)
        *head = temp->next;

    printf("\nDeleting data %d", temp->data);
    free(temp);
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch, val;
    Node* head = NULL;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("\nEnter the value to insert: ");
            scanf("%d", &val);
            if (head == NULL) {
                FirstInsert(&head, val);
            }
            else {
                printf("\nEnter the key before which item needs to be inserted: ");
                scanf("%d", &ch);
                Insert_at_Left(&head, ch, val);
            }
        }
        else if (ch == 2) {
            printf("\nEnter the value that needs to be deleted: ");
            scanf("%d", &val);
            delete_node(&head, val);
        }
        else if (ch == 3) {
            display(head);
        }
        else if (ch == 4) {
            // Free memory allocated for the linked list before exiting
            while (head != NULL) {
                Node* temp = head;
                head = head->next;
                free(temp);
            }
            exit(0);
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
