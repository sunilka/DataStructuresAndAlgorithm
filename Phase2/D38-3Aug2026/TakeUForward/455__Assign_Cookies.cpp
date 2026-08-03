/*
455. Assign Cookies

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0) return 0;
        priority_queue<int> cookies(s.begin(), s.end());
        priority_queue<int> children(g.begin(), g.end());
        int ans = 0;

        while(!cookies.empty()){
            if(children.empty()) break;
            int cookie_size = cookies.top();
            int child_greed = children.top(); 
            if(cookie_size < child_greed){
                children.pop();
            }
            else{
                ans++;
                cookies.pop();
                children.pop();
            }
        }
        return ans;
    }
};

/*
455. Assign Cookies

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0) return 0;
        priority_queue<int> cookies(s.begin(), s.end());
        priority_queue<int> children(g.begin(), g.end());
        int ans = 0;

        while(!cookies.empty()){
            if(children.empty()) break;
            int cookie_size = cookies.top();
            int child_greed = children.top(); 
            if(cookie_size < child_greed){
                children.pop();
            }
            else{
                ans++;
                cookies.pop();
                children.pop();
            }
        }
        return ans;
    }
};

/*
Time complexity:
- O(G) -> to build the children priority queue (Floyd's heap construction).
- O(S) -> to build the cookies priority queue (Floyd's heap construction).
- O(GlogG + SlogS) -> To extract elements and match them in the while loop.
Total Time Complexity: O(G log G + S log S)

Space complexity: O(S + G)
*/

/*
Using sorting and 2 pointers
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child_ptr = 0; 
        int cookie_ptr = 0; 
        while (child_ptr < g.size() && cookie_ptr < s.size()) {
            if (s[cookie_ptr] >= g[child_ptr]) {
                child_ptr++; 
            }
            cookie_ptr++;
        }
        return child_ptr;
    }
};

/*

Time complexity: O(GlogG+SlogS+O(G+S))
Space complexity: O(1)
*/