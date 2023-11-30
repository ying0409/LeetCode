class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int num = 1;
        int x = 0;
        int y = 0;
        int total = n*n;
        int num_dir = 0;
        while(num<=total){
            ans[x][y] = num;
            if(num==total) break;
            while(!(x+dir[num_dir][0]>=0 && x+dir[num_dir][0]<n && y+dir[num_dir][1]>=0 && y+dir[num_dir][1]<n && ans[x+dir[num_dir][0]][y+dir[num_dir][1]]==0)){
                num_dir = (num_dir+1)%4;
            }
            x += dir[num_dir][0];
            y += dir[num_dir][1];
            num++;
        }
        return ans;
    }
};