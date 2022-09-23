class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int above=-1, below=matrix.size();
        int l_idx=-1, right_idx=matrix[0].size();
        
        bool up = false, down=false, left=false, right=true;
        
        vector<int> nums;
        
        int r_idx = 0, c_idx = 0;
        int count = 0;
        
        while(count < matrix.size() * matrix[0].size()){
            
            nums.push_back(matrix[r_idx][c_idx]);
            
            if(left){
                if(c_idx == l_idx+1){
                    left = false;
                    up = true;
                    
                    r_idx --;
                    below --;                    
                }
                else{
                    c_idx --;
                }                
            }
            else if(right){
                if(c_idx == right_idx-1){
                    right = false;
                    down = true;

                    r_idx ++;
                    above ++;
                }
                else{
                    c_idx++;
                }
            }
            else if(down){
                if(r_idx == below-1){
                    down = false;
                    left = true;
                    
                    c_idx --;
                    right_idx --;                    
                }
                else{
                    r_idx ++;
                }
            }
            else if(up){
                if(r_idx == above+1){
                    up = false;
                    right = true;
                    
                    c_idx ++;
                    l_idx ++;                    
                }
                else{
                    r_idx --;
                }                
            }
            
            count ++;
        }
        return nums;
    }
    //1
    //5
    //9
    
};