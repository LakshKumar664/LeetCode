class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> occur;
        vector<int> maj_nums;
        
        for(int i=0; i < nums.size(); i++){
            if(occur.count(nums[i]) && occur[nums[i]] != -1){
                occur[nums[i]] ++ ;
            }
            else if(occur.count(nums[i]) && occur[nums[i]] == -1){
             //skip   
            }
            else{
                occur[nums[i]] = 1;
            }
            
            if(occur[nums[i]] != -1 && occur[nums[i]] > nums.size()/3){
                maj_nums.push_back(nums[i]);
                occur[nums[i]] = -1;
            }
        }
        
        return maj_nums;
    }
};