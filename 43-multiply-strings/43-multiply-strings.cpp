class Solution {
public:
        string multiply(string num1, string num2) {
        int num2_idx = num2.size()-1;
        vector<vector<int> > mul_res;
        vector<int> digit_mul;
        
        while(num2_idx >= 0){
            int digit2 = num2[num2_idx] - '0';
            int num1_idx = num1.size()-1;
            int carry = 0;
            
            while(num1_idx >= 0){
                int pos = num2.size() - 1 - num2_idx + (num1.size()-1-num1_idx);
                int digit1 = num1[num1_idx] - '0';
            
                int res = (digit1 * digit2) + carry;
                
                carry = res / 10;
                res = res % 10;
                if(digit_mul.size() >= pos+1){
                    digit_mul[pos] = (digit_mul[pos] + res);
                }
                else{
                    digit_mul.push_back(res);                
                }

                num1_idx --;
            }
            if(carry){
                digit_mul.push_back(carry);
            }
            num2_idx --;
        }
        
        string result = "";
        int carry = 0;
        int idx = digit_mul.size()-1;
        while(idx >= 0 && digit_mul[idx] == 0){
            idx --;
        }  
            
        for(int i=0; i <= idx; i++){
        	digit_mul[i] += carry;
			carry = 0;
        	if(digit_mul[i] > 9){
				carry = digit_mul[i] / 10;
        		digit_mul[i] = digit_mul[i] % 10;
			}
		}
		
		if(carry){
			digit_mul.push_back(carry);
            idx ++;
		}
		
		for(int i=idx; i >= 0; i--){
			result += digit_mul[i] + '0';
		}
		
        if(result == ""){
            result = "0";
        }    
		return result;
    }

};