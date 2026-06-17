class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long n = x;
        long long rev = 0;

        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }

        return rev == x;
    }
};