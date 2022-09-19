class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        bool found = false;
        vector<int> res;

        while(l <= r){
            mid = (l+r) / 2;
            
            if(target > nums[mid]){
                l = mid + 1;
            }
            else if(target < nums[mid]){
                r = mid - 1;
            }
            else{
                //1 2 2 4 4 5 6 8 8 8 10
                //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
                //1 1 1 1 1 1 1 1 1 8 8  8  9  9  9  9  9  9  9  9 
                //1 1 1 3 4 6 8 8 8 8         6 8 8 8 8
                found = true;
                break;
            }
        }
        int rr = mid;
        
        while(l < rr && found){
            int k = (l + rr) / 2;
            
            if(nums[k] < target){
                l = k + 1;
            }
            else if(l == k - 1){
                if(nums[l] == target){
                    break;
                }
                
                if(nums[k] == target){
                    l = k;
                }
                break;
            }
            else if(nums[k] == target){
                rr = k;
            }
        }
        int ll = mid;
        while(ll < r && found){
            int k = (ll + r) / 2;
            
            if(nums[k] > target){
                r = k - 1;
            }
            else if(r == k + 1){
                if(nums[r] == target){
                    break;
                }
                
                if(nums[k] == target){
                    r = k;
                }
                break;
            }
            else if(nums[k] == target){
                ll = k;
            }
        }
        
        
        if(found){            
            res.push_back(l);
            res.push_back(r);
        }
        else{        
            res.push_back(-1);
            res.push_back(-1);
        }
        
        return res;        
    }
};