class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> new_arr(nums.size());
        
        int even_idx = 0, odd_idx = 1;
        
        for(int i=0; i < nums.size(); i++){
            if(nums[i] % 2){
                new_arr[odd_idx] = nums[i];
                odd_idx += 2;
            }
            else{
                new_arr[even_idx] = nums[i];
                even_idx += 2;
            }
        }
        
        return new_arr;
    }
};