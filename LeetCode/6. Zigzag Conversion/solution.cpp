/*

6. Zigzag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }

        std::vector<std::string> v(numRows, "");

        int curr = 0;
        bool is_end = true;

        for (int i = 0; i < s.size(); ++i) {
            if (curr == 0 || curr == numRows - 1) {
                is_end = !is_end;
            }

            v.at(curr) += s.at(i);

            if (!is_end) {
                curr++;
            } else {
                curr--;
            }
        }

        std::string res;

        for (int i = 0; i < numRows; ++i) {
            res += v.at(i);
        }

        return res;
    }
};