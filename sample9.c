#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Node {
    char* Name;
    struct Node* next;
};

struct Node* createnode(char* Name, unsigned max) {
    struct Node* node_name = (struct Node*)malloc(sizeof(struct Node));
    node_name->Name = (char*)malloc(max);
    strcpy(node_name->Name, Name);  // Copy the name into the allocated memory
    node_name->next = NULL;
    return node_name;  // Don't forget to return the created node
}

void insert(struct Node** head, char* name) {
    struct Node* new_node = createnode(name, strlen(name));
    if (*head == NULL || strcmp((*head)->Name, name) >= 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        struct Node* curr = *head;
        while (curr->next != NULL && strcmp(curr->next->Name, name) < 0) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

void delete(struct Node** head, char* name) {
    int key = 1;
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (*head == NULL)
        return;
    while (temp != NULL && strcmp(temp->Name, name) != 0) {
        key = 0;
        prev = temp;
        temp = temp->next;
    }
    if (key == 1) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    if (temp == NULL) {
        printf("Key to delete does not exist\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void give(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf(" %s ", temp->Name);
        temp = temp->next;
    }
}

int main() {
    char arr[100];  // Allocate memory for the array
    int ch, max;
    printf("Enter the max size of the name\n");
    scanf("%d", &max);
    struct Node* head = NULL;  // Initialize head to NULL

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\t");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("\nEnter name to be inserted\t");
            scanf("%s", arr);
            insert(&head, arr);
        } else if (ch == 2) {
            printf("\nEnter the name to be deleted\t");
            scanf("%s", arr);
            delete(&head, arr);
        } else if (ch == 3) {
            give(head);
        } else if (ch == 4) {
            exit(0);
        } else {
            printf("Error\n");
        }
    }
    return 0;
}
