/*
128. Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 
Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109


*/

#include<bits/stdc++.h>
using namespace std;

vector<int> parent, size;

int find_parent(int i){
    if(parent[i] == i) return i;
    return parent[i] = find_parent(parent[i]);
}

void union_of_elements(int i, int j){
    int ri = find_parent(i);
    int rj = find_parent(j);

    if(ri == rj) return;

    // Path compression technique
    if(size[ri] < size[rj]){
        size[rj] += size[ri];
        parent[ri] = rj;
    }
    else{
        size[ri] += size[rj];
        parent[rj] = ri;
    }
}

int longestConsecutive(vector<int>& nums) {
    if(!nums.size()) return 0;

    int n = nums.size();
    set<int> s;
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    size.resize(n, 1);

    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) mp[nums[i]] = i; // Does not matter if the over ride happens, we just need to join the elements and we want only unique elements in the chain
    for(int i=n-1; i>=0; i--){
        if(s.count(nums[i])){
            continue;
        }
        int pe = nums[i] - 1;
        if(mp.count(pe)) union_of_elements(i, mp[pe]);
        int ne = nums[i] + 1;
        if(mp.count(ne)) union_of_elements(i, mp[ne]);
        s.insert(nums[i]);
    }
    return *max_element(size.begin(), size.end());
}

int main(){
    vector<int> nums ={0,3,7,2,5,8,4,6,0,1};
    int ans = longestConsecutive(nums);
    cout<<"Printing the longest consecutive element over here "<<ans<<endl;
}   

/*

Complexity analysis:

Time complexity: O(N*alpha(N)), where N is the number of elements present in the array, alpha(N) is the reverse ackermann function, which is how the DSU would work.
Space complexity: O(N), where N is the number of elements present in the array.

*/