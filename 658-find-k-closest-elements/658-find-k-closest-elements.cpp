class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx;
        int r = arr.size() - 1;
        int l = 0;
        vector<int> res;
        
        while(l <= r){
            idx = (l+r) / 2;
            
            if(arr[idx] == x){
                break;
            }
            else if(arr[idx] < x){
                l = idx + 1;
            }
            else{
                r = idx - 1;
            }
        }
        int count = 0;
        
        if(arr[idx] > x){
            if(idx == 0){
                l = idx;
                r = idx + 1;
            }
            else{
                l = idx - 1;
                r = idx;
            }
        }
        else if(arr[idx] < x){
            if(idx == arr.size()-1){
                l = idx - 1;
                r = idx;
            }
            else{
                l = idx;
                r = idx + 1;
            }
        }
        else if(arr[idx] == x){
            res.push_back(x);    
            l = idx - 1;
            r = idx + 1;
            count ++;
        }
        
        while(count < k){
            if(l >= 0 && r < arr.size()){
                if(abs(arr[l]-x) <= abs(arr[r]-x)){
                    res.push_back(arr[l]);
                    l -- ;
                }
                else{
                    res.push_back(arr[r]);
                    r ++;
                }
            }
            else if(l >= 0){
                res.push_back(arr[l]);
                l --;
            }
            else{
                res.push_back(arr[r]);
                r ++;
            }
            count ++;
        }
        sort(res.begin(), res.end());
        return res;
        
    }
};