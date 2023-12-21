class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<int> edge(n, 0);
        for(int i=0; i<roads.size(); ++i){
            edge[roads[i][0]] += 1;
            edge[roads[i][1]] += 1;
        }
        sort(edge.begin(), edge.end());
        for(long long i=n; i>0; --i){
            ans += i * edge[i-1];
        }
        return ans;
    }
};