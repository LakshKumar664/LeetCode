class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> balls;
        
        /*
            1, 1 ,1,-1,-1,
            1, 1 ,1,-1,-1
           -1,-1,-1 ,1 ,1
            1, 1 ,1 ,1,-1
           -1,-1,-1,-1,-1
        */
        
        for(int i=0; i < grid[0].size(); i++){
            int val = grid[0][i];
            int c = i;
            int r = 0;
            bool go = true;
            
            while(go && r < grid.size() && c < grid[0].size()){
                if(grid[r][c] == 1){
                if(c < grid[0].size()-1 && grid[r][c+1] == -1){
                    go = false;
                }
                if(c == grid[0].size()-1){
                    go = false;
                }
                    
                r++;
                c++;
            }
            else{
                if(c > 0 && grid[r][c-1] == 1){
                    go = false;
                }
                if(c == 0){
                    go = false;
                }
                r++;
                c--;
            }
            if(r == grid.size()){
                break;
            }
            }
            
            if(go){
                balls.push_back(c);
            }
            else{
                balls.push_back(-1);
            }
        }
        
        return balls;
    }
};