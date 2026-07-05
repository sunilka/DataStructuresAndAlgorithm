/*
Aggressive_Cows.cpp
*/

#include<bits/stdc++.h>
using namespace std;

bool _can_place_cows(vector<int>& arr, int k, int gap_needed){
    int lpcp = arr[0], n=arr.size();
    k--;
    for(int i=1; i<n; i++){
        if(arr[i] - lpcp >=gap_needed){
            k--;
            if(k == 0) return true;
            lpcp = arr[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int low = 1, high = (arr[n-1] - arr[0]), ans = -1;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(_can_place_cows(arr, k, mid)){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}

int main(){
    vector<int> arr={10, 1, 2, 7, 5};
    int k=3;
    int ans = aggressiveCows(arr, k);
    cout<<"Printing my answer here "<<ans<<endl;
}