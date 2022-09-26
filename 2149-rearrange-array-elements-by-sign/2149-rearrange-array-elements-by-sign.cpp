class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1;
        vector<int> new_arr(nums.size());
        
        for(int i=0; i < nums.size(); i++){
            if(nums[i] < 0){
                new_arr[neg] = nums[i];
                neg += 2;
            }
            else{
                new_arr[pos] = nums[i];
                pos += 2;
            }
        }
        
        return new_arr;
    }
};