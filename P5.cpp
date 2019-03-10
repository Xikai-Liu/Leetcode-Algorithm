class Solution {
    public:
        void Find(const string& s, int be, int ed, int &ss, int &ee){
            int len=s.size();
            while (be>=0&&ed<len &&s[be]==s[ed]){be--;ed++;}
            be++;ed--;
            if (ed-be>ee-ss){ss=be;ee=ed;}
        }
    string longestPalindrome(string s) {
        int len=s.size();
        if (len==0) return s;
        int ss=0, ee=0;
        for (int i=0;i<len-1;i++){
            Find(s,i,i,ss,ee); Find(s,i,i+1,ss,ee);
        }
        return s.substr(ss,ee-ss+1);
    }
};