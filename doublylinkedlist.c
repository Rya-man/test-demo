#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* Createnode(int d)
{
    struct node* ddl = (struct node*)malloc(sizeof(struct node));
    ddl->data=d;
    ddl->next=NULL;
    ddl->prev=NULL;
    return ddl;
}
void add_at_start(struct node** head,int d)
{
    struct node* newnode= Createnode(d);
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    newnode->next=*head;
    (*head)->prev=newnode;
    *head=newnode;
}
void traversal(struct node* head)
{
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
void insert(struct node* head,int val,int key)
{
    struct node* newnode = Createnode(val);
    int i=0;
    while(head!=NULL && i<key)
    {
        head=head->next;
    }
    newnode->next=head->next;
    newnode->prev=head->next->prev;
    head->next=newnode;
    newnode->next->prev=newnode;
}
int main()
{
    struct node* n1= Createnode(10);
    add_at_start(&n1,4);
    printf("%d",n1->data);
    return 0;
}