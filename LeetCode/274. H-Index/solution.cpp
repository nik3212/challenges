/*

274. H-Index

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r = citations.size();

        while (l < r) {
            int m = (l + r + 1) / 2;
            int c = 0;

            for (int i = 0; i < citations.size(); ++i) {
                if (citations[i] >= m) {
                    c++;
                }
            }

            if (c >= m) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
};