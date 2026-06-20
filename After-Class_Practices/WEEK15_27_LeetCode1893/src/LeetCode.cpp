class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        // 因為數字最大到 50，加上 end + 1 的操作，陣列開 52 很安全
        vector<int> diff(52, 0);

        // 建立差分陣列，只標記端點
        for (auto& r : ranges) {
            diff[r[0]]++;
            diff[r[1] + 1]--;
        }

        int curr_coverage = 0;

        // 由左往右累加，還原出每個位置的覆蓋次數
        for (int i = 1; i <= 50; i++) {
            curr_coverage += diff[i];

            // 如果走到目標範圍內，檢查有沒有 沒被蓋到的地方
            if (i >= left && i <= right) {
                if (curr_coverage <= 0) {
                    return false;
                }
            }
        }

        return true;
    }
};