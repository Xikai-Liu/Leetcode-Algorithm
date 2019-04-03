class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN,f[1111111];f[0]=nums[0];
        for (int i=1;i<nums.size();i++) f[i]=max(f[i-1]+nums[i],nums[i]);
        for (int i=0;i<nums.size();i++) ans=max(ans,f[i]);
        return ans;
    }
};