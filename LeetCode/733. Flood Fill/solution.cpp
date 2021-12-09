/*

733. Flood Fill

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

*/

class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int initial, int newColor) {
        if (
            sr < 0 || sr >= image.size() || 
            sc < 0 || sc >= image[0].size() ||
            image[sr][sc] != initial
        ) {
            return;
        }
        
        image[sr][sc] = newColor;

        dfs(image, sr - 1, sc, initial, newColor);
        dfs(image, sr + 1, sc, initial, newColor);
        dfs(image, sr, sc - 1, initial, newColor);
        dfs(image, sr, sc + 1, initial, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (newColor == image[sr][sc]) { 
            return image;
        }

        int initialColor = image[sr][sc];

        dfs(image, sr, sc, initialColor, newColor);

        return image;
    }
};