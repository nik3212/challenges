/*

763. Partition Labels

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        std::vector<int> pos(26, -1);
        
        std::vector<int> ans;

        for (int i = n - 1; i >= 0; --i) {
            if (pos[s[i] - 'a'] == -1) {
                pos[s[i] - 'a'] = i;
            }
        }

        int k = -1;
        std::string str = "";

        for (int i = 0; i < n; ++i) {
            int last_index = pos[s[i] - 'a'];
            
            k = std::max(k, last_index);
            
            if (k == i) {
                str += s[i];
                ans.push_back(str.size());
                str = "";
                k = -1;
            } else {
                str += s[i];
            }
        }
        
        return ans;
    }
};