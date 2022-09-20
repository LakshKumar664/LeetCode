class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> letters;
        char letter = 'a';
        
        for(int i='2'; i < '9'; i++, letter=letter+3){
            letters[i].push_back(letter);
            letters[i].push_back(letter+1);
            letters[i].push_back(letter+2);
            if(i == '7'){
                letters[i].push_back(letter+3);
                letter ++;
            }
        }
        
        letters['9'] = {'w', 'x', 'y', 'z'};
        letters['1'] = {};
        vector<string> result;
        // int 

//         for(int i=0; i < digits.size(); i++){
            
//         }
        
        recur(digits, "", result, 0, letters);
        return result;
    }
    
    void recur(string s, string comb, vector<string>& res, int d_idx,              unordered_map<char, vector<char>> letters){
        
        if(d_idx == s.size() - 1){
            for(int i=0; i < letters[s[d_idx]].size(); i++){
                string ss = comb + letters[s[d_idx]][i];
                res.push_back(ss);
            }
            return;
        }
        
        for(int i=0; i < letters[s[d_idx]].size(); i++){
            string ss = comb + letters[s[d_idx]][i];
            recur(s, ss, res, d_idx+1, letters);
        }
        // if(let_idx < letters[s[d_idx]].size() - 1)
        // recur()
    }
};