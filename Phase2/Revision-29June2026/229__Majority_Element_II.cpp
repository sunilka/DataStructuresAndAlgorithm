/*
Find the elements that appear more than n/3 times.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size(), e1 = -1, c1 = 0, e2 = -1, c2 = 0;
    for(int i=0; i<n; i++){
        int ele = nums[i];
        if(c1>0 && ele == e1) c1+=1;
        else if(c2>0 && ele == e2) c2+=1;
        else if(c1 == 0) e1 = ele, c1 = 1;
        else if(c1 == 0) e2 = ele, c2 = 1;
        else c1-=1, c2-=1;
    }   

    c1=0, c2=0;
    for(auto ele: nums){
        if(ele == e1) c1+=1;
        else if (ele == e2) c2+=1;
    }
    int rq = n/3 +1;  // We are doing plus once since we want greater than n/3 and not equal to.
    if(c1 >= rq) ans.push_back(e1);
    if(c2 >= rq) ans.push_back(e2);
    return ans;
}

int main(){
    vector<int> nums;
    vector<int> ans = majorityElement(nums);
    cout<<"Printing the answer here "<<endl;
    for(auto ele: ans) cout<<ele<<" ";
}