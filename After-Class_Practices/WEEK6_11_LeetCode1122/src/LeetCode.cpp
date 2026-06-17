class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;

        for (int x : arr1) {
            freq[x]++;
        }

        vector<int> ans;

        for (int x : arr2) {
            while (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }

        vector<int> rest;
        for (auto& [num, count] : freq) {
            while (count--) {
                rest.push_back(num);
            }
        }

        sort(rest.begin(), rest.end());

        for (int x : rest) {
            ans.push_back(x);
        }

        return ans;
    }
};