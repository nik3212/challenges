class Solution {
public:
    std::string helper(std::string& str, int& i) {
        std::string tmp = "";

        int num = 0;

        for (; i < str.size(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + str[i] - '0';
            } else if (str[i] == '[') {
                i += 1;
                auto result = helper(str, i);

                for (int i = 0; i < num; ++i) {
                    tmp += result;
                }

                num = 0;
            } else if (str[i] == ']') {
                return tmp;
            } else {
                tmp += str[i];
            }
        }

        return tmp;
    }
    
    string decodeString(string s) {
        int idx = 0;
        return helper(s, idx);
    }
};