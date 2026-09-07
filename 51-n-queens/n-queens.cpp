
void backtracking(vector<string>& chessBoard,vector<vector<string>>& ans,unordered_map<int,int>& left,unordered_map<int,int>& lowerDiagonal,unordered_map<int,int>& upperDiagonal,int& n,int col){
    // we fill up the board , all columns filled
    if( col == n){
        ans.push_back(chessBoard);
        return;
    }

    for(int row = 0; row < n; row++){ // Try every row in the current column
        // Check whether placing Q here causes any conflict
        if(left[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[row-col] == 0){
            // mark the maps and board
            left[row]++; lowerDiagonal[row+col]++ ; upperDiagonal[row-col]++;
            chessBoard[row][col] = 'Q';
            // move to next column
            backtracking(chessBoard,ans,left,lowerDiagonal,upperDiagonal,n,col+1);
            // unmark the maps and board
            chessBoard[row][col] = '.';
            left[row] -- ; lowerDiagonal[row+col] -- ; upperDiagonal[row-col] -- ;
        }
    }
}
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        // every string of chessBoard represent the rows of chess
        vector<string> chessBoard(n, string(n,'.'));
        // so we are filling the board col by col using row pointer , so we need to check there is queen present or not in left and diagonal part.
        unordered_map<int,int> left; // formula : row
        unordered_map<int,int> lowerDiagonal; // formula : row + col
        unordered_map<int,int> upperDiagonal; // formula : row - col
        
        backtracking(chessBoard,ans,left,lowerDiagonal,upperDiagonal,n,0);
        return ans;
    }
};