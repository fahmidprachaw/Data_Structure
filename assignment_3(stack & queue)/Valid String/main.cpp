#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<char>st;
    string s;
    int q;
    cin>>q;
    while(q--){
        cin>>s;
        for(char c:s){
            if(!st.empty()){
                if((c=='A' && st.top()=='B') || (c=='b' && st.top()=='A')){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
        }
        if(st.empty()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
