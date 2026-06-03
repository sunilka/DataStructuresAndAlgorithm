/*

Union of Two Sorted Arrays

Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.

NOTE: Elements in the union should be in ascending order.

Examples

Input:n = 5,m = 5 arr1[] = {1,2,3,4,5}  arr2[] = {2,3,4,4,5}
Output: {1,2,3,4,5}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5}

Input:n = 10,m = 7,arr1[] = {1,2,3,4,5,6,7,8,9,10}arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12}

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> union_sorted_arrays(vector<int>& arr1, vector<int>& arr2){
    int n1 = arr1.size(), n2 = arr2.size(), p1 = 0, p2 = 0;
    vector<int> ans;

    while(p1<n1 && p2<n2){
        if(arr1[p1] <= arr2[p2]){
            if(ans.size() == 0 || ans[ans.size()-1] != arr1[p1]) ans.push_back(arr1[p1]);
            p1++;
        }
        else{
            if(ans.size() == 0 || ans[ans.size()-1] != arr2[p2]) ans.push_back(arr2[p2]);
            p2++;
        }
    }

    while(p1<n1){
        if(ans.size() == 0 || ans[ans.size()-1] != arr1[p1]) ans.push_back(arr1[p1]);
        p1++;
    }

    while(p2<n2){
        if(ans.size() == 0 || ans[ans.size()-1] != arr2[p2]) ans.push_back(arr2[p2]);
        p2++;
    }
    return ans;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> arr2 = {2,3,4,4,5,11,12};

    vector<int> ans = union_sorted_arrays(arr1, arr2);
    cout<<"Printing the union array here "<<endl;
    for(auto ele: ans) cout<<ele<<" ";
}

/*

Complexity analysis:

Time complexity: O(N+M), where N is the number of elements in the first array and the M is the number of elements in the second array.
Space complexity: O(N+M),  where N is the number of elements in the first array and the M is the number of elements in the second array. In the worst case, 
where are the elements in the arr1 and arr2 are unqiue then we would need an array of size N+M for the answer.

*/