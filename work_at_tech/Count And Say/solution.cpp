/*

Count And Say

Count-And-Say is a sequence of numbers given below:

1
11
21
1211
111221
This sequence starts with 1.

1 is read as one 1 → 11

11 is read as two 1 → 21

21 is read as one 2, one 1 → 1211

1211 is read as one 1, one 2, two 1 → 111221

And so on…

Given a number n, find the nth sequence.

*/

std::string count(int n) {
    std::string res = "1";
    
    for (int i = 2; i <= n; ++i) {
        std::string next;
        char curr = res[0];
        int c = 1;
        
        for (int j = 1; j < res.size(); ++j) {
            if (res[j] == curr) {
                c++;
            } else {
                next += std::to_string(c) + curr;
                curr = res[j];
                c = 1;
            }
        }
        
        next += std::to_string(c) + curr;
        res = next;
    }
    
    return res;
}

string countAndSay(int n) {
    if (n == 1) {
		return "1";
	}
	
	return count(n);
}