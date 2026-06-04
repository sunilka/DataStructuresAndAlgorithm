#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Paste the file name here 
string fname = "Largest subarray with 0 sum";

int main(){
    string converted_file_name  = "";
    for(auto ele: fname){
        if(ele == '.' || ele == ' ' || ele == '(' || ele == ')') converted_file_name += '_';
        else converted_file_name += ele;
    }
    cout<<"Converted file name is : \n";
    cout<<"Mark down file is : "<<converted_file_name<<".md"<<endl;
    cout<<"CPP file name is : "<<converted_file_name<<".cpp";
    return 0;
}