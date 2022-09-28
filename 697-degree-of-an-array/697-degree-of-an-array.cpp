class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int max_freq = 0;
        int freq[500000] = {0};
        vector<int> idx(500000, -1);

        for(int i=0; i < nums.size(); i++){
            freq[nums[i]] ++;
            max_freq = max(freq[nums[i]], max_freq);
        }
        
        int freq_[500000] = {0};
        int min_len = nums.size();
        
        for(int i=0; i < nums.size(); i++){
            if(idx[nums[i]] == -1){
                idx[nums[i]] = i;
            }
            freq_[nums[i]] ++;
            
            if(freq_[nums[i]] == max_freq){
                min_len = min(min_len, i+1 - idx[nums[i]]);
            }
        }
        
        return min_len;
    }
};