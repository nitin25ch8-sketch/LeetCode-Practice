class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        arr.reserve(nums.size()); // micro-optimization: avoid repeated reallocations

        // 1) Convert numbers to strings once.
        for (int x : nums) {
            arr.push_back(to_string(x));
        }

        // 2) Custom sort rule (core of the problem):
        //    For two strings a and b, we compare a+b vs b+a.
        //    Example:
        //      a = "9", b = "34"
        //      a+b = "934", b+a = "349"
        //      Since "934" > "349", "9" must come before "34".
        //
        //    Why this works:
        //    We are deciding local order of every pair so the final concatenation
        //    is globally maximum.
        sort(arr.begin(), arr.end(),
             [](const string& a, const string& b) {
                 // If placing a before b creates a larger combined value,
                 // then a should rank earlier
                 return a + b > b + a;
             });

        // 3) If first string is "0", then all values are zero (e.g., [0,0]).
        if (arr[0] == "0") return "0";

        // 4) Build final answer efficiently.
        //    Optional micro-optimization: pre-compute total length for reserve.
        size_t totalLen = 0;
        for (const string& s : arr) totalLen += s.size();

        string ans;
        ans.reserve(totalLen);
        for (const string& s : arr) ans += s;

        return ans;
    }
};