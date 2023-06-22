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

void print_linked_list(Node *head){
    Node *temp=head;
    while(temp != NULL){
        cout<<temp->val<<' ';
        temp = temp->next;
    }
    cout<<endl;
}
void midelement(Node* head){
    Node* temp = head;
    int count = 0;
    int mid;
    if(temp == NULL){
        cout<<"list is empty";
    }
    else{
        while(temp != NULL){
            count++;
            temp=temp->next;
        }
        //cout<<count<<endl;
        temp = head;
        if(count%2==0){
            for(int i=1; i<count/2; i++){
                temp = temp->next;
            }
            cout<<temp->val<<' '<<temp->next->val<<endl;
        }
        else{
            for(int i=0; i<count/2; i++){
            temp = temp->next;
        }
        cout<<temp->val<<endl;
        }
    }
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
    for(Node* i=head; i->next !=NULL; i=i->next){
        for(Node* j=i->next; j!=NULL; j=j->next){
            if(i->val < j->val){
                swap(i->val, j->val);
            }
        }
    }
    print_linked_list(head);
    midelement(head);


    return 0;
}
