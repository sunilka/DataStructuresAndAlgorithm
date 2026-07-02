/*
Count inversions.
*/

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high, int &ans){
    vector<int> left, right;
    for(int i=low; i<=mid; i++) left.push_back(arr[i]);
    for(int i=mid+1; i<=high; i++) right.push_back(arr[i]);

    int p1 = 0, p2 = 0, n1 = left.size(), n2 = right.size();
    vector<int> temp;

    while(p1<n1 && p2<n2){
        if(left[p1] <= right[p2]){
            temp.push_back(left[p1]);
            p1++;
        }
        else{
            ans+=(n1-p1);
            temp.push_back(right[p2]);
            p2++;
        }
    }

    while(p1<n1) temp.push_back(left[p1++]);
    while(p2<n2) temp.push_back(right[p2++]);

    // put the elements back into the original array.
    int p = low;
    for(int i=0; i<temp.size(); i++){
        arr[p++] = temp[i];
    }
}

void merge_sort(vector<int>& arr, int low, int high, int &ans){
    if(low<high){
        int mid = low + (high - low)/2;
        merge_sort(arr, low, mid, ans);
        merge_sort(arr, mid+1, high, ans);
        merge(arr, low, mid, high, ans);
    }
}

int inversionCount(vector<int> &arr) {
    int ans = 0;
    merge_sort(arr, 0, arr.size()-1, ans);
    return ans;
}

int main(){
    vector<int> arr;
    int ans = inversionCount(arr);
    cout<<"Printing the inversions count here "<<ans<<endl;
}