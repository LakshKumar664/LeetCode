class Solution {
public:
    bool isDigit(char s){
        return (s >= '0' && s <='9');
    }
    
    
    int convertToInt(string s){
        int num = 0;
        for(int i=0; i < s.size(); i++){
            num = (num * 10) + (s[i] - '0');
        }
        
        return num;
    }
    
    bool isLetter(char s){
        return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z');
    }
    
    string decodeInner(string s, int& i, int kkk){
        string num = "";
        string res="";
        
        while(i < s.size() && s[i] != ']'){
            if(isDigit(s[i])){
                num += s[i];
            }
            else if(s[i] == '[' && num.size() > 0){
                int k = convertToInt(num);
                string inside = "";
                i++;
                while(i < s.size() && s[i] != ']'){
                    int kk = 0;
                    while(i < s.size() && isDigit(s[i])){
                        kk  = (kk * 10) + (s[i]-48);
                        i++;
                    }
                    if(s[i] == '['){
                        i ++;
                        inside += decodeInner(s, i, kk);
                    }
                    else{
                        inside += s[i];
                        i++;
                    }
                }
                
                // decodeInner(inside);
                for(int l=0; l < k; l++){
                    res += inside;
                }
                
                num = "";
            }
            else if(isLetter(s[i])){
                res += s[i];
            }
            i ++;
        }
        string result = "";
        for(int l=0; l < kkk; l++){
            result += res;
        }
        return result;
    }
    string decodeString(string s) {
        int i = 0;
        string num = "";
        string res="";
        
        while(i < s.size()){
            if(isDigit(s[i])){
                num += s[i];
            }
            else if(s[i] == '[' && num.size() > 0){
                int k = convertToInt(num);
                string inside = "";
                i++;
                while(s[i] != ']'){
                    int kk = 0;
                    while(i < s.size() && isDigit(s[i])){
                        kk  = (kk * 10) + (s[i]-48);
                        i++;
                    }
                    if(s[i] == '['){
                        i++;
                        inside += decodeInner(s, i, kk);
                        i++;
                    }
                    else{
                        inside += s[i];
                         i++;
                    }
                }
                
                // decodeInner(inside);
                for(int l=0; l < k; l++){
                    res += inside;
                }
                
                num = "";
            }
            else if(isLetter(s[i])){
                res += s[i];
            }
            i ++;
        }
        
        return res;
    }
};