class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
        for (int i=0;i<nums.size();i++){if (nums[i]!=val) ans++;}
        int now=nums.size()-1,tmp;
        for (int i=0;i<ans;i++){
            if (nums[i]==val){
                while (nums[now]==val) now--;
                tmp=nums[i];
                nums[i]=nums[now];
                nums[now]=tmp;
            }
        }
        return ans;
    }
};
