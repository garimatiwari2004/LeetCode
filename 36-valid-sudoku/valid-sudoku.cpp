class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> row[9], col[9], box[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num == '.') continue;  // Skip empty cells
                
                int n = num - '0';  // Convert character to integer
                int boxIndex = (i / 3) * 3 + (j / 3); // Compute sub-box index

                // Check if the number is already seen
                if (row[i].count(n) || col[j].count(n) || box[boxIndex].count(n)) {
                    return false;
                }

                // Insert the number into respective row, column, and sub-box
                row[i].insert(n);
                col[j].insert(n);
                box[boxIndex].insert(n);
            }
        }
        return true;
    }
};