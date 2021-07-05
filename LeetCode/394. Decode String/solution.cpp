class Solution {
public:
    std::string helper(int num, std::string& str, int& i) {
        std::string tmp = "";

        int current = 0;

        for (; i < str.size(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                current = current * 10 + str[i] - '0';
            } else if (str[i] == '[') {
                i += 1;
                tmp += helper(current, str, i);
                current = 0;
            } else if (str[i] == ']') {
                std::string result = "";
                for (int i = 0; i < num; ++i) {
                    result += tmp;
                }
                return result;
            } else {
                tmp += str[i];
            }
        }

        return tmp;
    }
    
    string decodeString(string s) {
        int idx = 0;
        return helper(0, s, idx);
    }
};