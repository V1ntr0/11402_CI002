class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<>
        > pq;

        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int ans = 0;

        while (k--) {
            auto [val, r, c] = pq.top();
            pq.pop();
            ans = val;

            if (c + 1 < n) {
                pq.push({matrix[r][c + 1], r, c + 1});
            }
        }

        return ans;
    }
};