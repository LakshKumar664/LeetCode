class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        string range = "";
        vector<string> ranges;
        if(!nums.size())
            return ranges;
        range += to_string(nums[0]);
        
        for(int i=1; i < nums.size(); i++){
            long long int num = nums[i];
            num = num - nums[i-1];
            if(num > 1){
                if(to_string(nums[i-1]) != range)
                    range += "->" + to_string(nums[i-1]);
                    
                ranges.push_back(range);
                range = to_string(nums[i]);
            }
        }
        
        if(to_string(nums[nums.size()-1]) != range)
            range += "->" + to_string(nums[nums.size()-1]);
        
        ranges.push_back(range);
        
        return ranges;
    }
};