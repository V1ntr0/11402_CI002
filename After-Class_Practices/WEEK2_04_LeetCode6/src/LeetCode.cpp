class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> rows(numRows);
        int curRow = 0;
        int dir = -1;

        for (char c : s) {
            rows[curRow] += c;

            if (curRow == 0 || curRow == numRows - 1) {
                dir *= -1;
            }

            curRow += dir;
        }

        string ans;
        for (string &row : rows) {
            ans += row;
        }

        return ans;
    }
};