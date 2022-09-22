class Solution {
public:
    struct greaters{
        bool operator()(const pair<string,int>& a,const pair<string,int>& b) const{
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> word_freq;
        vector<string> top_words;
        vector<pair<string, int>> words_freq;
        
        for(int i=0; i < words.size(); i++){
            if(word_freq.count(words[i])){
                word_freq[words[i]] ++;
            }
            else{
                word_freq[words[i]] = 1;
            }
        }
                
        for(auto i:word_freq){
            words_freq.push_back(make_pair(i.first, i.second));
        }
        
        int idx = 0;
        while(words_freq.size() && idx < k){
            make_heap(words_freq.begin(), words_freq.end(), greaters());
            top_words.push_back(words_freq.front().first);
            pop_heap(words_freq.begin(), words_freq.end());
            words_freq.pop_back();

            idx++;
        }
        
        return top_words;
    }
};