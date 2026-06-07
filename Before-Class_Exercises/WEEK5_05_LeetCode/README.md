# 179-Largest Number

## Code Structure
```cpp
class Solution {
public:
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> strs;

        // 轉成字串
        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        // 自訂排序
        sort(strs.begin(), strs.end(), cmp);

        // 特殊情況：全部都是 0
        if (strs[0] == "0") return "0";

        // 拼接答案
        string result = "";
        for (string s : strs) {
            result += s;
        }

        return result;
    }
};
```
