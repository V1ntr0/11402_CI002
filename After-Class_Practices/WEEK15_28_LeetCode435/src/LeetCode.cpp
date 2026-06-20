class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 按照區間的終點（第二個數字）由小到大排
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1; // 預計能留下來的區間數，第一個一定選
        int end_pos = intervals[0][1]; // 目前最靠前結束的邊界

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end_pos) {
                count++;
                end_pos = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};