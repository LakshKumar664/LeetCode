class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        bool valid = true;
        
        for(int i=0; i < s.size() && valid; i++){
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(ss.size() == 0){
                    valid = false;
                    break;
                }
                
                if(s[i] == ')' && ss.top() != '('){
                    valid = false;
                }
                else if(s[i] == ']' && ss.top() != '['){
                    valid = false;
                }
                else if(s[i] == '}' && ss.top() != '{'){
                    valid = false;
                }
                ss.pop();                
            }
            else{
                ss.push(s[i]);
            }
        }
        
        if(ss.size()){
            valid = false;
        }
        
        return valid;
    }
};