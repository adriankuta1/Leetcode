class Solution {
public:
    
    int result;
    int validSquares;
    int ROWS;
    int COLS;
    int endX;
    int endY;
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        ROWS = grid.size();
        COLS = grid[0].size();
        
        //valid squares tells us the length of path we must have at end for it to be valid
        validSquares = 1;
        result = 0;
        
        int startR;
        int startC;
        
        //go through grid and find start position, end position, and valid positions
        for(int i = 0; i < ROWS; ++i){
            for(int j = 0; j < COLS; ++j){
                
                if(grid[i][j]==0){
                    validSquares++;
                }
                if(grid[i][j] == 1){
                    startR = i;
                    startC = j;
                }
                if(grid[i][j] == 2){
                    endX = i;
                    endY = j;
                }
            }
        }
        
        //call backtracking function from the start position of the grid
        helper(grid,startR,startC,0);   
        return result;
    }
    
    void helper(vector<vector<int>>& grid, int r, int c, int moves){
        
        //return if out of bounds, obstacle, seen already, or at end without seeing all cells
        if(r == ROWS || c == COLS || r < 0 || c < 0 || grid[r][c] == -1 || grid[r][c] == -2 ||
            (grid[r][c] == 2 && moves != validSquares)){
            return;
        }    
        
        //we can terminate early if there is no way to get to the end from our current positon
            //in time
        int movesLeft = validSquares+1 - moves;
        int distToEnd = abs(endX-r) + abs(endY-c);
        
        if(distToEnd > movesLeft){
            return;
        }
        
        //if valid path, increment result and return
        if(moves==validSquares && grid[r][c] == 2){
            result++;
            return;
        }
        
        //label cell as seen
        grid[r][c] = -2;
        
        //call backtrack in the allowed directions
        helper(grid,r+1,c,moves+1);
        helper(grid,r,c+1,moves+1);
        helper(grid,r-1,c,moves+1);
        helper(grid,r,c-1,moves+1);
        
        //once recursions are closed from this position, we un-see it, and return
        grid[r][c] = 0;
        
        return;
        
    }
    
};