/*
282. Expression Add Operators
Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.

Note that a number can contain multiple digits.

 

Example 1:

Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
Example 2:

Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
Example 3:

Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
 

Constraints:

1 <= num.length <= 10
num consists of only digits.
-231 <= target <= 231 - 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string& num, int n, int target, int idx, long long cans, long long prev, string cexp, vector<string>& ans) {
        if (idx == n) {
            if (cans == target) {
                ans.push_back(cexp);
            }
            return;
        }

        for (int i = idx; i < n; i++) {
            if (i > idx && num[idx] == '0') break;

            string part = num.substr(idx, i - idx + 1);
            long long cur_val = stoll(part);

            if (idx == 0) solve(num, n, target, i + 1, cur_val, cur_val, part, ans);
            else {
                solve(num, n, target, i + 1, cans + cur_val, cur_val, cexp + '+' + part, ans);
                solve(num, n, target, i + 1, cans - cur_val, -cur_val, cexp + '-' + part, ans);
                solve(num, n, target, i + 1, (cans - prev) + (prev * cur_val), prev * cur_val, cexp + '*' + part, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        int n = num.size();
        if (n == 0) return ans;
        solve(num, n, target, 0, 0, 0, "", ans);
        return ans;
    }
};

/*
Time complexity: O(4^N), where N is the number of characters present in the string.
Space complexity: O(N) auxiliary stack space because of the recursion.
*/