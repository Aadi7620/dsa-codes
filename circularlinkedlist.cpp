#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class circularlist{
Node*head;
Node*tail;
public:
circularlist(){
head = tail = NULL;
}
//insert at head
void push_front(int val){
    Node*newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
        tail->next = head;
        return;
    }
    else{
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}
void push_back(int val){
    Node*newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
        tail->next = head;
        return;
    }
    else{
        tail->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}
void pop_front(){
    if(head == NULL)
        return;
        else if(head == tail ){
            delete head;
            head = tail = NULL;
        }
        else{
            Node*temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
}
void pop_back(){
    if(head == NULL)
    return;
    else if (head == tail){
        delete head;
        head = tail = NULL;
    }
    else {
        Node*temp = tail;
        Node*prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }
        tail = prev;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }
}
  void print(){
            Node*temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"NULL";
        }
};
int main(){
    circularlist cl;
    cl.push_back(1);
    cl.push_back(2);
    cl.push_back(3);
    cl.print();
    cout<<endl;
    cl.pop_front();
    cl.print();
    cout<<endl;
    cl.pop_back();
    cl.print();
    return 0;
}