#include <stdio.h>
#include <stdlib.h>
#define max 3

int queue[max], front = -1, end = -1;

void insert(int num)
{
    if (front == (end + 1) % max)
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
    {
        front = end = 0;
    }
    else
    {
        end = (end + 1) % max;
    }
    queue[end] = num;
    printf("\n");
}

void delete()
{
    if (front == -1)
    {
        printf("Queue empty.\n");
        return;
    }
    if (front == end)
    {
        front = end = -1;
    }
    else
    {
        front = (front + 1) % max;
    }
}
void display()
{
    int i = front;
    if (front == -1)
    {
        printf("Queue empty.\n");
    }
    else
    {
        for (i = front; i < end; i = (i + 1) % max)
        {
            printf("%d\t", queue[i]);
        }
        printf("%d\n", queue[end]);
    }
}

void main()
{
    int choice, id;
    while (1)
    {
        printf("1.Add caller\n2.Delete caller\n3.Display queue\n4.Exit\nEnter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter caller id:");
            scanf("%d", &id);
            insert(id);
            break;

        case 2:
            delete ();
            printf("Caller id removed from queue.\n");
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice");
            break;
        }
    }
}