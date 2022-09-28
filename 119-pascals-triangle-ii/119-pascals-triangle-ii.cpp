class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1);
        for(int i=1; i <= rowIndex; i++){
            int prev = row[0];
            for(int j=1; j < i; j++){
                if(j < row.size()){
                    int temp = row[j];
                    row[j] = prev + row[j];
                    prev = temp;
                }
            }
            row.push_back(1);
        }
        
        return row;
    }
};