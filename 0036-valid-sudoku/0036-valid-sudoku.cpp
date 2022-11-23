class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        map<int,set<int>> rows;                                      // for keep cheking the previous row value
        map<int,set<int>> cols;                                       // for keep cheking the previous col value
        map<pair<int,int>,set<int>> subBox;                 // for keep cheking the previous curr 3x3 matrix value by pair
        
        for(int r=0;r<9;r++)                                              // each row
        {
            for(int c=0;c<9;c++)                                        // each col
            {
                // if it is . skip it
                if(board[r][c]=='.') continue;
                
                // if we found current value previously then return false
                
                // Check row
                if(rows[r].find(board[r][c]-'0') != rows[r].end())
                    return false;
                
                // check col
                if(cols[c].find(board[r][c]-'0') != cols[c].end())
                    return false;
                
                // check sub boxes
				// (r/3,c/3) will tell the curr sub Box as we are taking them from (0,0) to (2,2)
                if(subBox[{r/3,c/3}].find(board[r][c]-'0') != subBox[{r/3,c/3}].end())
                    return false;
                
                
                // if none of then return false then add curr board value to the declared set for next check
                rows[r].insert(board[r][c]-'0');
                cols[c].insert(board[r][c]-'0');
                subBox[{r/3,c/3}].insert(board[r][c]-'0');
            }
        }
        
        return true;
    }
};