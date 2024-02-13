 #include <stdio.h>
      #include <stdlib.h>

      struct Node {
          int data;
          struct Node* next;
      };

      struct Queue {
          struct Node* front;
          struct Node* rear;
      };

      void enqueue(struct Queue* queue, int data) {
          struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
          newNode->data = data;
          newNode->next = NULL;

          if (queue->rear == NULL) {
              queue->front = newNode;
              queue->rear = newNode;
          } else {
              queue->rear->next = newNode;
              queue->rear = newNode;
          }
      }

      int dequeue(struct Queue* queue) {
          if (queue->front == NULL) {
              printf("Queue is empty\n");
              return -1;
          }

          int data = queue->front->data;
          struct Node* temp = queue->front;

          if (queue->front == queue->rear) {
              queue->front = NULL;
              queue->rear = NULL;
          } else {
              queue->front = queue->front->next;
          }

          free(temp);
          return data;
      }

      void display(struct Queue* queue) {
          struct Node* current = queue->front;
          while (current != NULL) {
              printf("%d ", current->data);
              current = current->next;
          }
          printf("\\n");
      }

      int main() {
          struct Queue callQueue = {NULL, NULL};
          int choice, callNumber;

          do {
              printf("\nMenu:\n");
              printf("1. Add a phone call\n");
              printf("2. Remove a phone call\n");
              printf("3. Display the call queue\n");
              printf("4. Exit\n");
              printf("Enter your choice: ");
              scanf("%d", &choice);

              switch (choice) {
                  case 1:
                      printf("Enter the phone call number: ");
                      scanf("%d", &callNumber);
                      enqueue(&callQueue, callNumber);
                      printf("Phone call %d added to the queue.\n", callNumber);
                      break;
                  case 2:
                      callNumber = dequeue(&callQueue);
                      if (callNumber != -1) {
                          printf("Phone call %d removed from the queue.\n", callNumber);
                      }
                      break;
                  case 3:
                      printf("Call Queue: ");
                      display(&callQueue);
                      break;
                  case 4:
                      printf("Exiting the program.\n");
                      break;
                  default:
                      printf("Invalid choice. Please enter a valid option.\n");
              }

          } while (choice != 4);

          return 0;
      }