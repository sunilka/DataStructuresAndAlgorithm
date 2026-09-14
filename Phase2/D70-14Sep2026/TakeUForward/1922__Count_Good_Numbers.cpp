/*
1922. Count Good Numbers
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303
 

Constraints:

1 <= n <= 1015
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(long long n) {
        if (n == 1) return 5;
        if (n % 2 == 0) return (1LL * 4 * solve(n - 1)) % MOD;
        else return (1LL * 5 * solve(n - 1)) % MOD;
    }
    int countGoodNumbers(long long n) {
        return solve(n);
    }
};

/*
Time complexity: O(N), where N is the given n.
Space complexity: O(N) auxiliary stack space
*/

class Solution {
public:
    const int MOD = 1e9+7;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if(exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even_count = (n+1)/2;
        long long odd_count = n/2;
        long long even_ways = power(5, even_count);
        long long odd_ways = power(4, odd_count);
        return (odd_ways * even_ways)%MOD;
    }
};

/*
Time complexity: O(logN), where N is the given n.
Space complexity: O(N) auxiliary stack space
*/
