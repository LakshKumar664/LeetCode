class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0)
            return false;
        long long signed x = (long long signed) log2(n);
        
        return pow(2, x) == n;
    }
};