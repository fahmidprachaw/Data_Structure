#include <iostream>

using namespace std;
class Node{
    public:
        string add;
        Node* next;
        Node* prev;

        Node(string add){
            this->add=add;
            this->next=NULL;
            this->prev=NULL;
        }
};

void insert_tail(Node* &head, Node* &tail, string add){
    Node* newNode = new Node(add);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

void print_list(Node* head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->add << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int q;
    cin>>q;
    while(q--){
        string add;
        cin>>add;
        cin.ignore();
        if(add=="end"){
            break;
        }
        insert_tail(head, tail, add);
    }
    print_list(head);
    return 0;
}
