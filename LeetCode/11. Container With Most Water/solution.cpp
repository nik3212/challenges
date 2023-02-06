/*

11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the i-th line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0;
        int j = height.size() - 1;

        while (i < j) {
            res = max(res, (j - i) * std::min(height[i], height[j]));

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return res;
    }
};