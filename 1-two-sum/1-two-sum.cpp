class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //sort(nums.begin(), nums.end());
        vector<int> idx;
        map<long long, vector<int> > sum;
        map<long long, long long> freq;
        
        for(int i=0; i < nums.size(); i++){
            // vector<int> dpp;
            // dpp
            sum[nums[i]].push_back(i);
            if(freq.count(nums[i]) == 0){
                freq[nums[i]] = 1;
            }
            else{
                freq[nums[i]] ++;
            }
        }
        
        for(int i=0; i < nums.size(); i++){
            if(target - nums[i] == nums[i] && sum.count(target-nums[i])){
                if(freq[nums[i]] > 1){
                    long long val = target - nums[i];
                    idx.push_back(sum[target-val][0]);
                    idx.push_back(sum[val][1]);                    
                    break;
                }
            }
            else if(sum.count(target-nums[i])){
                long long val = target - nums[i];
                idx.push_back(sum[target-val][0]);
                idx.push_back(sum[val][0]);
                break;
            }
        }
        
        return idx;
    }
};