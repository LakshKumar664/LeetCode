class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int idx = 0;
        
        while(stones.size() > 1){
            make_heap(stones.begin(), stones.end());
            idx++;
            
            int y = stones.front();
            
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
      
            make_heap(stones.begin(), stones.end());
            int x = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            idx++;
            
            if(x < y){
                stones.push_back(y-x);
                idx --;
            }
        }
        if(stones.size())
        return stones.front();
        
        return 0;
    }
};