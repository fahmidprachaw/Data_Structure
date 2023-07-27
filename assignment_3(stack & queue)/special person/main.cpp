#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<string>p;
    string name;
    int q;
    cin>>q;
    while(q--){
        int com;
        cin>>com;

        if(com==0){
            cin>>name;
            p.push(name);
        }
        else if(com==1){
            if(!p.empty()){
                cout<<p.front()<<endl;
                p.pop();
            }
            else{
                cout<<"Invalid"<<endl;
            }
        }
    }
    return 0;
}
