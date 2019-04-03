class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],maxx=nums[0],minx=nums[0];
        for (int i=1;i<nums.size();i++){
            int tmp;
            tmp=max(nums[i],max(nums[i]*maxx,nums[i]*minx));
            minx=min(nums[i],min(nums[i]*maxx,nums[i]*minx));
            maxx=tmp;
            if (maxx>ans)ans=maxx;
        }
        return ans;
    }
};