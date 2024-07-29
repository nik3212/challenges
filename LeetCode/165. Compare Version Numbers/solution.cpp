/*

165. Compare Version Numbers

Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.

*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();

        int i = 0, j = 0;

        while (i < n1 || j < n2) {
            int x = 0;
            while (i < n1 && version1[i] != '.') {
                x = 10 * x + (version1[i++] - '0');
            }
            int y = 0;
            while (j < n2 && version2[j] != '.') {
                y = 10 * y + (version2[j++] - '0');
            }
            
            if (x < y) { return -1; }
            if (x > y) { return 1; }

            if (i < n1 && version1[i] == '.') i++;
            if (j < n2 && version2[j] == '.') j++;
        }
        
        return 0;
    }
};