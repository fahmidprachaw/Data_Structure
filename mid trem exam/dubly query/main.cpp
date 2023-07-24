//#include <bits/stdc++.h>
#include<iostream>

using namespace std;
class Node{
    public:
        int val;
        Node* next;
        Node* prev;

        Node(int val){
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

void insert_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_at_any(Node* head, int pos, int val){
    Node* newNode = new Node(val);
    Node* temp = head;
    for(int i=0; i<pos-1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    //temp->next = newNode;
    newNode->prev = temp;
    temp->next->prev = newNode;

    temp->next = newNode;
}

void insert_tail(Node* &tail, Node* &head, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev =tail;
    tail = tail->next;
}

void print_normal(Node* head){
    cout<<"L -> ";
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void print_reverse(Node* tail){
    cout<<"R -> ";
    Node* temp=tail;
    while(temp != NULL){
        cout<<temp->val<<' ';
        temp=temp->prev;
    }
    cout<<endl;
}

int size(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != 0){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int q;
    cin>>q;
    while(q--){
        int pos, val;
        cin>>pos>>val;
        if(pos==0){
            insert_head(head, tail, val);
            print_normal(head);
            print_reverse(tail);
        }
        else if(pos==size(head)){
            insert_tail(tail, head, val);
            print_normal(head);
            print_reverse(tail);
        }
        else if(pos >= size(head)){
            cout<<"Invalid"<<endl;
        }
        else{
            insert_at_any(head, pos, val);
            print_normal(head);
            print_reverse(tail);
        }
    }
    // print_normal(head);
    // print_reverse(tail);
    return 0;
}
