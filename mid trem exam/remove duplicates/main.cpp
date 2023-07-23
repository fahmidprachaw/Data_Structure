#include <bits/stdc++.h>

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
void print_linked_list(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void removeDuplicate(Node* head){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->val == temp->next->val){
            temp->next = temp->next->next;
        }
        if(temp->next == NULL){
            break;
        }
        else if(temp->val != temp->next->val){
            temp= temp->next;
        }
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    while(true){
        cin>>val;
        if(val == -1){
            break;
        }
        insert_tail(head, tail, val);
    }
    for(Node* i=head; i->next !=NULL; i=i->next){
        for(Node* j=i->next; j!=NULL; j=j->next){
            if(i->val > j->val){
                swap(i->val, j->val);
            }
        }
    }
    removeDuplicate(head);
    print_linked_list(head);

    return 0;
}
