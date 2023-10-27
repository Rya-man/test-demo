#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(){
        data = 10;
        next = NULL;
    }

};
int main()
{
    node *n1 = new node();
    cout<<n1->data;

}  