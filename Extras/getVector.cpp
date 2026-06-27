#include<bits/stdc++.h>
using namespace std;

int main(){
    string input = "[[1,2,3],[0,2],[0,1,3],[0,2]]";
    string output = "";
    for(auto c: input){
        if(c == '[') output+='{';
        else if(c==']') output+='}';
        else output+=c;
    }
    cout<<"Here is you final vector"<<endl;
    cout<<output<<endl;
}