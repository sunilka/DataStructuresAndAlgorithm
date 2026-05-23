#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Paste the file name here 
string fname = "1752. Check if Array Is Sorted and Rotated";

int main(){
    string converted_file_name  = "";
    for(auto ele: fname){
        if(ele == '.' || ele == ' ') converted_file_name += '_';
        else converted_file_name += ele;
    }
    cout<<"Converted file name is : \n"<<converted_file_name;
    return 0;
}