#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int>st;
    queue<int>qu;
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
