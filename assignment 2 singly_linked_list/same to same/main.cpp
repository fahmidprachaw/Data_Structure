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

void same(Node* head, Node* head2){
    int count = 0;
    int count2 = 0;
    while(head != NULL && head2 != NULL){
        count++;
        count2++;
        if(count != count2){
            if(head->val != head2->val){
                cout<<"NO"<<endl;
                return;
            }
            //else{
                //cout<<"NO"<<endl;
                //return;
            //}
        }
        else{
            cout<<"YES"<<endl;
            return;
        }
        head=head->next;
        head2=head2->next;

    }
    cout<<count2<<' '<<count;
}

int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    Node* head2=NULL;
    Node* tail2=NULL;
    int val,val2;
    while(true){
        cin>>val;
        if(val==-1){
            break;
        }
        insert_tail(head, tail, val);
    }
    while(true){
        cin>>val2;
        if(val2==-1){
            break;
        }
        insert_tail(head2, tail2, val2);
    }
    //print_linked_list(head);
    //print_linked_list(head2);
    same(head, head2);
    return 0;
}
