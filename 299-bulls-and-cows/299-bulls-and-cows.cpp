class Solution {
public:
    string getHint(string secret, string guess) {
        int occur[70] = {0};
        int num_bulls = 0;
        int num_cows = 0;
        
        for(int i=0; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                num_bulls ++;
            }
            else{
                occur[secret[i]] ++;
            }
        }
        
        for(int i=0; i < guess.size(); i++){
            if(secret[i] != guess[i] && occur[guess[i]]){
                occur[guess[i]] --;
                num_cows ++;
            }
        }
        
        string res = to_string(num_bulls) + "A" + to_string(num_cows) + "B";

        return res;
    }
};