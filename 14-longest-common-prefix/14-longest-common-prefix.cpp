class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sort(strs.begin(), strs.end());
        // int max_len = 0;
        // string prefix = "";
        
//         for(int i=0; i < strs.size()-1; i++){
//             if(strs[i].size() && strs[i+1].size() && strs[i][0] == strs[i+1][0]){
//                 int idx = 0;
//                 string pre = "";
//                 while(idx < strs[i].size() && idx < strs[i+1].size()
//                       && strs[i][idx] == strs[i+1][idx])
//                 {
//                     pre += strs[i][idx];
//                     idx ++;
//                 }
                
//                 if(idx > max_len){
//                     max_len = idx;
//                     prefix = pre;
//                 }
//             }
//         }
        
//         for(int i=0; i < strs[0].size(); i++){
            
//         }
        
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