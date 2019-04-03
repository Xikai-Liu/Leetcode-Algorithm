class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int f[1111][1111];
        f[0][0]=triangle[0][0];
        for (int i=1;i<triangle.size();i++){
            for (int j=0;j<triangle[i].size();j++){
                //if (j==0 || j==triangle[i].size()-1)
                if (j==0) f[i][j]=f[i-1][j]+triangle[i][j];
                else if (j==triangle[i].size()-1) f[i][j]=f[i-1][j-1]+triangle[i][j];
                else f[i][j]=min(f[i-1][j],f[i-1][j-1])+triangle[i][j];
            }
        }
        int ans=INT_MAX;
        for (int i=0;i<triangle[triangle.size()-1].size();i++) ans=min(ans,f[triangle.size()-1][i]);
        return ans;
    }
};