#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Paste the file name here 
string fname = "Count inversions in an array";

int main(){
    string converted_file_name  = "";
    for(auto ele: fname){
        if(!isalnum(ele)) converted_file_name += '_';
        else converted_file_name += ele;
    }
    cout<<"Converted file name is : \n";
    cout<<"Mark down file is : "<<converted_file_name<<".md"<<endl;
    cout<<"CPP file name is : "<<converted_file_name<<".cpp";
    return 0;
}