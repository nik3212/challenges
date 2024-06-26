/*

Longest Consecutive Sequence

Given an array of integers A, find the length of the longest consecutive elements sequence.

*/

int longestConsecutiveSequence(std::vector<int> &A) {
    std::unordered_set<int> n(A.begin(), A.end());
    
    int res = 0;
    
    for (int k: A) {
        if (n.count(k - 1) == 0) {
            int num = k;
            int s = 1;

            while (n.count(num + 1) > 0) {
                num += 1;
                s += 1;
            }
            
            res = std::max(s, res);
        }
    }
    
    return res;
}