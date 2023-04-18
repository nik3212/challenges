/*

836. Rectangle Overlap

An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.

*/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = 0, y1 = 1, x2 = 2, y2 = 3;
        
        return (std::min(rec1[y2], rec2[y2]) - std::max(rec2[y1], rec1[y1]) > 0) && 
               (std::min(rec1[x2], rec2[x2]) - std::max(rec2[x1], rec1[x1]) > 0);
    }
};