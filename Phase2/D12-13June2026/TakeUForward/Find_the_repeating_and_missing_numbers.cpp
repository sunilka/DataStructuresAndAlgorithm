/*

Missing And Repeating

Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

Examples:

Input: arr[] = [2, 2]
Output: [2, 1]
Explanation: Repeating number is 2 and the missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: [3, 2]
Explanation: Repeating number is 3 and the missing number is 2.
Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: Repeating number is 1 and the missing number is 5.
Constraints:
2 ≤ n ≤ 106
1 ≤ arr[i] ≤ n

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size(), rn, mn;
    vector<int> elements(n, 0);
    for(auto ele: arr) elements[ele-1]+=1;
    for(int i=0; i<n; i++){
        if(elements[i] > 1) rn = i+1;
        if(elements[i] == 0) mn = i+1;
    }
    vector<int> ans = {rn, mn};
    return ans;
}

int main(){
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> ans = findTwoElement(arr);
    cout<<"Printing the answer here "<<endl;
    for(auto ele: ans) cout<<ele<<" ";
    cout<<endl;
}

/*

Complexity analysis:

Time complexity: O(N), where N is the number of elements present in the array.
Space complexity: O(N), where N is the number of elements present in the array.

*/