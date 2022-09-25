class Solution {
public:
    bool isPalindrome(string s) {
        string new_s = "";
        
        for(int i=0; i < s.size(); i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                new_s += s[i];
            if(s[i] >= 'A' && s[i] <= 'Z')
                new_s += (s[i] + 32);
            
        }
        
        for(int i=0, j=new_s.size()-1; i < j; i++, j--){
            if(new_s[i] != new_s[j])
                return false;
        }
        
        return true;
    }
};