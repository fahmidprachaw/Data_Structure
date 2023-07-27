#include <iostream>

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

class myStack{
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int sz=0;

    void push(int val){
        sz++;
        Node* newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=tail->next;
    }
    void pop(){
        sz--;
        Node* deleteNode = tail;
        tail = tail->prev;
        if(tail == NULL){
            head = NULL;
        }
        delete deleteNode;
    }
    int top(){
        return tail->val;
    }
    int size(){
        return sz;
    }
    bool empty(){
        if(sz==0){
            return true;
        }
        else{
            return false;
        }
    }
};

class myQueue{
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int sz=0;

    void push(int val){
        sz++;
        Node* newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=tail->next;
    }
    void pop(){
        sz--;
        Node* deleteNode = head;
        head=head->next;
        if(head == NULL){
            tail=NULL;
            delete deleteNode;
            return;
        }
        head->prev = NULL;
        delete deleteNode;
    }
    int front(){
        return head->val;
    }
    int size(){
        return sz;
    }
    bool empty(){
        if(sz==0){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    myStack st;
    myQueue qu;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        st.push(x);
    }
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        qu.push(x);
    }
    if(st.size() != qu.size()){
        cout<<"NO";
        return 0;
    }
    bool flag = true;
    while(!st.empty() && !qu.empty()){
//        cout<<st.top()<<' '<<qu.front()<<endl;
//        st.pop();
//        qu.pop();
          if(st.top() != qu.front()){
              flag = false;
          }
        st.pop();
        qu.pop();
    }
    if(flag==true){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
