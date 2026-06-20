/*

Aggressive Cows

You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples:

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows in this case is 3, which is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows in this case is 4, which is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: There are 6 stalls and only 5 cows, we try to place the cows such that the minimum distance between any two cows is as large as possible.
The minimum distance between cows in this case is 1, which is the largest among all possible ways.
Constraints:
2 ≤ stalls.size() ≤ 106
0 ≤ stalls[i] ≤ 108
2 ≤ k ≤ stalls.size()

*/

#include<bits/stdc++.h>
using namespace std;

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[stalls.size()-1] - stalls[0], ans = -1, n = stalls.size();
    while(low<=high){
        int mid = low + (high - low)/2, cp = 1, lcp = stalls[0]; // Here mid is denoting the minimum amount of gap between the aggressive cows
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - lcp >= mid) {
                cp++;
                lcp = stalls[i];
            }
        }
        if(cp >= k){ // Increase the min distance of placement, but note down the possible answer before you do that
            ans = mid;
            low = mid + 1; 
        }
        else high = mid-1;
    }
    return ans;
}

int main(){
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    int ans = aggressiveCows(stalls, k);
    cout<<"Printing the answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(NlogN) + O(Nlog(max_element - min_element)), first one is for the sorting and the second one is for searching for the answer, 
where N is the number of elements present in the array and the max_element is the max element present in the 
array and the min element is the minimum element present in the array.

Space complexity: O(1), we are not using any extra space, hence the space complexity is constant.

*/