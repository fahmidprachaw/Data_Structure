#include <bits/stdc++.h>

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
    for(int i=1; i<=pos; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = temp;
}

void insert_tail(Node* &tail, int val){
    Node* newNode = new Node(val);
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
        }
        else if(pos==size(head)){
            insert_tail(tail, val);
        }
        else if(pos >= size(head)){
            cout<<"Invalid"<<endl;
        }
        else{
            insert_at_any(head, pos, val);
        }
    }
    print_normal(head);
    print_reverse(tail);
    return 0;
}
