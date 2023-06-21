/*

832. Flipping an Image

Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].

*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& m) {
        int n = m.size();
        int u = m[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (u + 1) / 2; ++j) {
                m[i][j] ^= 1;
    
                if (u - j - 1 != j) { m[i][u - j - 1] ^= 1; }

                std::swap(m[i][j], m[i][u - j - 1]);
            }
        }

        return m;
    }
};