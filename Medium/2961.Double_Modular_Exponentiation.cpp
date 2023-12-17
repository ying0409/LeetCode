class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for(int i=0; i<variables.size(); ++i){
            int temp1 = 1;
            for(int j=0; j<variables[i][1]; ++j){
                temp1 *= variables[i][0];
                temp1 %= 10;
            }
            int temp2 = 1;
            for(int j=0; j<variables[i][2]; ++j){
                temp2 *= temp1;
                temp2 %= variables[i][3];
            }
            if(temp2==target) ans.push_back(i);
        }
        return ans;
    }
};