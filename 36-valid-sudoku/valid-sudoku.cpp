class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(board[row][col]!='.'){
     char dig=board[row][col];
             

                //horizontal check

                for(int k=0;k<9;k++){
                    if(board[row][k]==dig && k!=col){
                        return false;
                    }
                }


                //vertical check
                for(int k=0;k<9;k++){
                    if(board[k][col]==dig && k!=row){
                        return false;
                    }
                }



                //grid check
                int srow=(row/3)*3;
                int scol=(col/3)*3;
                for(int a=srow;a<srow+3;a++){
                    for(int b=scol;b<scol+3;b++){
                        if( (a!=row || b!=col) && board[a][b]==dig){
                            return false;
                        }
                    }
                }


            }
        }
     }
     return true;
    }
};