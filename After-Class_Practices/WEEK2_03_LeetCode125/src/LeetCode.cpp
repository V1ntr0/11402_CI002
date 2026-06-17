class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {

            // 左邊跳過非字母數字
            while (l < r && !isalnum(s[l]))
                l++;

            // 右邊跳過非字母數字
            while (l < r && !isalnum(s[r]))
                r--;

            if (tolower(s[l]) != tolower(s[r]))
                return false;

            l++;
            r--;
        }

        return true;
    }
};