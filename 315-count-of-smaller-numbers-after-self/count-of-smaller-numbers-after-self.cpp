class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int total = nums.size();
        vector<int> answer(total);

        int lowest = nums[0];
        int highest = nums[0];

        for (int val : nums) {
            if (val < lowest)
                lowest = val;
            if (val > highest)
                highest = val;
        }

        int shift = 1 - lowest;
        int limit = highest - lowest + 2;

        vector<int> bit(limit, 0);

        for (int pos = total - 1; pos >= 0; pos--) {
            int key = nums[pos] + shift;

            int running = 0;

            // Query Fenwick Tree
            for (int idx = key - 1; idx > 0; idx -= idx & -idx) {
                running += bit[idx];
            }

            answer[pos] = running;

            // Update Fenwick Tree
            for (int idx = key; idx < limit; idx += idx & -idx) {
                bit[idx]++;
            }
        }

        return answer;
    }
};