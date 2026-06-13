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

/*

Complexity analysis:

Time complexity: O(N), where N is the number of elements present in the array.
Space complexity: O(N), where N is the number of elements present in the array.

*/

vector<int> findTwoElement(vector<int>& arr) {
    long long n = arr.size();
    long long sn = (n*(n+1))/2;
    long long s2n = (n*(n+1)*(2*n+1))/6;
    long long s = 0, s2 = 0;
    for(int i=0; i<n; i++){
        s+=(long long)arr[i];
        s2+=(long long)arr[i]*(long long)arr[i];
    }
    long long val1 = s - sn;
    long long val2 = s2 - s2n;
    val2 = val2/val1;
    long long x = (val1 + val2)/2;
    long long y = x - val1;
    return {(int)x, (int)y};
}

/*

Complexity analysis:

Time complexity: O(N), for the summation, where N is the number of elements present in the array.
Space complexity: O(1), we do not use any extra space, expect some vairbales, hence the space complexity is constant. 

*/

int main(){
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> ans = findTwoElement(arr);
    cout<<"Printing the answer here "<<endl;
    for(auto ele: ans) cout<<ele<<" ";
    cout<<endl;
}

