class Solution {
public:
    string pushDominoes(string dominoes) {
        string f_state = "";
        vector<int> dp(dominoes.size(), 0);
        vector<int> dp_l(dominoes.size(), 0);
        vector<int> dp_r(dominoes.size(), 0);
        
        for(int j=dominoes.size()-1; j >= 0;j--){
            if(dominoes[j] == 'R'){
                dp_l[j] = -1;
            }
            else if(dominoes[j] == '.'){
                if(j < dominoes.size()-1 && dp_l[j+1] == -1){
                    dp_l[j] = -1;
                }
                else if(j < dominoes.size()-1){
                    dp_l[j] = dp_l[j+1] + 1;
                }
                else{
                    dp_l[j] = -1;
                }
            }
        }
        
        
        
        for(int i=0; i < dominoes.size(); i++){
            if(i > 0 && dominoes[i] == 'L' && dominoes[i-1] == '.'){
                if(i > 1 && dominoes[i-2] == 'R'){
                    //skip
                    f_state += 'L';
                }
                else{
                    f_state[i-1] = 'L';
                    f_state += 'L';
                }
            }
            
            else if(i < dominoes.size()-1 && dominoes[i]=='R' && dominoes[i+1] == '.'){
                if(i < dominoes.size()-2 && dominoes[i+2] == 'L'){
                    //skip
                    f_state += 'R';
                }
                else{
                    // f_state[i+1] = 'R';
                    f_state += "RR";
                    dp[i+1] = 1;
                    i ++;
                }                
            }
            else if(i > 0 && dominoes[i] == '.' && 
                    f_state[i-1] == 'R' && dp[i-1] && (dp_l[i] > dp[i-1]+1 || dp_l[i] == -1)){
                dp[i] = dp[i-1] + 1;
                f_state += 'R';
            }
            else{
                f_state += dominoes[i];
            }
        }
        
        for(int j=dominoes.size()-1; j >= 0; j--){
            if(dp_l[j] > 0 && f_state[j] == '.'){
                if(j > 0 && f_state[j-1] != 'R'){
                    f_state[j] = 'L';
                }
                else if(j > 0 && f_state[j-1] == 'R' && dp[j-1] == dp_l[j]){
                    f_state[j] = 'L';
                }
                else if(j == 0){
                    f_state[j] = 'L';
                }
            }
        }
        
        return f_state;
    }
};