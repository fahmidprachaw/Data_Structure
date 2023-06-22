#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int val;
        Node *next;

    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void insert_tail(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}

void print_linked_list(Node *head, int val){
    Node *temp=head;
    while(temp != NULL){
        cout<<temp->val<<' ';
        temp = temp->next;
    }
    cout<<endl;
}
void min_max_value(Node *&head){
    Node *maxValue = head;
    Node *minValue = head;
    while(head != NULL){
        if(head->val > maxValue->val){
            maxValue = head;
        }
        if(head->val < minValue->val){
            minValue = head;
        }
        head=head->next;
    }
    cout<<maxValue->val<<' '<<minValue->val;

}

int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    int val;
    while(true){
        cin>>val;
        if(val==-1){
            break;
        }
        insert_tail(head, tail, val);
    }
   // print_linked_list(head);
    min_max_value(head);
    //min_value(head);
    return 0;
}
