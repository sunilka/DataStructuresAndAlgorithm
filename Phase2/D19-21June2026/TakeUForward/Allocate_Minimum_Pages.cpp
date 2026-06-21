/*

Allocate Minimum Pages

Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
All books must be allocated.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i], k ≤ 103

*/

#include<bits/stdc++.h>
using namespace std;

// Recursive way without using the framework of partition recursion. 
int calc(vector<int>& arr, int k, int pointer, vector<vector<int>>& as, vector<int>& cas){
    int n = arr.size();
    if(pointer == n){
        if( k==1 && !cas.empty()){
            as.push_back(cas);

            int max_pages_in_config = 0;
            for(auto sb: as){
                int css = 0;
                for(int p: sb) css+=p;
                max_pages_in_config = max(max_pages_in_config, css);
            }
            as.pop_back();
            return max_pages_in_config;
        }
        else return INT_MAX;
    }

    int ans = INT_MAX;
    if (!cas.empty() && k > 1) {
        as.push_back(cas);
        vector<int> empty_next_student;
        int ans1 = calc(arr, k - 1, pointer, as, empty_next_student);
        as.pop_back();
        ans = min(ans, ans1);
    }

    cas.push_back(arr[pointer]);
    int ans2 = calc(arr, k, pointer + 1, as, cas);
    cas.pop_back();
    ans = min(ans, ans2);

    return ans;
}


// Using the framework of partition recursion.
int calc2(vector<int> &arr, int k, int idx, int n){
    if(k==1){
        int rs = 0;
        for(int i=idx; i<n; i++) rs += arr[i];
        return rs;
    }

    if(idx == n) return INT_MAX;

    int ans = INT_MAX;
    int cs = 0;

    for(int i=idx; i<n; i++){
        cs += arr[i];
        int rops = calc2(arr, k-1, i+1, n);
        if (rops != INT_MAX) {
            int csm = max(cs, rops); 
            ans = min(ans, csm); 
        }
    }
    return ans;
}

/*

Analysing the time complexity of this approach. 

Generic framework for analysis of the time complexity of recusive functions = Number of states in the recusion * Time consumed per state. 

So, applying this formula for the above recusion, we can see this:

Number of states in the recursion = 2, namely, k=number of students, idx= which goes over N-1.
Time consumed per state of the recusion = n, because we are trying to split the array of size N.

*/


int findPages(vector<int>& arr, int k){
    int n = arr.size(), ans = -1;
    if(n < k) return -1;

    int low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = low + (high - low)/2; // this is the number of pages we are going to assign to each student
        int rs = 0, ns = 1;
        for(int i=0; i<n; i++){
            if(rs+arr[i] <= mid) rs+=arr[i];
            else{
                rs=arr[i];
                ns+=1;
            }
        }
        if(ns <= k){
            ans = mid;
            high = mid-1; 
        }
        else low = mid+1;
    }
    return ans;
}

int main(){
    vector<int> arr = {12, 34, 67, 90};
    int k=2;
    int ans = findPages(arr, k);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time Complexity: O(N * log(Sum - Max)) 
    - The while loop runs log(Sum - Max) times because the search space is cut in half each iteration.
    - Inside the loop, we iterate through the array of size N exactly once.
Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/