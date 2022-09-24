class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //3 2 2 3   
        int k = nums.size();
        for(int i=0; i < nums.size(); i++){
            if(nums[i] == val){
                int j = i;
                while(j < nums.size() && nums[j] == val){
                    j ++;
                }
                int l = j;
                int kk = i;
                bool swap = false;
                while(l < nums.size() && kk < j){
                    nums[kk] = nums[l];
                    nums[l] = val;
                    kk ++;
                    l ++;
                    swap = true;
                }
                // if(i != nums.size()-1 && swap)
                // i --;
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                k = i;
                break;
            }
        }
        
        return k;
    }
};