class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int idx1=0, idx2=0;
        
        while(idx1 < name.size() && idx2 < typed.size()){
            if(name[idx1] == typed[idx2]){
                idx1 ++;
                idx2 ++;
            }
            else{
                if(idx2 == 0){
                    return false;
                }

                if(typed[idx2] != typed[idx2-1]){
                    return false;
                }
                
                idx2 ++;
            }
        }
        
        while(idx2 < typed.size()){
            if(idx2 == 0){
                return false;
            }
            if(typed[idx2] != typed[idx2-1]){
                return false;
            }
            idx2 ++;
        }

        if(idx1 < name.size())
            return false;
        
        return true;
    }
};