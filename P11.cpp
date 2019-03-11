class Solution {
public:
    int maxArea(vector<int>& height) {
        int a=0,b=height.size()-1;
        int  ans=0;
        if (height.size()==1) return 0;
        while (a!=b){
            if (height[a]<height[b]){
                if (height[a]*(b-a)>ans) ans=height[a]*(b-a);
                a++;
            }
            else{
                if (height[b]*(b-a)>ans) ans=height[b]*(b-a);
                b--;
            }
        }
        return ans;
    }
};