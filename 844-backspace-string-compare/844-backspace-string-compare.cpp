class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string new_s = "";
        string new_t = "";
        int count = 0;
        
        for(int i=s.size(); i >= 0; i--){
            if(s[i] == '#'){
                count ++;
            }
            else{
                if(count){
                    count --;
                }
                else{
                    new_s += s[i];
                }
            }
        }
        
        count = 0;
        for(int i=t.size(); i >= 0; i--){
            if(t[i] == '#'){
                count ++;
            }
            else{
                if(count){
                    count --;
                }
                else{
                    new_t += t[i];
                }
            }            
        }
        
        return new_s == new_t;
    }
};