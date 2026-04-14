// Brute Force Approach : O(n * n) time complexity & O(n) space complexity
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                if (board[row][i] == '.') continue;
                if (seen.count(board[row][i])) return false;
                seen.insert(board[row][i]);
            }
        }

        for (int col = 0; col < 9; col++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                if (board[i][col] == '.') continue;
                if (seen.count(board[i][col])) return false;
                seen.insert(board[i][col]);
            }
        }

        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};

// Optimal Approach : O(n * n) time complexity & O(n * n) space complexity
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rowSet;
        unordered_map<int, unordered_set<char>> colSet;
        map<pair<int,int> , unordered_set<char>> squares;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == '.') continue;

                int val = board[i][j];
                pair<int,int> squareKey = {i / 3 , j / 3};
                if(rowSet[i].count(val) || colSet[j].count(val) || squares[squareKey].count(val)){
                    return false;
                }
                rowSet[i].insert(val);
                colSet[j].insert(val);
                squares[squareKey].insert(val);
            }
        }
        return true;
    }
};
