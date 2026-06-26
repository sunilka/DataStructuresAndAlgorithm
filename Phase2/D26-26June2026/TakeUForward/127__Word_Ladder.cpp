/*
127. Word Ladder

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

#include<bits/stdc++.h>
using namespace std;

int get_diff_count(string s1, string s2){
    if(s1.length()!=s2.length()) return INT_MAX;
    int diff_count = 0;
    for(int i=0; i<s1.length(); i++){
        if(s1[i]!=s2[i]) diff_count+=1;
    }
    return diff_count;
}

int bfs(vector<vector<int>>& connections, string beginWord, string endWord, vector<string>& wordList){
    int n = wordList.size();
    vector<int> distance(n, 0);
    vector<bool> visited(n, false);
    queue<int> q;

    int endWordindex = -1;
    for(int i=0; i<n; i++){
        if(wordList[i] == endWord){
            endWordindex = i;
            break;
        }
    }
    
    // push all the words into the q which are 1 in difference present in the word list
    for(int i=0; i<n; i++){
        if(get_diff_count(wordList[i], beginWord) == 1){
            q.push(i);
            visited[i] = true;
            distance[i] = 2;
        }
    }

    while(!q.empty()){
        int cwi = q.front();
        q.pop();

        if(cwi == endWordindex) return distance[cwi];

        vector<int>& connected_nodes = connections[cwi];
        for(int i=0; i<connected_nodes.size(); i++){
            int neighbour = connected_nodes[i];
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
                distance[neighbour] = distance[cwi] + 1;
            }
        }
    }
    return 0;
}

int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
    if(beginWord == endWord) return 0;

    bool end_word_exists = false;
    for(auto s: wordList){
        if(s == endWord) end_word_exists = true;
    }
    if(!end_word_exists) return 0;

    int n = wordList.size();
    vector<vector<int>> connections(n);

    // Creating the connections.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            string s1 = wordList[i], s2 = wordList[j];
            int dc = get_diff_count(s1, s2);
            if(dc == 1) connections[i].push_back(j);
        }
    }
    return bfs(connections, beginWord, endWord, wordList);
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordset(wordList.begin(), wordList.end());
    if(wordset.find(endWord) == wordset.end()) return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while(!q.empty()){
        auto [word, steps] = q.front();
        q.pop();
        if(word == endWord) return steps;

        for(int i=0; i<word.length(); i++){
            char originalchar = word[i];
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                if(wordset.find(word) != wordset.end()){
                    wordset.erase(word);
                    q.push({word, steps+1});
                }
            }
            word[i] = originalchar;
        }
    }
    return 0;
}

int main(){
    string beginWord="hit";
    string endWord="cog";
    vector<string> wordList={"hot","dot","dog","lot","log","cog"};
    int ans = ladderLength(beginWord, endWord, wordList);
    cout<<"Printing my answer here "<<ans<<endl;
}

/*

Complexity analysis:

Time complexity: O(N * (L^2) * 26), where N is the number of words in wordList and L is the length of each word.
- Each of the N words is pushed and popped from the queue at most once.
- For each word, we mutate L characters across 26 possibilities.
- Checking/erasing a string from the hash set takes O(L) time to calculate the string's hash value.

Space complexity: O(N * L), where N is the number of words in wordList and L is the length of each word.
- The `unordered_set` holds up to N strings of length L.
- The BFS queue holds at most O(N * L) string data at peak capacity.

*/