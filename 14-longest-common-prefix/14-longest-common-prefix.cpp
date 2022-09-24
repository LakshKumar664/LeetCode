class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        string prefix = "";
        int min_len = strs[0].size();
        
        for(int i=0; i < strs.size(); i++){
            if(strs[i].size() < min_len)
                min_len = strs[i].size();
        }
        
        while(idx < min_len){
            bool is_pre = true;
            
            for(int i=1; i < strs.size(); i++){
                if(strs[i][idx] != strs[0][idx]){
                    is_pre = false;
                    break;
                }
            }
            
            if(!is_pre){
                break;
            }
            prefix += strs[0][idx];
            idx ++;
        }
        
        return prefix;
    }
};