class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        /*
            Two Solutions:
            1) Use Hashtable, count occurence of each num and then if occur > n/2 return that                   element
            2)Sort and then count consecutive same elements, if count > n/2 then return that                    element
            
            /*
                Hashing approach
                unordered_map<int, int> occur;
                int num;
                
                for(int i=0; i < nums.size(); i++){
                    if(occur.count(nums[i])){
                        occur[nums[i]] ++;
                    }
                    else{
                        occur[nums[i]] = 1;
                    }
                    
                    if(occur[nums[i]] > nums.size()/2){
                        num = nums[i];
                    }
                }
                return num;
        */
        
        sort(nums.begin(), nums.end());
        int count = 1;
        int num = nums[0];
        
        for(int i=1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                count ++;
            }
            else{
                count = 1;
            }
            
            if(count > nums.size()/2){
                num = nums[i];
            }
        }
        
        return num;
    }
};