#include<bits/stdc++.h>
using namespace std;

void generate(int n,int op,int cl,string &s){
    if(op==n && cl==n){
        cout <<s<<" ";
        return;
    }
    if(op<=n){
        s.push_back('(');
        generate(n,op+1,cl,s);
        s.pop_back();
    }
    if(cl<=op && cl<op){
        s.push_back(')');
        generate(n,op,cl+1,s);
        s.pop_back();
    }
    if(s.size()==2){
    	cout <<1;
    }
}

int main(){
    int n;
    while(cin >>n){
        string s="";
        int op=0,cl=0;
        generate(n,op,cl,s);
        cout <<'\n';
    }
   // write your code here
    return 0;
}