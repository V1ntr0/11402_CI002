# 169-Majority Element

## Code Structure
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                majority = num;
            }

            if (num == majority) {
                count++;
            } else {
                count--;
            }
        }

        return majority;
    }
};
```
