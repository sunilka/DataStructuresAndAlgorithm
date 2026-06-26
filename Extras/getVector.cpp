#include<bits/stdc++.h>
using namespace std;

int main(){
    string input = "[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]";
    string output = "";
    for(auto c: input){
        if(c == '[') output+='{';
        else if(c==']') output+='}';
        else output+=c;
    }
    cout<<"Here is you final vector"<<endl;
    cout<<output<<endl;
}