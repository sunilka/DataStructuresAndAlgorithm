/*

733. Flood Fill

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.


Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:

From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

Output: [[0,0,0],[0,0,0]]

Explanation:

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size(), n = image[0].size(), src_c = image[sr][sc];
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;
    
    while(!q.empty()){
        auto [pr, pc] = q.front();
        q.pop();

        for(int i=0; i<dirs.size(); i++){
            int npr = pr + dirs[i].first, npc = pc + dirs[i].second;
            if(npr <0 || npr >=m || npc <0 || npc >= n) continue;
            if(image[npr][npc] == color) continue;
            if(image[npr][npc] == src_c){
                image[npr][npc] = color;
                q.push({npr, npc});
            }
        }
    }
    return image;
}

int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr=1, sc=1, color=2;
    vector<vector<int>> ans = floodFill(image, sr, sc, color);

    cout<<"Printing my answer image here "<<endl;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/*

Complexity analysis:

Time complexity: O(m*n), where m is the number of rows in the matrix and the n is the number of cols present in the matrix.
Space complexity: O(m*n), where m is the number of rows in the matrix and the n is the number of cols present in the matrix.s

*/