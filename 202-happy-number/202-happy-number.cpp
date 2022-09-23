class Solution {
public:
    bool isHappy(int n) {
        long long m = n;
        map<long long, int> visited;
        
        while(visited.count(m) == 0){
            visited[m] = 1;
            m = sq_sum(m);
        }
        
        return m == 1;
    }
    
    long long sq_sum(long long n){
        long long sum = 0;
        for(long long i=n; i > 0; i = i /10){
            sum += (i%10) * (i%10);
        }
        
        return sum;
    }
    
    int len(long long n){
        int count = 0;
        for(long long i=n; i > 0; i=i/10){
            count++;
        }
        return count;
    }
};