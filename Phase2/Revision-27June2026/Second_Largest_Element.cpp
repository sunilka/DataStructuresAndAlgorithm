/*

Find the second largest element present in the array.

*/

#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> arr){
    int l = INT_MIN, sl = INT_MIN;
    for(auto ele: arr){
        if(ele > l){
            sl = l;
            l = ele;
        }
        else{
            sl = max(sl, ele);
        }
    }
    return sl;
}

int main(){
    vector<int> arr = {1, 1, 1, 1, 1};
    int ans = secondLargest(arr);
    cout<<"Printing the answer here "<<ans<<endl;   
}