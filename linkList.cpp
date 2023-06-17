#include<iostream>
#include "node.cpp"
using namespace std;
class LinkList{
    Node* head;

    public:
        LinkList(int d){
            head=new Node(d);
        }
        
        void display(){
            while (head!=NULL){
                cout<<head->data;
                head=head->next;
            }
        }
};