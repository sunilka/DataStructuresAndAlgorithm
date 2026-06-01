/*
We are going to develop this segment tree for the case of the min findings of a given range.

Analysis of the time complexity:

Let us consider N as the number of elements in the array

1) construct method -> O(N)
2) Query method -> O(logN)
3) Update method -> O(logN)


Analysis of the space complexity:

Tree Storage: O(N) because we resize the vector to 4 * n.
Call Stack (Auxiliary Space): O(logN) for query and update due to the recursion depth, and O(logN) for construct.
s
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> segmentTree;

void construct_segment_tree(vector<int> arr, int low, int high, int index){
    if(low == high){
        segmentTree[index] = arr[low];
        return;
    }

    int mid = low+(high-low)/2;
    construct_segment_tree(arr, low, mid, 2*index+1);
    construct_segment_tree(arr, mid+1, high, 2*index+2);
    segmentTree[index] = min(segmentTree[2*index+1], segmentTree[2*index+2]);
}

/*
There are 3 cases that we need to consider in the case of the query they are:

1) Partial overlap -> Other conditions other than the below conditions
2) Full overlap [slow qlow qhigh shigh]
3) No overlap [qlow qhigh slow shigh] || [slow shigh qlow qhigh]
*/

int query(int qlow, int qhigh, int slow, int shigh, int index){    
    // No overlap
    if(qhigh < slow || qlow > shigh){
        return INT_MAX;
    }

    // Full overlap
    if(qlow <= slow && shigh <= qhigh){
        return segmentTree[index];
    }

    // Partial overlap case
    int mid = slow+(shigh-slow)/2;
    return min(query(qlow, qhigh, slow, mid, 2*index+1), query(qlow, qhigh, mid+1, shigh, 2*index+2));
}

// Point updates
void update(int update_index, int update_val, int low, int high, int index){
    if(low == high){
        segmentTree[index]  = update_val;
        return;
    }
    
    int mid = low+(high-low)/2;
    if(update_index <= mid) update(update_index, update_val, low, mid, 2*index+1);
    else update(update_index, update_val, mid+1, high, 2*index+2);
    segmentTree[index] = min(segmentTree[2*index+1], segmentTree[2*index+2]);    
}

void print_segment_tree(){
    cout<<"Printing the constructed segement tree over here "<<endl;
    for(auto ele: segmentTree){
        cout<<ele<<" "; 
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1, 0, 2, 3, 0, 4, 1, 0};
    int n = arr.size();
    segmentTree.resize(4*n);    
    construct_segment_tree(arr, 0, n-1, 0);
    print_segment_tree();
}