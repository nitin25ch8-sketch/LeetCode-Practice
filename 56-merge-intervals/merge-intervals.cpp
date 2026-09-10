class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Store the final non-overlapping intervals
        vector<vector<int>> res;

        // Sort intervals based on their starting value
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        // Start with the first interval
        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];

        // Process the remaining intervals
        for (int i = 1; i < intervals.size(); i++) {

            // If the next interval starts before or at
            // the end of the current interval, they overlap
            if (intervals[i][0] <= currEnd) {

                // Extend the current interval if necessary
                currEnd = max(currEnd, intervals[i][1]);

            } else {

                // No overlap, so store the current interval
                res.push_back({currStart, currEnd});

                // Start a new current interval
                currStart = intervals[i][0];
                currEnd = intervals[i][1];
            }
        }

        // Add the last merged interval
        res.push_back({currStart, currEnd});

        return res;
    }
};