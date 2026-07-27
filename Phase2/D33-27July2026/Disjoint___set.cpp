/*
Disjoint set union algorithm.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> size;

int find_parent(int u){
    if(parent[u] == u) return u;
    return parent[u] =  find_parent(parent[u]);
}

void union_of_elements(int u, int v){
    int parent_u = find_parent(u);
    int parent_v = find_parent(v);

    if(parent_u == parent_v) return;

    if(size[parent_u] > size[parent_v]){
        parent[parent_v] = parent_u;
        size[parent_u] += size[parent_v];
    }

    else{
        parent[parent_u] = parent_v;
        size[parent_v] += size[parent_u];
    }
}


int main(){
    int V=10;
    parent.resize(V);
    size.resize(V);
    iota(parent.begin(), parent.end(), 0);
    fill(size.begin(), size.end(), 1);
}

/*
Time complexity: O(V+Qalpha(V)), where Q is the time on the queries.
Space complexity: O(V)
*/