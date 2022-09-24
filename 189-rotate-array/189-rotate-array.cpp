class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
            Time Complexity : O(n)
            Space Complexity : O(n)
        */
        
        int temp = 0;
        int count = 0;
        int idx = 0;
        k = k % nums.size();
        int prev_elem = nums[0];
        
        while(k && count < nums.size()){
            count ++;
            int new_idx = (idx + k) % nums.size();
            temp = nums[new_idx];
            nums[new_idx] = prev_elem;

            long long num = count;
            num = num * k;
            
            if((num % nums.size() == 0 || nums.size() % k == 0) 
                    && idx + k >= nums.size())
            {
                new_idx ++;
                temp = nums[new_idx];
            }

            idx = new_idx;
            prev_elem = temp;
        }
        
        
    }
};