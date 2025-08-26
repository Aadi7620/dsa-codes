#include<iostream>
using namespace std;
class node{
public:
int data;
node*prev;
node*next;
node (int val){
    data = val;
    prev = NULL;
    next = NULL;
}
};
class doublell{
    public:
    node*head;
    node*tail;
    doublell(){
        head = tail = NULL;
    }
    void push_front(int val){
        node*newnode = new node(val);
        if(head == NULL){
            head = tail = newnode;
            return;
        }else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            return;
        }
    }
    void push_back(int val){
        node*newnode = new node(val);
        if(head == NULL){
            head = tail = newnode;
            return;
        }else{
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
            return;
        }
    }
    void pop_front(){
        if(head == NULL){
            cout<<"list is empty";
            return;
        }else{
            node*temp = head;
            head = head->next;
            if(head != NULL){
            head->prev = NULL;
            }
            temp->next = NULL;
            delete temp; 
        }
    }
    void pop_back(){
        if(head == NULL){
            cout<<"list is empty";
            return;
    }else{
        node*temp = tail;
        tail = tail->prev;
        if(tail != NULL){
            tail->next = NULL;
        }
        temp->next = NULL;
        delete temp; 
    }
    }
    void printll(){
        node*temp = head;
        while(temp!= NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};
int main(){
    doublell dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.printll();
    cout<<endl;
    dll.pop_front();
    dll.printll();
    cout<<endl;
    dll.pop_back();
    dll.printll();
    return 0;
}