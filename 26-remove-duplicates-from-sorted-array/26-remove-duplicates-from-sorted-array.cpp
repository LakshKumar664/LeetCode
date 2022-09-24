class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for(int i=0; i < nums.size(); i++){
            if(i < nums.size()-1 && nums[i] >= nums[i+1]){
                int j = i+1;
                while(j < nums.size() && nums[j] <= nums[i])
                    j++;
                if(j < nums.size())
                nums[i+1] = nums[j];
            }
        }
        
        int k = nums.size();

        for(int i=1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                k = i;  break;
            }
        }
        
        return k;
    }
};