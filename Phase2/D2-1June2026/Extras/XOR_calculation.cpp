// calculating the bitwise XOR for the given elements in an array
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {};
    int ans = a[0], n = a.size();
    for(int i=1; i<n; i++) ans = ans ^ a[i];
    cout<<"Printing the bitwise XOR of the array elements here "<<ans<<endl;
}