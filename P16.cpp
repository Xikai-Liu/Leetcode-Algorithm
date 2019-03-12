class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int min=INT_MAX, sum=0,tmp=0;
        for (int i=0;i<nums.size();i++){
            for (int j=i+1, k=nums.size()-1;j<k;tmp<target?++j:--k){
                tmp=nums[i]+nums[j]+nums[k];
                if (tmp==target) return target;
                if (abs(tmp-target)<min){sum=tmp;min=abs(tmp-target);}
            }
        }
        return sum;
    }
};