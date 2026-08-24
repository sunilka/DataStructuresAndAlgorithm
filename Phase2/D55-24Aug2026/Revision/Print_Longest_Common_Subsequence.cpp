/*
Problem Description: Given two strings str1 and str2, print the longest common subsequence of the two strings.

A subsequence of a string is a list of characters of the string where zero or more characters are deleted and they should be in the same order in the subsequence as in the original string.
*/

#include<bits/stdc++.h>
using namespace std;

string lcs(string &s1, string &s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            if(s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1] + 1;
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    int i=0, j=0;
    string ans = "";
    while(i<n1 && j<n2){
        if(s1[i] == s2[j]) ans += s1[i], i++, j++;
        else{
            if(dp[i+1][j] >= dp[i][j+1]) i = i+1;
            else j = j+1;
        }
    }
    return ans;
}

int main(){
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    string ans = lcs(s1, s2);
    cout<<"Printing the longest common subsequence here "<<ans<<endl;
}

/*
Time complexity: O(n1*n2) where n1 is the number of characters in the string s1 and n2 is the number of characters in the string s2.
Space complexity: O(n1*n2) for the DP array and please note that there is no auxiliary stack space involved here.  
*/