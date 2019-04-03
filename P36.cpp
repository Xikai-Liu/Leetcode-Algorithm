class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++){
            set<char> c;
            for (int j=0;j<9;j++){
                if (board[i][j]=='.') continue;
                if (c.count(board[i][j])>0) return false;
                c.insert(board[i][j]);
            }
        }
        for (int i=0;i<9;i++){
            set<char> c;
            for (int j=0;j<9;j++){
                if (board[j][i]=='.') continue;
                if (c.count(board[j][i])>0) return false;
                c.insert(board[j][i]);
            }
        }
        set<char> san1[100];
        for (int i=0;i<9;i++){ 
            for (int j=0;j<9;j++){
                if (board[i][j]=='.') continue;
                if  (san1[i/3*10+j/3].count(board[i][j])>0) return false; 
                san1[i/3*10+j/3].insert(board[i][j]);
            }
        }
        return true;
    }
};