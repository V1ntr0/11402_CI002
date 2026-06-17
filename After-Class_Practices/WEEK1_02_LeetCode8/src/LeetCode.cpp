class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        long long num = 0;
        int sign = 1;

        // 1. 跳過空白
        while (i < n && s[i] == ' ')
            i++;

        // 2. 處理正負號
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. 讀數字
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // 4. overflow 提前處理
            if (sign == 1 && num > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -num < INT_MIN)
                return INT_MIN;

            i++;
        }

        return (int)(num * sign);
    }
};