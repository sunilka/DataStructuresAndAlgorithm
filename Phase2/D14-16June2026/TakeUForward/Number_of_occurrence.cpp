/*

Number of occurrence

Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

Examples :

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.
Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106

*/

#include<bits/stdc++.h>
using namespace std;

int getMinIndex(vector<int>& arr, int target){
    int low = 0, high = arr.size()-1, ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target) ans = mid;
        if(arr[mid] == target || arr[mid] > target) high = mid-1;
        else low = mid+1;
    }
    return ans;
}

int getMaxIndex(vector<int>& arr, int target){
    int low = 0, high = arr.size()-1, ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target) ans = mid;
        if(arr[mid] == target || arr[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return ans;
}

int countFreq(vector<int>& arr, int target) {
    int mini = getMinIndex(arr, target);
    if(mini == -1) return 0;

    int maxi = getMaxIndex(arr, target);
    return maxi - mini + 1;
}

int main(){
    vector<int> arr = {8, 9, 10, 12, 12, 12};
    int target = 12;
    int ans = countFreq(arr, target);
    cout<<"Printing the answer here "<<ans<<endl;
}


/*

Space complexity:

Time complexity: O(logN + logN) = O(logN), where N is the number of elements present in the array.
Space complexity: O(1), we do not use any extra space, hence the space complexity is constant.

*/