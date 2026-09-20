class Solution {
public:

    void backtracking(int &ans,
                      unordered_map<int,int> &left,
                      unordered_map<int,int> &lowerDiagonal,
                      unordered_map<int,int> &upperDiagonal,
                      int n,
                      int col) {

        // All columns filled -> one valid arrangement
        if (col == n) {
            ans++;
            return;
        }

        // Try placing queen in every row of this column
        for (int row = 0; row < n; row++) {

            // Check if queen already exists in:
            // same row
            // lower diagonal: row + col
            // upper diagonal: row - col
            if (left[row] ||
                lowerDiagonal[row + col] ||
                upperDiagonal[row - col]) {
                continue;
            }

            // Place queen
            left[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[row - col] = 1;

            // Move to next column
            backtracking(ans, left, lowerDiagonal,
                         upperDiagonal, n, col + 1);

            // Remove queen (backtrack)
            left[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[row - col] = 0;
        }
    }

    int totalNQueens(int n) {

        int ans = 0;

        // Same row
        unordered_map<int,int> left;

        // row + col
        unordered_map<int,int> lowerDiagonal;

        // row - col
        unordered_map<int,int> upperDiagonal;

        // Start from column 0
        backtracking(ans, left, lowerDiagonal,
                     upperDiagonal, n, 0);

        return ans;
    }
};