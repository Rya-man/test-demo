#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    //node(){
      //  data = 10;
        //next = NULL;
    //}
    node(int s=0,node* f=NULL)
    {
        data = s;
        next = f;
    }  
};
void printlist(node* head)
{
    while(head)
    {
        cout<<head->data<<' ';
        head=head->next;
    }
}
int main()
{
    node *head,*n1,*n2;
    head = new node();
    n1= new node(1);
    n2=new node(2);
    head->next= n1;
    n1->next=n2;
    cout<<'\n';
    printlist(head);


}  