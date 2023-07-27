#include <bits/stdc++.h>

using namespace std;


class myStack{
    public:
        list<int>s;

    void push(int val){
        s.push_back(val);
    }
    void pop(){
        s.pop_back();
    }
    int top(){
        return s.back();
    }
    int size(){
        return s.size();
    }
    bool empty(){
        if(s.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};

class myQueue{
    public:
        list<int>q;

    void push(int val){
        q.push_back(val);
    }
    void pop(){
        q.pop_front();
    }
    int front(){
        return q.front();
    }
    int size(){
        return q.size();
    }
    bool empty(){
        if(q.size()==0){
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
