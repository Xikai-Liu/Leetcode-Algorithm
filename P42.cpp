class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,maxx=0,pl=0;
        for (int i=0;i<height.size();i++)
            if (height[i]>maxx) maxx=height[i],pl=i;
        int preh=0;
        for (int i=0;i<pl;i++){
            if (height[i]>preh) preh=height[i];
            ans=ans+preh-height[i];
        }
        preh=0;
        for (int i=height.size()-1;i>pl;i--){
            if (height[i]>preh) preh=height[i];
            ans=ans+preh-height[i];
        }
        return ans;
    }
};