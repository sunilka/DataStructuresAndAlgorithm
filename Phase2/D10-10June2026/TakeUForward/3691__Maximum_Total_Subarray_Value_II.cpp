/*

3691. Maximum Total Subarray Value II

You are given an integer array nums of length n and an integer k.

You must select exactly k distinct subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.

The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

The total value is the sum of the values of all chosen subarrays.

Return the maximum possible total value you can achieve.


Example 1:

Input: nums = [1,3,2], k = 2

Output: 4

Explanation:

One optimal approach is:

Choose nums[0..1] = [1, 3]. The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2.
Choose nums[0..2] = [1, 3, 2]. The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2.
Adding these gives 2 + 2 = 4.

Example 2:

Input: nums = [4,2,5,1], k = 3

Output: 12

Explanation:

One optimal approach is:

Choose nums[0..3] = [4, 2, 5, 1]. The maximum is 5 and the minimum is 1, giving a value of 5 - 1 = 4.
Choose nums[1..3] = [2, 5, 1]. The maximum is 5 and the minimum is 1, so the value is also 4.
Choose nums[2..3] = [5, 1]. The maximum is 5 and the minimum is 1, so the value is again 4.
Adding these gives 4 + 4 + 4 = 12.

 

Constraints:

1 <= n == nums.length <= 5 * 10​​​​​​​4
0 <= nums[i] <= 109
1 <= k <= min(105, n * (n + 1) / 2)

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int mini, maxi;
};


vector<Node*> segmentTree;

void constructSegmentTree(vector<int>& nums, int low, int high, int index){
    if(low == high){
        Node* newnode = new Node();
        newnode->mini = nums[low];
        newnode->maxi = nums[high];
        segmentTree[index] = newnode;
        return;
    }

    int mid = low + (high - low)/2;
    constructSegmentTree(nums, low, mid, 2*index+1);
    constructSegmentTree(nums, mid+1, high, 2*index+2);
    
    Node* newnode = new Node();
    newnode->mini = min(segmentTree[2*index+1]->mini, segmentTree[2*index+2]->mini);
    newnode->maxi = max(segmentTree[2*index+1]->maxi, segmentTree[2*index+2]->maxi);
    segmentTree[index] = newnode;
}

Node query(int slow, int shigh, int qlow, int qhigh, int index){
    // No overlap
    if(qhigh < slow || qlow > shigh){
        return {INT_MAX, INT_MIN};
    }

    // Full overlap
    if(qlow <= slow && shigh <= qhigh){
        return *(segmentTree[index]);
    }

    // Partial overlap case
    int mid = slow + (shigh - slow)/2;
    Node leftChild = query(slow, mid, qlow, qhigh, 2*index+1);
    Node rightChild = query(mid+1, shigh, qlow, qhigh, 2*index+2);
    
    Node result;
    result.mini = min(leftChild.mini, rightChild.mini);
    result.maxi = max(leftChild.maxi, rightChild.maxi);
    return result;
}

long long maxTotalValue(vector<int>& nums, int k) {
    int n = nums.size();
    if(n == 0 || k == 0) return 0;
    
    segmentTree.assign(4*n, nullptr);
    constructSegmentTree(nums, 0, n-1, 0);
    
    priority_queue<int> pq;
    for(int l = 0; l < n; l++) {
        for(int r = l; r < n; r++) {
            Node res = query(0, n-1, l, r, 0);
            int sub_value = res.maxi - res.mini;
            pq.push(sub_value);
        }
    }
    
    long long max_total_value = 0;
    for(int i = 0; i < k && !pq.empty(); i++) {
        max_total_value += pq.top();
        pq.pop();
    }
    
    for(auto node : segmentTree) {
        if(node != nullptr) delete node;
    }
    
    return max_total_value;
}

int main(){
    vector<int> nums = {4, 2, 5, 1}; 
    int k = 3;
    long long ans = maxTotalValue(nums, k);
    cout << "Printing the answer here: " << ans << endl; // Output: 12
    return 0;
}