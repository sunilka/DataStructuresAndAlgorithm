/*

D. Xenia and Bit Operations
time limit per test2 seconds
memory limit per test256 megabytes
Xenia the beginner programmer has a sequence a, consisting of 2n non-negative integers: a1, a2, ..., a2n. Xenia is currently studying bit operations. To better understand how they work, Xenia decided to calculate some value v for a.

Namely, it takes several iterations to calculate value v. At the first iteration, Xenia writes a new sequence a1 or a2, a3 or a4, ..., a2n - 1 or a2n, consisting of 2n - 1 elements. In other words, she writes down the bit-wise OR of adjacent elements of sequence a. At the second iteration, Xenia writes the bitwise exclusive OR of adjacent elements of the sequence obtained after the first iteration. At the third iteration Xenia writes the bitwise OR of the adjacent elements of the sequence obtained after the second iteration. And so on; the operations of bitwise exclusive OR and bitwise OR alternate. In the end, she obtains a sequence consisting of one element, and that element is v.

Let's consider an example. Suppose that sequence a = (1, 2, 3, 4). Then let's write down all the transformations (1, 2, 3, 4)  →  (1 or 2 = 3, 3 or 4 = 7)  →  (3 xor 7 = 4). The result is v = 4.

You are given Xenia's initial sequence. But to calculate value v for a given sequence would be too easy, so you are given additional m queries. Each query is a pair of integers p, b. Query p, b means that you need to perform the assignment ap = b. After each query, you need to print the new value v for the new sequence a.

Input
The first line contains two integers n and m (1 ≤ n ≤ 17, 1 ≤ m ≤ 105). The next line contains 2n integers a1, a2, ..., a2n (0 ≤ ai < 230). Each of the next m lines contains queries. The i-th line contains integers pi, bi (1 ≤ pi ≤ 2n, 0 ≤ bi < 230) — the i-th query.

Output
Print m integers — the i-th integer denotes value v for sequence a after the i-th query.

Examples
inputCopy
2 4
1 6 3 5
1 4
3 4
1 2
1 2
outputCopy
1
3
3
3
Note
For more information on the bit operations, you can follow this link: http://en.wikipedia.org/wiki/Bitwise_operation
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> segmentTree;

void construct_segement_tree(const vector<int>& arr, int low, int high, int index, bool orr){
    if(low == high){
        segmentTree[index] = arr[low];
        return;
    }
    int mid = low + (high - low)/2;
    construct_segement_tree(arr, low, mid, 2*index+1, !orr);
    construct_segement_tree(arr, mid+1, high, 2*index+2, !orr);
    if(orr) segmentTree[index] = segmentTree[2*index+1] | segmentTree[2*index+2];
    else segmentTree[index] = segmentTree[2*index+1] ^ segmentTree[2*index+2];
}

void update_segment_tree(int update_index, int update_val, int low, int high, int index, bool orr){
    if(low == high){
        segmentTree[index] = update_val;
        return;
    }

    int mid = low + (high - low)/2;
    if(update_index <= mid) update_segment_tree(update_index, update_val, low, mid, 2*index+1, !orr);
    else update_segment_tree(update_index, update_val, mid+1, high, 2*index+2, !orr);
    
    if(orr) segmentTree[index] = segmentTree[2*index+1] | segmentTree[2*index+2];
    else segmentTree[index] = segmentTree[2*index+1] ^ segmentTree[2*index+2];
}

int main(){
    int l, no_q;
    if (!(cin >> l >> no_q)) return 0;
    
    int n = 1 << l;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    segmentTree.resize(4*n);

    if(l%2 == 0) construct_segement_tree(arr, 0, n-1, 0, false);
    else construct_segement_tree(arr, 0, n-1, 0, true);

    for(int i=0; i<no_q; i++){
        int update_index, update_val;
        cin >> update_index >> update_val;
        update_index--;
        if(l%2 == 0) update_segment_tree(update_index, update_val, 0, n-1, 0, false);
        else update_segment_tree(update_index, update_val, 0, n-1, 0, true);
        
        cout << segmentTree[0] << "\n"; 
    }
    return 0;
}