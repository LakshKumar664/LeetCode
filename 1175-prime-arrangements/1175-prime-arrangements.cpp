class Solution {
public:
    int numPrimeArrangements(int n) {
        int count = 0;
        
        for(int i=1; i <= n; i++){
            bool is_prime = true;
            for(int j=2; j*j <= i && is_prime; j++){
                if(i % j == 0){
                    is_prime = false;
                }
            }
            
            if(is_prime && i > 1){
                count ++;
            }
        }
        
        long long not_primes = n - count;
        
        for(int i=not_primes-1; i > 1; i --){
            not_primes = (not_primes * i)  % 1000000007;
                //((long long)(10e+9) + 7);
        }
        
        for(int i=2; i <= count; i++){
            not_primes = (not_primes * i)  % (1000000007);
        }
        int res = (int) not_primes;
        return res;
        /*
            1 2 3 4 5 6 7 = > 4 * 3  * 2 * 
            3 * 2 * 1 * (2)
        */
    }
};