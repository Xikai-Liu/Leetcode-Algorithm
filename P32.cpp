class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0,tmp=0,last=-1;
        vector<int> Q;
        for (int i=0;i<s.size();i++){
            if (s[i]=='(') Q.push_back(i);
            if (s[i]==')'){
                if (Q.size()<=0) last=i;
                else{
                    Q.pop_back();
                    if (Q.size()==0) tmp=i-last;
                    else tmp=i-Q.back();
                    if (tmp>ans) ans=tmp;
                }
            }
        }
        return ans;
    }
};
