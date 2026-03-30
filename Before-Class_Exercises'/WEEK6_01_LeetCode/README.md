# 414-Third Maximum Number

## Code Structure
```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 1;
        int prev = nums[nums.size()-1];

        for (int i =  nums.size()-2 ; i >= 0 ; i--) {
            if (nums[i] != prev) { // 遇到不同數字
                count++;
                prev = nums[i];
            }
            if (count == 3) return prev; // 找到第三大
        }

        return nums[ nums.size() - 1 ]; // 不到第三大 → 回傳最大
    }
};
```
