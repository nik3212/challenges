/*

997. Find the Town Judge

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

1. The town judge trusts nobody.
2. Everybody (except for the town judge) trusts the town judge.
3. There is exactly one person that satisfies properties 1 and 2.

You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        std::vector<int> degree(N + 1, 0);
        
        for(auto item: trust) {
            degree[item[0]]--;
            degree[item[1]]++;
        }
        
        for (size_t i = 1; i <= N; ++i) {
            if (degree[i] == N - 1) {
                return i;
            }
        }
        
        return -1;
    }
};