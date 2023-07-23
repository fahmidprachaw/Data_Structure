#include <iostream>

using namespace std;
class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val=val;
            this->next=NULL;
        }
};

void insert_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}

void print_list(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reverse(Node* &head, Node* cur){
    if(cur->next == NULL){
        head = cur;
        return;
    }
    reverse(head, cur->next);
    cur->next->next = cur;
    cur->next = NULL;
}

//void pelindrom()
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
    Node* temp = head;
    Node* head1 = NULL;
    Node* tail1 = NULL;
    while(temp != NULL){
        insert_tail(head1, tail1, temp->val);
        temp=temp->next;
    }
    reverse(head1, head1);
    print_list(head);
    print_list(head1);
    temp = head;
    Node* temp2 = head1;
    while(temp != NULL){
        if(temp->val != temp2->val){
            cout<<"NO"<<endl;
            return;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    cout<<"YES"<<endl;
    return 0;
}
