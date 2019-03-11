class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ans=0,ma=0;
        if (strs.size()==0) return "";
        for (int i=0;i<strs.size();i++){if (strs[i].size()>ma) ma=strs[i].size();}
        if (strs.size()==1) return  strs[0];
        bool f=true;
        while (f && ans<ma){
            char tmp=strs[0][ans];
            for (int i=1;i<strs.size();i++){
                if (strs[i][ans]!=tmp){f=false;break;}
            }
            if (f==false) break;
            ans=ans+1;
        }
        //return to_string(ans);
        if (ans==0) return "";
        return strs[0].substr(0,ans);
    }
};